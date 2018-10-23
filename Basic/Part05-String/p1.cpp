/*
http://codeforces.com/problemset/problem/518/A?fbclid=IwAR1pBr_iiY8tCRJPQwPQ7sw4Fky2P35t-gNbMwujivuZtzmf85_g-kq9LdA

Summary:
Give 2 strings s,t find string x in codition s<x<t
Complexity: O(n)
Solution:
from the end of s string go through each character of s string then make that character equal
next character in alphabet then check if s<x<t else keep doing it until go through all the character
of s string
*/

#include<iostream>
#include<string>

using namespace std;

int main() {
  string s,t;
  cin>>s>>t;
  string x=s;
  for (int i=x.size()-1;i>=0;i++) {
    if (x[i]=='z') x[i]='a';
    else x[i]++;
    if ((x>s) && (x<t)) {
      cout<<x;
      return 0;
    }
  }
  cout<<"No such string";
  return 0;
}
