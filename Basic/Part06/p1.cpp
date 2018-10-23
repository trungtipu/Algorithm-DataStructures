/*
https://www.hackerrank.com/challenges/bfsshortreach/problem
Implement BFS algorithm
*/
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int dist[1001],n,m;
bool visited[1001];
queue<int> q;

void bfs(int s,vector<int> graph[]) {
  for (int i=1;i<=n;i++) {
    visited[i]=false;
    dist[i]=-1;
  }
  dist[s]=0;
  visited[s]=true;
  q.push(s);
  while (!q.empty()) {
    s=q.front(); q.pop();
    for (int i=0;i<graph[s].size();i++)
      if (!visited[graph[s][i]]) {
        dist[graph[s][i]]=dist[s]+6;
        visited[graph[s][i]]=true;
        q.push(graph[s][i]);
      }
  }
}

int main() {
  int q,s,u,v;
  cin>>q;
  for (int k=1;k<=q;k++) {
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
      if (i!=s) cout<<dist[i]<<' ';
    cout<<'\n';
  }
  return 0;
}
