/*
https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1876&fbclid=IwAR1gp-JkdCuS0fM8QEPS7bKvfjx8aDEWPSnXl2Ili8tQVKlvW41Ae_XCbgY
*/
#include<iostream>
#include<queue>

using namespace std;

int main() {
  while (1) {
    int n;
    cin>>n;
    if (n==0) return 0;
    queue<int> q;
    for (int i=1;i<=n;i++)
      q.push(i);
    cout<<"Discarded cards:";
    while (q.size()>=2) {
      cout<<' '<<q.front();
      q.pop();
      q.push(q.front());
      q.pop();
      if (q.size()>=2) cout<<',';
    }
    cout<<'\n';
    cout<<"Remaining card: "<<q.front()<<'\n';
  }
}
