//http://codeforces.com/problemset/problem/279/B?fbclid=IwAR1n2VTWHw6LOGZyxIjewXH-eYjKTT9MfP90JdwjFC5eUqMhps3ROO9L1k0
/*
Summarize:
give an array have n elements
find the longest sub array that the sum is less than or equal to given value t
Caculate complexity : O(n)

Solution : we have two variable i and j
initally, i=j=0 we have a variable sum to caculate sum of the array from i to j
then we just increase j
each j
if sum+a[j]<= then we just increase sum=sum+a[j]
else if sum+a[j]>t we will update max if (j-i+1)>max
then we increase i and decrease sum with a[i] until we can add a[j] to sum
and keep doing that until j=n
the result is max
*/
#include<iostream>

using namespace std;

int main() {
  int maxn=1e5,sum=0,n,t,a[maxn],max=0;
  cin>>n>>t;
  for (int i=0;i<n;i++) cin>>a[i];
  int i=0,j=0;
  while (j<n) {
    while (sum+a[j]>t) {
        sum-=a[i];
        i++;
      }
    sum+=a[j];
    if (j-i+1>max) max=j-i+1;
    j++;
  }
  cout<<max;
  return 0;
}
