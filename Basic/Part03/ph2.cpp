/*
http://codeforces.com/problemset/problem/439/B

Summary:
Give an array c have n value ci mean the number of chater of book i
a guy study 1 chapter with x hours
but if the guy finish a book the next book he study he will learn in (x-1) hours
x always larger than or equal to 1
find out the minimum hours that the boy will study all the books

Complexity: O(nlogn)

Solution:
we sort c array in increasing order
then we use greedy approach , we let the guy study book with small chapter first
from left to right because after one book the hour need to study the next book will decrease 1 value
*/
#include<iostream>
#include<algorithm>

using namespace std;

int main() {
  long long n,maxn=1e5,c[maxn],x;
  long long res=0;
  cin>>n>>x;
  for (int i=0;i<n;i++) cin>>c[i];
  sort(c,c+n);
  for (int i=0;i<n;i++) {
    res+=x*c[i];
    if (x>1) x--;
  }
  cout<<res;
  return 0;
}
