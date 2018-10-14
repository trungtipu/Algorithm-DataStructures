/*
http://codeforces.com/contest/451/problem/B

Summary:
Give an array a have n elements
find out can we make this array to increasing order array by reversing one segment of the array
if it's possible print out the segment left,right
else print no

Complexity: O(nlogn)

Solution:
we can imagine that the array we that we want to revese need to be decreasing array
for example 11aaaa11 , 11aaaa, aaaa11
segment contains value 'a' is the array we want to revese to make increasing array
we have a example
1 4 3 2 5
in this example we can make the array become increasing order by reverse segment 2 4
observe we can solve the problem by first we have another array that equal to first array but sorted
1 4 3 2 5 a
1 2 3 4 5 tmp
then we find the first position that a[i]!=tmp[i] from left to right : l
then we find the second position that a[i]!=tmp[i] from right to left : r
then we have
4 3 2 and 2 3 4
then we compare if every element from left to right from a is equal to
every element from right to left from b then the answer is segment l,r
else it's no
*/
#include<iostream>
#include<algorithm>

using namespace std;

int main() {
  int n,maxn=1e5+1;
  int tmp[maxn],a[maxn];
  cin>>n;
  for (int i=1;i<=n;i++) {
    cin>>a[i];
    tmp[i]=a[i];
  }
  sort(a+1,a+1+n);
  int i,l,r;
  i=1; l=1; r=1;
  while ((i<=n) && (a[i]==tmp[i])) i++;
  if (i<=n) l=i;
  i=n;
  while ((i>=1) && (a[i]==tmp[i])) i--;
  if (i>=1) r=i;
  int temp=r;
  for (i=l;i<=r;i++) {
      if (tmp[i]!=a[temp]) {
        cout<<"no";
        return 0;
      }
      temp--;
    }
  cout<<"yes\n";
  cout<<l<<' '<<r;
  return 0;
}
