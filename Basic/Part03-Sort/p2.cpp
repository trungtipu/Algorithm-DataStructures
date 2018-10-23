/*
http://codeforces.com/problemset/problem/149/A?fbclid=IwAR2vS3AKgUMmA1HUhRTZ9DN9rcpbqDJVZSMyYLbq07Rt8Ujq4MvzhHolPdQ

Summary:
we have k centimeters
we have a array of 12 elements mean ai is the height a flower will be grown if it is watered in i month
find the minimum month to water the flower in order to make the flower grown just larger than or equal to k centimeters
otherwise if don't have the result print -1

Complexity: O(12log12)

Solution:
we will sort a array then we will water from the month that make the flower grow most downto
the other months if sum of the centimers that the flower has grown just >= k we will print the result
otherwise, if through a year the the sum still < k we will print -1

*/
#include<iostream>
#include<algorithm>

using namespace std;

int main() {
  int k,i,a[13],sum=0;
  cin>>k;
  for (i=1;i<=12;i++) cin>>a[i];
  sort(a+1,a+1+12);
  for (i=12;i>=1;i--) {
    if (sum>=k) break;
    sum+=a[i];
  }
  if (sum<k) cout<<-1;
  else cout<<12-i;
  return 0;
}
