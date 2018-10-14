//http://codeforces.com/problemset/problem/572/A
#include<iostream>

using namespace std;

int main() {
  int na,nb,maxn=1e5+1,k,m;
  int a[maxn],b[maxn];
  cin>>na>>nb;
  cin>>k>>m;
  for (int i=1;i<=na;i++) cin>>a[i];
  for (int i=1;i<=nb;i++) cin>>b[i];
  if (a[k]<b[nb-m+1]) cout<<"YES";
  else cout<<"NO";
  return 0;
}
