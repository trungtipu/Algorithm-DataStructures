/*
http://codeforces.com/problemset/problem/224/B

Summarize:
Give an array a have n elements and a number k
find a minimal sub array from i to j that have exactly k distinct number
if there are many of that kind of sub array just print one pair i j
if a sub array that we need to find doesn't exist print -1 -1

Complexity: O(n)

Solution:
to caculate the number of distinct value in a sequence i j we have check array
check[i] mean the value of a[i] has appeared in the sequence we're working on
we generate an array f , the value of f[i] means the number of distinct value from 1 to i
then we find the first position in f array that have a same a value equal to k
after that run backward from that position until we have k distinct values
that the sequence we need to find
on the other hand, if we coundn't find any value in f array that equals to k
we can conclude that the sequence doesn't exist
*/
#include<iostream>

using namespace std;

int main() {
  int n,k,maxn=1e5+1,a[maxn],count=0,f[maxn];
  bool check[maxn];
  for (int i=1;i<=maxn;i++) check[i]=false;
  cin>>n>>k;
  cin>>a[1];
  check[a[1]]=true;
  f[1]=1;
  for (int i=2;i<=n;i++) {
    cin>>a[i];
    if ((check[a[i]]==false) && (a[i]!=a[i-1])) {
      f[i]=f[i-1]+1;
      check[a[i]]=true;
    }
    else f[i]=f[i-1];
  }
  for (int i=1;i<=maxn;i++) check[i]=false;
  for (int j=1;j<=n;j++) {
    if (f[j]==k) {
      check[a[j]]=true;
      int i=j;
      while (f[j]>1) {
        i--;
        if ((check[a[i]]==false) && (a[i]!=a[i+1])) {
          f[j]--;
          check[a[i]]=true;
        }
      }
      cout<<i<<' '<<j;
      return 0;
    }
  }
  cout<<-1<<' '<<-1;
  return 0;
}
