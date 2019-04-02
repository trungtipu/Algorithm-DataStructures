//https://www.spoj.com/problems/SHPATH/en/
#include<iostream>
#include<queue>
#include<vector>
#include<functional>
#include<string>
using namespace std;
#define max 10001
vector<pair<int,int>> graph[max];
int dist[max];
string st[max];
int n;

int check(string tmp) {
  int i=1;
  for (i=1;i<=n;i++)
      if (st[i]==tmp) break;
  return i;
}

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
  int N;
  cin>>N;
  while (N--) {
    cin>>n;
    int p,v,w;
    for (int u=1;u<=n;u++) {
      cin>>st[u];
      cin>>p;
      for (int j=1;j<=p;j++) {
        cin>>v>>w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
      }
    }
    int r;
    cin>>r;
    int inf=1e9;
    string name1,name2;
    int s,t;
    for (int i=1;i<=r;i++) {
      cin>>name1>>name2;
      s=check(name1); t=check(name2);
      for (int j=1;j<=n;j++) dist[j]=inf;
      dijikstra(s,graph,dist);
      cout<<dist[t]<<endl;
    }
    for (int i=1;i<=n;i++) graph[i].clear();
  }
  return 0;
}
