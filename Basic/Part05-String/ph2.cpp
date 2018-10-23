/*
http://codeforces.com/problemset/problem/499/B
Summary:
We have m word ai, bi
ai from language 1
bi from language 2
all the words are distinct
then we have n words from the proffesor's speech in language 1
the student know 2 language so he will take note the word in the language
which length of the word is shorter if the length are equal ìn 2 language
he will choose language 1
Complexity: O(n^2)
Solution:
Implement just like the Summary

*/
#include<iostream>
#include<string>

using namespace std;

int main() {
  int n,m;
  string a[3000],b[3000],x;
  cin>>n>>m;
  for (int i=0;i<m;i++)  cin>>a[i]>>b[i];
  for (int i=0;i<n;i++) {
    cin>>x;
    for (int j=0;j<m;j++)
      if (a[j]==x && a[j].size()>b[j].size()) {
        x=b[j];
        break;
      }
    cout<<x<<' ';
  }
  return 0;
}
