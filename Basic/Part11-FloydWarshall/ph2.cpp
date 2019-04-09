//http://lightoj.com/volume_showproblem.php?problem=1174
#include<iostream>
#include<math.h>
using namespace std;

int graph[200][200],dist[200][200];
int n,m;
void floyd_warshall() {
  int inf=1e9;
  for (int i=0;i<n;i++)
    for (int j=0;j<n;j++) {
      if (i==j) dist[i][j]=0;
      else if (graph[i][j]==1) dist[i][j]=graph[i][j];
      else dist[i][j]=inf;
    }

  for (int k=0;k<n;k++)
    for (int i=0;i<n;i++)
      for (int j=0;j<n;j++)
        if (dist[i][k]!=inf && dist[k][j]!=inf
        && dist[i][k]+dist[k][j]<dist[i][j]) {
          dist[i][j]=dist[i][k]+dist[k][j];
        }
}

int main() {
  int t,test=1,u,v,s,d;
  cin>>t;
  while (t--) {
    cin>>n>>m;
    m;
    for (int i=0;i<n;i++)
      for (int j=0;j<n;j++) graph[i][j]=0;
    for (int i=0;i<m;i++) {
      cin>>u>>v;
      graph[u][v]=1;
      graph[v][u]=1;
    }
    floyd_warshall();
    cout<<"Case "<<test++<<": ";
    cin>>s>>d;

    int res=dist[s][0]+dist[0][d];
    for (int i=1;i<n;i++)
      res=max(res,dist[s][i]+dist[i][d]);
    cout<<res<<endl;
  }
  return 0;
}
