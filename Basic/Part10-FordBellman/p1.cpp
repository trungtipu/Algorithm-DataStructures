//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=499&fbclid=IwAR0laOE1jjSuesoFcYw37YhvSJujtofwkbdZ_6UrbfpJI-kHuJjHlCo705g
#include<iostream>
#include<vector>
#include<tuple>
using namespace std;

int test;
int n,m,u,v,w;
int inf=1e9;
int dist[1000];
vector< tuple<int,int,int> > graph;

bool bellman_ford(int s) {
  dist[s]=0;
  for (int i=1;i<=n;i++)
    for (int j=0;j<graph.size();j++) {
      int u=get<0>(graph[j]);
      int v=get<1>(graph[j]);
      int w=get<2>(graph[j]);
      if (dist[u]!=inf && dist[u]+w<dist[v]) {
        if (i==n) return true;
        dist[v]=dist[u]+w;
      }
    }
  return false;
}

int main() {

  cin>>test;
  while (test--) {
    cin>>n>>m;
    graph.clear();
    for (int i=0;i<n;i++) dist[i]=inf;
    for (int i=0;i<m;i++) {
      cin>>u>>v>>w;
      graph.push_back({u,v,w});
    }
    if (bellman_ford(0)) cout<<"possible"<<endl;
    else cout<<"not possible"<<endl;
  }
  return 0;
}
