/*
http://codeforces.com/problemset/problem/90/B
*/
#include<iostream>

using namespace std;

int main() {
  char a[100][100];
  int r[100][255]={0},c[100][255]={0};
  int n,m;
  cin>>n>>m;
  for (int i=0;i<n;i++)
    for (int j=0;j<m;j++) {
      cin>>a[i][j];
      r[i][a[i][j]]++;
      c[j][a[i][j]]++;
    }
  for (int i=0;i<n;i++)
    for (int j=0;j<m;j++)
      if (r[i][a[i][j]]==1  && c[j][a[i][j]]==1)
        cout<<a[i][j];
  return 0;
}
