#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n,m,u,v;
queue<int> q;
int dis[1001];

void bfs(int s,vector<int> graph[]) {
  bool visited[1001];
  for (int i=1;i<=n;i++) {
    visited[i]=false;
    dis[i]=-1;
  }
  dis[s]=0;
  visited[s]=true;
  q.push(s);
  while (!q.empty()) {
    s=q.front(); q.pop();
    for (int i=0;i<graph[s].size();i++)
      if (!visited[graph[s][i]]) {
          dis[graph[s][i]]=dis[s]+6;
          visited[graph[s][i]]=true;
          q.push(graph[s][i]);
        }
    }
}

int main() {
  int test,s;
  cin>>test;
  for (int k=1;k<=test;k++) {
    vector<int> graph[1001];
    cin>>n>>m;
    for (int i=1;i<=m;i++) {
      cin>>u>>v;
      graph[u].push_back(v);
      graph[v].push_back(u);
    }
    cin>>s;
    bfs(s,graph);
    for (int i=1;i<=n;i++)
      if (i!=s) cout<<dis[i]<<' ';
    cout<<endl;
  }
  return 0;
}
