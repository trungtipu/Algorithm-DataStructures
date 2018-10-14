/*
http://codeforces.com/problemset/problem/161/A

Summarize:
give an array a has n elements, an array b has m elements
give x and y
ai is the size of the bulletproof vest that the soldier want
bi is the size of the availabe vest
the soldier can wear a vest that has ai-x<= bi size <=ai+y
find the maximum soldier equipped with bulletproof vest

Complexity: O(max(m,n))

Solution:
we have i=j=1 , we run through a and b array with some conditions
because a and b contain integers in increasing order so,
if a[i]-x<=b[j]<=a[i]+y we add i,j to the result and increase i,j
if b[j]<a[i]-x we need to increase the value of b[j]->increase j
if b[j]>a[i]+y we need to incrase the value of a[i]->increase i
keep doing until i>n or j>m
*/
#include<iostream>

using namespace std;

int main() {
  int n,m,x,y,maxn=1e5+1;
  int a[maxn],b[maxn];
  cin>>n>>m>>x>>y;
  for (int i=1;i<=n;i++) cin>>a[i];
  for (int i=1;i<=m;i++) cin>>b[i];
  int i=1,j=1,res=0;
  int u[maxn],v[maxn];
  while (j<=m && i<=n) {
    if ((a[i]-x<=b[j]) && (b[j]<=a[i]+y)) {
      res++;
      u[res]=i;
      v[res]=j;
      i++; j++;
    }
    else if (b[j]<a[i]-x) j++;
    else if (b[j]>a[i]+y) i++;
  }
  cout<<res<<'\n';
  for (int i=1;i<=res;i++)
    cout<<u[i]<<' '<<v[i]<<'\n';
  return 0;
}
