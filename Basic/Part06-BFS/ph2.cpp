/*
https://www.spoj.com/problems/MAKEMAZE/
*/
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int n,m;
char visited[21][21];



void bfs(pair<int,int> s,pair<int,int> t) {
  queue< pair<int,int> > q;
  q.push(s);
  visited[s.first][s.second]='#';
  pair<int,int> tmp;
  int tmpx,tmpy;
  while (!q.empty()) {
    tmp=q.front();
    if (tmp==t) {
      cout<<"valid\n";
      return;
    }
    q.pop();
    for (int i=0;i<4;i++) {
      tmpx=tmp.first+dx[i];
      tmpy=tmp.second+dy[i];
      if (tmpx>=1 && tmpx<=m && tmpy>=1 && tmpy<=n && visited[tmpx][tmpy]=='.') {
        visited[tmpx][tmpy]='#';
        q.push({tmpx,tmpy});
      }
    }
  }
  cout<<"invalid\n";
}

int main() {
  int t;
  cin>>t;
  for (int k=0;k<t;k++) {
    cin>>m>>n;
    vector< pair<int,int> > pos;
    for (int i=1;i<=m;i++)
      for (int j=1;j<=n;j++) {
        cin>>visited[i][j];
        if ((i==1 || j==1 || i==m || j==n) && visited[i][j]=='.')
          pos.push_back({i,j});
      }
    if (pos.size()>2 || pos.size()<2) cout<<"invalid\n";
    else {
      bfs(pos[0],pos[1]);
    }
  }
  return 0;
}
