//http://acm.timus.ru/problem.aspx?space=1&num=1837&fbclid=IwAR0yMQ_S4qh_hT05RlM-kHSo3cC1jhMHj0ekXmbC06s3gHw63UxLx3wSD8Y
#include<iostream>
#include<map>

int main() {
  int n;
  string x,y,z;
  map<string,int> m;
  vector<int> graph[100];
  cin>>n;
  int p=1;
  for (int int i=0;i<n;i++) {
    cin>>x>>y>>z;
    if (!m[x]) m[x]=p++;
    if (!m[y]) m[y]=p++;
    if (!m[z]) m[z]=p++;
    graph[m[x]].push_back(m[y]);
    graph[m[x]].push_back(m[z]);
    graph[m[y]].push_back(m[x]);
    graph[m[y]].push_back(m[z]);
    graph[m[z]].push_back(m[y]);
    graph[m[z]].push_back(m[x]);
  }
  bfs(grap)
  return 0;
}
