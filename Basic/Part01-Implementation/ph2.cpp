//http://codeforces.com/problemset/problem/242/B
#include<iostream>

using namespace std;

int main() {
  int n,l,r,max=1e9+1,maxn=1e5;
  int minl=max,maxr=0,a[maxn],b[maxn];
  cin>>n;
  for (int i=0;i<n;i++) {
    cin>>l>>r;
    a[i]=l;
    b[i]=r;
    if (l<minl) minl=l;
    if (r>maxr) maxr=r;
  }
  for (int i=0;i<n;i++)
    if ((minl==a[i]) && (maxr==b[i])) {
      cout<<i+1;
      return 0;
    }
  cout<<-1;
  return 0;
}
