//http://codeforces.com/problemset/problem/691/A
#include<iostream>

using namespace std;

int main() {
  int n,x,count=0;
  cin>>n;
  for (int i=0;i<n;i++) {
    cin>>x;
    if (x==1) count++;
  }
  if ((n>1) && (count==n-1)) cout<<"YES";
  else if ((n==1) && (count==n)) cout<<"YES";
  else cout<<"NO";
  return 0;
}
