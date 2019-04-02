//http://www.spoj.com/problems/ALLIZWEL/
#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;

int dx[]={0,0,-1,1,-1,1,-1,1};
int dy[]={1,-1,0,0,-1,1,1,-1};
int t,n,m;
char a[100][100];
bool visited[100][100];
string st="ALLIZZWELL";
bool check;

bool in_map(int x,int y) {
  return (x>=0 && x<n && y>=0 && y<=m);
}

void dfs(pair<int,int> s,int count) {
  if (count==10) {
    check=true;
    return;
  }
  visited[s.first][s.second]=true;
  for (int i=0;i<8;i++) {
    int x=s.first+dx[i];
    int y=s.second+dy[i];
    if (in_map(x,y) && !check && !visited[x][y] && a[x][y]==st[count])
      dfs({x,y},count+1);
  }
  visited[s.first][s.second]=false;
}

int main() {
  cin>>t;
  while (t--) {
    cin>>n>>m;
    vector< pair<int,int> > pos;
    for (int i=0;i<n;i++)
      for (int j=0;j<m;j++) {
        cin>>a[i][j];
        if (a[i][j]=='A') pos.push_back({i,j});
      }
    check=false;
    for (int i=0;i<pos.size();i++) {
      for (int ii=0;ii<n;ii++)
        for (int jj=0;jj<m;jj++) visited[ii][jj]=false;
      dfs(pos[i],1);
      if (check) {
        cout<<"YES"<<endl;
        break;
      }
    }
    if (!check) cout<<"NO"<<endl;
  }
  return 0;
}
