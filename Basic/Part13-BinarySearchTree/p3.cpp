//https://www.hackerrank.com/contests/womens-codesprint-2/challenges/minimum-loss?fbclid=IwAR1LcQ_RiWlPEn6amvqDW88ktzj4IzyAwgTJLgW13HFMNR3SlxMrlHx-nRU
#include<iostream>
#include<set>

using namespace std;

int main() {
  long long n,x;
  set<long long> s;
  set<long long>::iterator k;
  cin>>n;
  cin>>x;
  s.insert(x);
  long long min =1e16;
  for (int i=1;i<n;i++) {
    cin>>x;
    k=s.upper_bound(x);
    if (k!=s.end()) {
      if (*k-x<min) min=*k-x;
    }
    s.insert(x);
  }
  cout<<min;
  return 0;
}
