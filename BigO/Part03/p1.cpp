/*
http://codeforces.com/problemset/problem/169/A?fbclid=IwAR0bxRNAqfefrk5zse6OqqsBApITUrSz8He8dlHy7lMHVFQnBOTPdkaNrzs

Summary:
Give n work with hi complexity for each work
the older will do exactly a work with complexity >x
the younger will do exactly b work with complexity <x
find how many ways we can choose the value of the x that satisfy the condition

Complexity: O(nlogn)

Solution:
we sort h array in increasing order then
we have
  h[n-a+1] mean the minimum number among a biggest numbers in h array
  h[b] mean the maximum number among b smallest numbers in h array
if h[n-a+1] - h[b] > 0 then that is the result
because x will have the value from h[b] to h[n-a+1]-1
else h[n-a+1] just equalt to h[b] so there're no x value that can satisfy the problem condition
*/
#include<iostream>
#include<algorithm>

using namespace std;

int main() {
  int n,a,b,maxn=2e5+1;
  int h[maxn];
  cin>>n>>a>>b;
  for (int i=1;i<=n;i++) cin>>h[i];
  sort(h+1,h+1+n);
  if (h[n-a+1]-h[b]>0) cout<<h[n-a+1]-h[b];
  else cout<<0;
  return 0;
}
