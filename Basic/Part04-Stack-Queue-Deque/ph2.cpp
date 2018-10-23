/*
https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=3359
*/
#include<iostream>
#include<string>
#include<deque>

using namespace std;

int main() {
  int t=0;
  while (1) {
    int p,c;
    cin>>p>>c;
    if ((p==0) && (c==0)) return 0;
    t++;
    deque<int> q;
    if (p>1000) p=1000;
    for (int i=1;i<=p;i++) q.push_back(i);
    char s;
    int tmp;
    cout<<"Case "<<t<<":\n";
    for (int i=1;i<=c;i++) {
      cin>>s;
      if (s=='N') {
        cout<<q.front()<<endl;
        q.push_back(q.front());
        q.pop_front();
      }
      else {
        cin>>tmp;
        deque<int>::iterator j;
        for (j=q.begin();j!=q.end();j++)
          if (*j==tmp) {
            q.erase(j);
            break;
          }
        q.push_front(tmp);
      }
    }
  }
  return 0;
}
