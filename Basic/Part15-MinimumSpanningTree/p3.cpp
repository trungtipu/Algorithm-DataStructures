#include<iostream>
#include<queue>
#include<map>
#include<string>
#include<vector>
using namespace std;

int dist[2000];
bool done[2000];

int prim(int s,int n,vector< pair<int,int> > graph[]) {
  int inf=1e9;
  for (int i=1;i<=n;i++) {
    dist[i]=inf;
    done[i]=false;
  }
  priority_queue< pair<int,int>, vector< pair<int,int> >, greater< pair<int,int> > > pq;
  dist[s]=0;
  pq.push({0,s});
  pair<int,int> tmp;
  while (!pq.empty()) {
    tmp=pq.top();
    pq.pop();
    int u=tmp.second;
    done[u]=true;
    for (int i=0;i<graph[u].size();i++) {
      int v=graph[u][i].first;
      int w=graph[u][i].second;
      if (!done[v] && w<dist[v]) {
        dist[v]=w;
        pq.push({dist[v],v});
      }
    }
  }
  ////
  int ans=0;
  for (int i=1;i<=n;i++) {
  if (!done[i]) return -1;
    ans+=dist[i];
  }
  return ans;
}

int main() {
  int t,test=1,w,m,n;
  string u,v;
  int tmpu,tmpv;
  vector< pair<int,int> > graph[2000];
  cin>>t;
  while (t--) {
    cin>>m;
    map<string,int> ma;
    map<string,int>::iterator it;
    n=0;
    for (int i=1;i<=m;i++) {
      cin>>u>>v>>w;
      //////u
      it=ma.find(u);
      if (it==ma.end()) {
        n++;
        tmpu=n;
        ma.insert({u,n});
      }
      else tmpu=it->second;
      /////v
      it=ma.find(v);
      if (it==ma.end()) {
        n++;
        tmpv=n;
        ma.insert({v,n});
      }
      else tmpv=it->second;
      /////
      graph[tmpu].push_back({tmpv,w});
      graph[tmpv].push_back({tmpu,w});
      /////
    }
    cout<<"Case "<<test++<<": ";
    int res=prim(1,n,graph);
    if (res!=-1) cout<<res<<endl;
    else cout<<"Impossible"<<endl;
    ma.clear();
    for (int i=1;i<=n;i++) graph[i].clear();
  }
  return 0;
}
