/*
https://www.spoj.com/problems/STPAR/
*/
#include<iostream>
#include<stack>

using namespace std;

int main() {
  while (1) {
    stack<int> s;
    int n,a[1000];
    cin>>n;
    if (n==0) return 0;
    for (int i=0;i<n;i++) cin>>a[i];
    int number=1,i=0;
    while (i<n) {
      if ((!s.empty()) && (number==s.top())) {
        s.pop();
        number++;
      }
      else {
        if (number!=a[i]) s.push(a[i]);
        if (number==a[i]) number++;
        i++;
      }
    }
    while ((!s.empty()) && (s.top()==number)) {
      number++;
      s.pop();
    }
    if (s.empty()) cout<<"yes\n";
    else cout<<"no\n";
  }
}
