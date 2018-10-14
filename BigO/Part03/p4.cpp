/*
http://codeforces.com/contest/551/problem/A

Summary:
give an array a has n element a[i] is the rating of student i in the contest
rank them

Complexity: O(nlogn)

Solution:
sort a array in increasing order
from the highest rating downto the other we have the function
count=1 ( we use this to count the number of same value)
rank[i]=rank[i+1] if rating[i]=rating[i+1] then we increase count
rank[i]=rank[i+1]+count if rating[i]!=rating[i+1] then we reset count=1 
*/
#include<iostream>
#include<algorithm>

using namespace std;

int main() {
  int n;
  int rank[2001],a[2001],tmp[2001];
  cin>>n;
  for (int i=1;i<=n;i++) {
    cin>>a[i];
    tmp[i]=a[i];
  }
  sort(a+1,a+1+n);
  int count=1;
  rank[a[n]]=1;
  for (int i=n-1;i>=1;i--) {
    if (a[i]==a[i+1]) {
      rank[a[i]]=rank[a[i+1]];
      count++;
    }
    else {
      rank[a[i]]=rank[a[i+1]]+count;
      count=1;
    }
  }
  for (int i=1;i<=n;i++) cout<<rank[tmp[i]]<<' ';
  return 0;
}
