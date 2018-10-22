/*
http://codeforces.com/problemset/problem/731/A?fbclid=IwAR0lqk_Exj-UfxhgrS8HGR7eHIxQJbsDntW96ayX-AERB_pWQLJDzppCnyQ

Summary:
give an alphabet in circle like a wheel , then give a string
find out the minimum move to type the string by using the wheel
the wheel pointer is at a in the beginning
Complexity: O(n)
Solution:
because we have 26 character in the alphabet so if at the pointer of charater i we plus or minus 26
we will be at the same position
so the minimum distance from on charater to another charater on the wheel is
min(abs(next-now),26-(next-now))

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
