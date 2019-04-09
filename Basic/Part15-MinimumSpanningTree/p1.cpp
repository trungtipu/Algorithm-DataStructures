//https://www.spoj.com/problems/MST/
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector< pair<int,int> > graph[20000];
int dist[20000],path[20000];
bool done[20000];

long long prim(int s,int n,vector< pair<int,int> > graph[]) {
  int inf=1e9;
  for (int i=1;i<=n;i++) {
    dist[i]=inf;
    path[i]=-1;
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
      if (w<dist[v] && !done[v]) {
        dist[v]=w;
        pq.push({dist[v],v});
        path[v]=u;
      }
    }
  }
  /////
  long long res=0;
  for (int i=1;i<=n;i++)
      res+=dist[i];
  return res;
}

int main() {
  int n,m,u,v,w;
  cin>>n>>m;
  for (int i=1;i<=m;i++) {
    cin>>u>>v>>w;
    graph[u].push_back({v,w});
    graph[v].push_back({u,w});
  }
  cout<<prim(1,n,graph);
  return 0;
}
