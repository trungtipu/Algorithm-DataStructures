/*
https://www.codechef.com/problems/DIGJUMP
*/
#include<iostream>
#include<vector>
#include<queue>
#include<string>

using namespace std;

string st;

void bfs(int s,vector<int> digit[]) {
  int n=st.size(),tmp;
  queue<int> q;
  int dist[n];
  bool visited[n];
  for (int i=0;i<n;i++) {
    visited[i]=false;
    dist[i]=-1;
  }
  dist[s]=0;
  visited[s]=true;
  q.push(s);
  while (!q.empty()) {
    s=q.front();
    q.pop();
    tmp=st[s]-'0';
    for (int i=0;i<digit[tmp].size();i++)
      if (!visited[digit[tmp][i]]) {
        dist[digit[tmp][i]]=dist[s]+1;
        visited[digit[tmp][i]]=true;
        q.push(digit[tmp][i]);
      }
    digit[tmp].clear();
    if (s+1<n && visited[s+1]==false) {
      dist[s+1]=dist[s]+1;
      visited[s+1]=true;
      q.push(s+1);
    }
    if (s-1>=0 && visited[s-1]==false) {
      dist[s-1]=dist[s]+1;
      visited[s-1]=true;
      q.push(s-1);
    }
    if (visited[n-1]) break;
  }
  cout<<dist[n-1];
}

int main() {
  cin>>st;
  vector<int> digit[10];
  for (int i=0;i<st.size();i++)
    digit[st[i]-'0'].push_back(i);
  bfs(0,digit);
  return 0;
}
