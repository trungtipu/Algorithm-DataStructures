/*
http://codeforces.com/problemset/problem/518/A?fbclid=IwAR1pBr_iiY8tCRJPQwPQ7sw4Fky2P35t-gNbMwujivuZtzmf85_g-kq9LdA

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
