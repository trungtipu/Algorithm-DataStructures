//https://www.spoj.com/problems/TRVCOST/
#include<iostream>
#include<vector>
#include<queue>
#include<functional>

using namespace std;

vector< pair<int,int> > graph[1000];
int dist[1000];

void djkstra(int s) {
  dist[s]=0;
  priority_queue< pair<int,int>, vector< pair<int,int> >,greater< pair<int,int> > >  pq;
  pair<int,int> tmp;
  pq.push({0,s});
  while (!pq.empty()) {
    tmp = pq.top();
    pq.pop();
    int u=tmp.second;
    for (int i=0;i<graph[u].size();i++) {
      int v=graph[u][i].first;
      int w=graph[u][i].second;
      if (dist[u]+w<dist[v]) {
        dist[v]=dist[u]+w;
        pq.push({dist[v],v});
      }
    }
  }
}

int main() {
  int n,u,v,w,q;
  cin>>n;
  for (int i=0;i<n;i++) {
    cin>>u>>v>>w;
    graph[u].push_back({v,w});
    graph[v].push_back({u,w});
  }
  cin>>u;
  int inf=1e9;
  for (int i=0;i<1000;i++) dist[i]=inf;
  djkstra(u);
  cin>>q;
  for (int i=0;i<q;i++) {
    cin>>v;
    if (dist[v]==inf) cout<<"NO PATH"<<endl;
    else cout<<dist[v]<<endl;
  }
  return 0;
}
