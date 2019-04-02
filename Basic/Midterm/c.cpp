//https://codeforces.com/problemset/problem/37/A
#include<iostream>

using namespace std;

int main() {
  int x,check[1001];
  for (int i=0;i<=1000;i++) check[i]=0;
  int n;
  cin>>n;
  for (int i=0;i<n;i++) {
    cin>>x;
    check[x]++;
  }
  int max=1;
  for (int i=0;i<=1000;i++)
    if (check[i]>0) {
      if (check[i]>max)
       max=check[i];
      n=n-(check[i]-1);
    }
  cout<<max<<' '<<n;
  return 0;
}
