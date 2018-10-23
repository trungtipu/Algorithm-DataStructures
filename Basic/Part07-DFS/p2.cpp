/*
http://lightoj.com/volume_showproblem.php?problem=1012&fbclid=IwAR0Xd9dm_JHv3C04OHE6lfqQe0dbokM3mxifa01hEdDg2KZDlRREj7Itpc4
*/
#include<iostream>
#include<vector>

using namespace std;

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
char a[20][20];
int n,m,res;

void dfs(pair<int,int> s) {
  a[s.first][s.second]='#';
  for (int i=0;i<4;i++) {
    int tmpx=s.first+dx[i];
    int tmpy=s.second+dy[i];
    if (tmpx>=0 && tmpx<n && tmpy>=0 && tmpy<m && a[tmpx][tmpy]=='.') {
       res++;
       dfs({tmpx,tmpy});
    }
  }
}

int main() {
  int test;
  cin>>test;
  pair<int,int> s;
  for (int k=1;k<=test;k++) {
    cin>>m>>n;
    for (int i=0;i<n;i++)
      for (int j=0;j<m;j++) {
        cin>>a[i][j];
        if (a[i][j]=='@') {
          s.first=i;
          s.second=j;
        }
      }
    res=1;
    dfs(s);
    cout<<"Case "<<k<<": "<<res<<'\n';
  }
  return 0;
}
