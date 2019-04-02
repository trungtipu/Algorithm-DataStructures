//https://www.spoj.com/problems/MICEMAZE/
#include<iostream>
#include<vector>
#include<queue>
#include<functional>
using namespace std;

#define max 101
int check[max][max];
vector<pair<int,int>> graph[max];
int dist[max];

void dijikstra(int source,vector<pair<int,int>> graph[],int dist[]) {
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
  dist[source]=0;
  pq.push({0,source});
  while (!pq.empty()) {
    int a=pq.top().second;
    int d=pq.top().first;
    pq.pop();
    for (int i=0;i<graph[a].size();i++) {
      pair<int,int> b=graph[a][i];
      if (d+b.second<dist[b.first]) {
        dist[b.first]=d+b.second;
        pq.push({dist[b.first],b.first});
      }
    }
  }
}

int main() {
  int n,e,t,m;
  cin>>n>>e>>t>>m;
  int a,b,w;
  int inf=1e9;
  for (int i=0;i<m;i++) {
    cin>>a>>b>>w;
    graph[a].push_back({b,w});
  }
  int res=1;
  for (int k=1;k<=n;k++)
    if (k!=e) {
      for (int i=1;i<=n;i++) {
        dist[i]=inf;
      }
      dijikstra(k,graph,dist);
      if (dist[e]<=t) res++;
  }
  cout<<res;
  return 0;
}
