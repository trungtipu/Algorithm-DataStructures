/*
https://www.spoj.com/problems/CAM5/fbclid=IwAR04QkMGh9bxybUntnWhKH4_Tpj4lbd3fyPxgAy76Cm5bIDaCrIDDBp7kok
*/
#include<iostream>
#include<vector>
#define maxn 100000
using namespace std;

int n,m;
vector<int> graph[maxn];
bool visited[maxn];

void dfs(int s) {
  if (visited[s]) return;
  visited[s]=true;
  for (int i=0;i<graph[s].size();i++)
    dfs(graph[s][i]);
}
int main() {
  int test,u,v;
  cin>>test;
  for (int k=0;k<test;k++) {
    for (int i=0;i<n;i++) {
      graph[i].clear();
      visited[i]=false;
    }
    cin>>n>>m;
    for (int i=0;i<m;i++) {
      cin>>u>>v;
      graph[u].push_back(v);
      graph[v].push_back(u);
    }
    int res=0;
    for (int i=0;i<n;i++)
      if (!visited[i]) {
        res++;
        dfs(i);
      }
    cout<<res<<'\n';
  }
  return 0;
}
