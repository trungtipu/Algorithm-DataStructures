//https://www.hackerearth.com/practice/data-structures/trees/binary-search-tree/practice-problems/algorithm/distinct-count/?fbclid=IwAR2Jo9NMwgJVMr4LnuAahrCK2tOFbKYvCKtNe9YHUTlsCIJGCTpF22d92go
#include<iostream>
#include<set>

using namespace std;

int main() {
  set<int> s;
  int t,n,u,x;
  cin>>t;
  while (t--) {
    s.clear();
    cin>>n>>x;
    for (int i=0;i<n;i++) {
      cin>>u;
      s.insert(u);
    }
    if (s.size()==x) cout<<"Good"<<endl;
    else if (s.size()>x) cout<<"Average"<<endl;
    else cout<<"Bad"<<endl;
  }
  return 0;
}
