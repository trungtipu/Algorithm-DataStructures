/*
http://codeforces.com/problemset/problem/731/A?fbclid=IwAR0lqk_Exj-UfxhgrS8HGR7eHIxQJbsDntW96ayX-AERB_pWQLJDzppCnyQ

*/
#include<iostream>
#include<string>
#include<math.h>

using namespace std;

int main() {
  string s;
  cin>>s;
  char now='a';
  int res=0;
  for (int i=0;i<s.size();i++) {
    res+=min(abs(s[i]-now),26-abs(s[i]-now));
    now=s[i];
  }
  cout<<res;
  return 0;
}
