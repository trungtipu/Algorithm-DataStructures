/*
http://codeforces.com/problemset/problem/499/B
*/
#include<iostream>
#include<string>

using namespace std;

int main() {
  int n,m;
  string a[3000],b[3000],x;
  cin>>n>>m;
  for (int i=0;i<m;i++)  cin>>a[i]>>b[i];
  for (int i=0;i<n;i++) {
    cin>>x;
    for (int j=0;j<m;j++)
      if (a[j]==x && a[j].size()>b[j].size()) {
        x=b[j];
        break;
      }
    cout<<x<<' ';
  }
  return 0;
}
