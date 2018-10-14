//http://codeforces.com/problemset/problem/676/A
#include<iostream>
#include<algorithm>

using namespace std;

int main() {
  int n,x,i,posmin,posmax;
  cin>>n;
  for (i=1;i<=n;i++) {
    cin>>x;
    if (x==1) posmin=i;
    if (x==n) posmax=i;
  }
  cout<<max(abs(posmax-posmin),max(max(n-posmin,n-posmax),max(posmin-1,posmax-1)));
  return 0;
}
