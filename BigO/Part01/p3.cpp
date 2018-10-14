//http://codeforces.com/problemset/problem/673/A
#include<iostream>

using namespace std;

int main() {
  int n,t[92];
  cin>>n;
  t[0]=0;
  t[n+1]=91;
  for (int i=1;i<=n+1;i++) cin>>t[i];
  for (int i=1;i<=n+1;i++)
    if (t[i]-t[i-1]>15) {
      cout<<t[i-1]+15;
      return 0;
    }
  cout<<90;
  return 0;
}
