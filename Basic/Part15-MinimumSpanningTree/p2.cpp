//https://www.spoj.com/problems/CSTREET/fbclid=IwAR3RoWz4LfzV8NYz650sb1nHMm3006y0JtDSKjYYkH_RUPnj_V3iwydwFDA
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int dist[2000];
bool done[2000];



int prim(int s,int n,vector< pair<int,int> > graph[]) {
  int inf=1e9;
  for (int i=1;i<=n;i++) {
    dist[i]=inf;
    done[i]=false;
  }
  priority_queue< pair<int,int>, vector< pair<int,int> >,greater< pair<int,int> > > pq;
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
  /////
  int ans=0;
  for (int i=1;i<=n;i++) ans+=dist[i];
  return ans;
}

int main() {
  int test;
  int n,m,p,u,v,w;
  vector< pair<int,int> > graph[2000];
  cin>>test;
  while (test--) {
    cin>>p;
    cin>>n;
    cin>>m;
    for (int i=1;i<=m;i++) {
      cin>>u>>v>>w;
      graph[u].push_back({v,w});
      graph[v].push_back({u,w});
    }
    cout<<p*prim(1,n,graph)<<endl;
    for (int i=1;i<n;i++) graph[i].clear();
  }
  return 0;
}
