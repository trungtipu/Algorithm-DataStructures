//http://lightoj.com/volume_showproblem.php?problem=1002
#include<iostream>
#include<vector>
#include<queue>
#include<functional>

using namespace std;
const int inf=1e9;
vector< pair<int,int> > graph[500];
int dist[500];

void djkstra(int s) {
  dist[s]=0;
  priority_queue< pair<int,int> , vector< pair<int,int> > , greater< pair<int,int> > > pq;
  pq.push({0,s});
  pair<int,int> tmp;
  while (!pq.empty()) {
    tmp=pq.top();
    pq.pop();
    int u=tmp.second;
    for (int i=0;i<graph[u].size();i++) {
      int v=graph[u][i].first;
      int w=graph[u][i].second;
      if (dist[u]>w) {
        if (dist[u]<dist[v]) {
          dist[v]=dist[u];
          pq.push({dist[v],v});
        }
      }
      else {
        if (w<dist[v]) {
          dist[v]=w;
          pq.push({dist[v],v});
        }
      }
    }
  }
}

int main() {
  int t,test=1;
  cin>>t;
  while (t--) {
    int n,m,u,v,w,s;
    cin>>n>>m;
    for (int i=0;i<500;i++) {
      dist[i]=inf;
      graph[i].clear();
    }
    for (int i=0;i<m;i++) {
      cin>>u>>v>>w;
      graph[u].push_back({v,w});
      graph[v].push_back({u,w});
    }
    cin>>s;
    djkstra(s);
    cout<<"Case "<<test++<<":"<<endl;
    for (int i=0;i<n;i++) {
        if (dist[i]!=inf) cout<<dist[i]<<endl;
        else cout<<"Impossible"<<endl;
      }
  }
  return 0;
}
