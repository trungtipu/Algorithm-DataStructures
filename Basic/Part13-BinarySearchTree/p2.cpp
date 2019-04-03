//https://www.hackerearth.com/practice/data-structures/trees/binary-search-tree/practice-problems/algorithm/monk-and-his-friends/description/?fbclid=IwAR15wzJTYG_FGnf-yEtngy-KzOGrGDAJQMSakfxrGiDY-jaKVJzHt1Dg58M
#include<iostream>
#include<unordered_set>

using namespace std;

int main() {
  long long t,n,m,tmp;
  cin>>t;
  unordered_set<long long> s;
  while (t--) {
    s.clear();
    cin>>n>>m;
    for (int i=0;i<n;i++) {
      cin>>tmp;
      s.insert(tmp);
    }
    for (int i=0;i<m;i++) {
      cin>>tmp;
      if (s.count(tmp))
         cout<<"YES"<<endl;
      else {
        cout<<"NO"<<endl;
        s.insert(tmp);
      }
    }
  }
  return 0;
}
