//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1415
#include<iostream>
#include<algorithm>
using namespace std;

//first number = x
int binary_search(int x,int a[],int left,int right) {
  while (left<=right) {
    int mid=left+(right-left)/2;
    if ( (mid==0 || a[mid-1]<x) && a[mid]==x) return mid;
    if (x>a[mid]) left=mid+1;
    else right=mid-1;
  }
  return -1;
}

int main() {
  int n,q,x,test=1;
  int a[10001];
  while (1) {
    cin>>n>>q;
    if (n==0 && q==0) break;
    for (int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    cout<<"CASE# "<<test++<<":"<<endl;
    for (int i=0;i<q;i++) {
      cin>>x;
      int tmp=binary_search(x,a,0,n-1);
      if (tmp!=-1)
        cout<<x<<" found at "<<tmp+1<<endl;
      else
        cout<<x<<" not found"<<endl;
    }
  }
  return 0;
}
