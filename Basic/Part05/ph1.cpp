/*
http://codeforces.com/problemset/problem/90/B
Summary:
give a grid of lowcase alphabet characters
if one characters has appear more than one time in same row or collum we have to cross it out
then print out the remain charater from top to down left to right
Complexity: O(n^2)
Solution:
we have two matrix r[i][x] means the apperance number of charater x in row i
c[j][x] means the apperance number of charater x in collum j
when we go through the grid we will print out the charater x if r[i][x]=c[j][x]=1

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
