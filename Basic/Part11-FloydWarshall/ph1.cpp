//https://www.spoj.com/problems/SOCIALNE/
#include<iostream>
#include<string>
using namespace std;

int possible[200][200];
bool is_friend[200][200];
int n;

void floyd_warshall() {
  for (int i=0;i<n;i++)
    for (int j=0;j<n;j++)
      possible[i][j]=0;

  for (int k=0;k<n;k++)
    for (int i=0;i<n;i++)
      for (int j=0;j<n;j++)
        if (is_friend[i][k] && is_friend[k][j] && !is_friend[i][j]
        && i!=j)
          possible[i][j]=1;
}

int main() {
  int test;
  string st;
  cin>>test;
  cin.ignore();
  while (test--) {
    int i=0;
    getline(cin,st);
    n=st.size();
    for (int j=0;j<n;j++) {
      if (st[j]=='N') is_friend[i][j]=false;
      else is_friend[i][j]=true;
    }
    ///////
    for (i=1;i<n;i++) {
      getline(cin,st);
      for (int j=0;j<n;j++) {
        if (st[j]=='N') is_friend[i][j]=false;
        else is_friend[i][j]=true;
      }
    }
    floyd_warshall();
    int sum,res=-1,pos;
    for (i=0;i<n;i++) {
      sum=0;
      for (int j=0;j<n;j++)
        sum+=possible[i][j];
      if (sum>res) {
        res=sum;
        pos=i;
      }
    }
    cout<<pos<<' '<<res<<endl;
  }
  return 0;
}
