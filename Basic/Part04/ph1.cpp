/*
https://www.spoj.com/problems/ONP/
*/
#include<iostream>
#include<queue>
#include<stack>
#include<string>

using namespace std;

int main() {
  int n;
  cin>>n;
  for (int j=0;j<n;j++) {
    string s;
    cin>>s;
    stack<char> sta;
    queue<char> res;
    for (int i=0;i<s.size();i++) {
      if ((s[i]==')') && (!sta.empty())) {
        res.push(sta.top());
        sta.pop();
      }
      else if ((s[i]=='+') || (s[i]=='-') || (s[i]=='*') || (s[i]=='/') || (s[i]=='^')) {
        sta.push(s[i]);
      }
      else if ((s[i]>='a') && (s[i]<='z')) {
        res.push(s[i]);
      }
    }
    while (!res.empty()) {
      cout<<res.front();
      res.pop();
    }
    cout<<endl;
  }
  return 0;
}
