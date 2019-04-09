//https://www.spoj.com/problems/EKO/
#include<iostream>
using namespace std;

int main() {
  long long n,m;
  int maxn=1e6+1;
  long long a[maxn];
  cin>>n>>m;
  int max=0;
  for (int i=0;i<n;i++) {
    cin>>a[i];
    if (a[i]>max)
      max = a[i];
  }
  long long left=1,right=max;
  long long res=0;
  while (left<=right) {
    long long mid = left+(right-left)/2;
    long long count=0;
    for (int i=0;i<n;i++)
     if (a[i]-mid>0)
      count+=(a[i]-mid);
    if (count==m) {
      res=mid;
      break;
    }
    if (count<m) right=mid-1;
    else {
      left=mid+1;
      if (mid>res) res=mid;
    }
  }
  cout<<res;
  return 0;
}
