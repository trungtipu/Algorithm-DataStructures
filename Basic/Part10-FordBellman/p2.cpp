//http://www.lightoj.com/volume_showproblem.php?problem=1074
#include<iostream>
#include<vector>
#include<tuple>
#include<math.h>
using namespace std;

int test;
int n,m;
int inf=1e9;
vector< tuple<int,int,int> > graph;
int dist[300],busy[300];

void bellman_ford(int s) {
  dist[s]=0;
  for (int i=1;i<=n-1;i++)
    for (int j=0;j<graph.size();j++) {
      int u=get<0>(graph[j]);
      int v=get<1>(graph[j]);
      int w=get<2>(graph[j]);
      if (dist[u]!=inf && dist[u]+w<dist[v])
        dist[v]=dist[u]+w;
    }
}

int main() {
  cin>>test;
  int t=1;
  int u,v,w,q;
  while (test--) {
    cin>>n;
    graph.clear();
    for (int i=1;i<=n;i++) {
      cin>>busy[i];
      dist[i]=inf;
    }
    cin>>m;
    for (int i=1;i<=m;i++) {
      cin>>u>>v;
      w=pow(busy[v]-busy[u],3);
      graph.push_back({u,v,w});
    }
    bellman_ford(1);
    cout<<"Case "<<t++<<":"<<endl;
    cin>>q;
    int tmp;
    for (int i=1;i<=q;i++) {
      cin>>tmp;
      if (dist[tmp]<3 || dist[tmp]==inf) cout<<"?"<<endl;
      else cout<<dist[tmp]<<endl;
    }
  }
  return 0;
}
