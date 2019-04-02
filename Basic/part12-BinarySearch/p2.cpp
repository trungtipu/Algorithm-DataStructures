//https://www.spoj.com/problems/OPCPIZZA/
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
  int t,price,n;
  int maxn=1e5;
  bool check[maxn];
  int a[maxn];
  cin>>t;
  while (t--) {
    cin>>n>>price;
    for (int i=0;i<n;i++) {
      cin>>a[i];
      check[i]=false;
    }
    sort(a,a+n);
    int count=0;
    for (int i=0;i<n;i++)
      if (!check[i]) {
      check[i]=true;
      int tmp=binary_search(price-a[i],a,0,n-1);
      if (tmp!=-1) {
        count++;
        check[tmp]=true;
      }
      if (tmp==i) count--;
    }
    cout<<count<<endl;
  }
  return 0;
}
