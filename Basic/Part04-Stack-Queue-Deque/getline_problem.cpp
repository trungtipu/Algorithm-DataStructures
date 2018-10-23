#include<iostream>
#include<string>
//when use getline remember has cin.ignore() before them
using namespace std;

int main() {
  string s;
  int n;
  cin>>n;
  cout<<n<<endl;
  cin.ignore();
  getline(cin,s);
  cout<<s<<endl;
  cin>>n;
  cout<<n<<endl;
  return 0;
}
