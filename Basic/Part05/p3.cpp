/*
http://codeforces.com/problemset/problem/61/B?fbclid=IwAR3sRIaH34c8DdTfJaSRiqpJpQwRfNnw7vWyTiajnWQ8YWt_SNXFDLd8obo

*/
#include<iostream>
#include<string>
using namespace std;

string a[7];

void solve(string &x) {
  int i=0;
  while (i<x.size()) {
    if ((x[i]=='-') || (x[i]=='_') || (x[i]==';')) {
      x.erase(i,1);
      i--;
    }
    else if ((x[i]>='A') && (x[i]<='Z'))
      x[i]+=32;
    i++;
  }
}

string res(string &x) {
  if ((x==a[1]) || (x==a[2]) || (x==a[3])
    || (x==a[4]) || (x==a[5]) || (x==a[6]))
      return "ACC";
  return "WA";
}

int main() {
  string s[4];
  for (int i=1;i<=3;i++) {
    getline(cin,s[i]);
    solve(s[i]);
  }
  a[1]=s[1]+s[2]+s[3];
  a[2]=s[1]+s[3]+s[2];
  a[3]=s[2]+s[1]+s[3];
  a[4]=s[2]+s[3]+s[1];
  a[5]=s[3]+s[1]+s[2];
  a[6]=s[3]+s[2]+s[1];
  int n;
  cin>>n;
  cin.ignore();
  string a;
  for (int i=1;i<=n;i++) {
    getline(cin,a);
    solve(a);
    cout<<res(a)<<'\n';
  }
  return 0;
}
