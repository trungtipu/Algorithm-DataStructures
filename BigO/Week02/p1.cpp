//http://codeforces.com/problemset/problem/387/B?fbclid=IwAR1_6Vndn0DzjU8dWTExTnADSVF8Ke2WhHbzP1pRp0PFlV3R9c-UZ3cXfWE
/*
Summarize:
give m problems each problem has bj complexity
give n problems each problem has ai complexity
find the minimum number of problem have to prepare of fix
in m problems to make any aj value are in b array

Caculate complexity : O(m)

Solution : use two pointer technique
we run through b array and a array with some conditions
if ai<=bj then we have one problem that satisfy ai complexity
so we increase i, repeat the work until j=m
the result when i>=n is 0 because if i>=n mean the last value a[n-1] is satisfy
else the result is (n-1)-i+1 = n-i
*/
#include<iostream>

using namespace std;

int main() {
  int n,m,a[3000],b[3000];
  cin>>n>>m;
  for (int i=0;i<n;i++) cin>>a[i];
  for (int i=0;i<m;i++) cin>>b[i];
  int i=0,j=0;
  while (j<m) {
    if (a[i]<=b[j]) i++;
    j++;
  }
  if (i>=n) cout<<0;
  else cout<<n-i;
  return 0;
}
