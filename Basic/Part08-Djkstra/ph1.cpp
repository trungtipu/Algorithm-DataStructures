//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1927
#include<iostream>
#include<vector>
#include<queue>
#include<functional>

using namespace std;

vector< pair<int,int> > graph[20000];
int dist[20000];

void djkstra(int s) {
  dist[s]=0;
  priority_queue< pair<int,int>, vector< pair<int,int> >, greater< pair<int,int> > > pq;
  pq.push({0,s});
  pair<int,int> tmp;
  while (!pq.empty()) {
    tmp=pq.top();
    pq.pop();
    int u=tmp.second;
    for (int i=0;i<graph[u].size();i++) {
      int w=graph[u][i].second;
      int v=graph[u][i].first;
      if (dist[u]+w<dist[v]) {
        dist[v]=dist[u]+w;
        pq.push({dist[v],v});
      }
    }
  }
}

int main() {
  int t,count=1;
  cin>>t;
  while (t--) {
    int n,m,s,d,u,v,w;
    int inf=1e9;

    cin>>n>>m>>s>>d;
    for (int i=0;i<20000;i++) {
      dist[i]=inf;
      graph[i].clear();
    }
    for (int i=0;i<m;i++) {
      cin>>u>>v>>w;
      graph[u].push_back({v,w});
      graph[v].push_back({u,w});
    }

    djkstra(s);
    cout<<"Case #"<<count++<<": ";
    if (dist[d]!=inf) cout<<dist[d]<<endl;
    else cout<<"unreachable"<<endl;
  }
  return 0;
}
