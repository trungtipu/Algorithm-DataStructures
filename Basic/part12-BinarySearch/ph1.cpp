//https://www.spoj.com/problems/HACKRNDM/
#include<iostream>
#include<algorithm>

using namespace std;

int binary_search(int x,int a[],int left,int right) {
  while (left<=right) {
    int mid = left + (right-left)/2;
    if (a[mid]==x) return mid;
    if (x>a[mid]) left=mid+1;
    else right=mid-1;
  }
  return -1;

}

int main() {
  int n,k;
  int maxn=1e5;
  int a[maxn];
  cin>>n>>k;
  for (int i=0;i<n;i++) cin>>a[i];
  sort(a,a+n);
  int tmp,count=0;
  for (int i=0;i<n;i++) {
    tmp=binary_search(a[i]+k,a,0,n-1);
    if (tmp!=-1) count++;
  }
  cout<<count;
  return 0;
}
