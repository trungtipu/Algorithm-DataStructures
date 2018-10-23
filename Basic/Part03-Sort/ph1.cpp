/*
http://codeforces.com/problemset/problem/334/B

Summary:
we have an array
x1<x2<x3, y1<y2<y3
the base array have 8 elements contains all the point (xi,yj) (1<=i,j<=3) except (x2,y2)
give 8 points find if 8 points are equal to the base array

Complexity: 0(8^2)

Solution:
sort and find distinct value in x and y
generate all the points from distince value in x and y
check the first array equal to a array just generated
check to find result
*/
#include<iostream>
#include<algorithm>

using namespace std;

int main() {
  int x[8],y[8],tmpx[8],tmpy[8];
  for (int i=0;i<8;i++) {
    cin>>x[i]>>y[i];
    tmpx[i]=x[i];
    tmpy[i]=y[i];
  }

  //sort and find distinct value in x and y
  sort(x,x+8);
  sort(y,y+8);
  int resx[8],resy[8];
  int countx=0,county=0;
  resx[0]=x[0]; resy[0]=y[0];
  for (int i=1;i<8;i++) {
    if ((countx<3) && (x[i]!=x[i-1])) {
      countx++;
      resx[countx]=x[i];
    }
    if ((county<3) && (y[i]!=y[i-1])) {
      county++;
      resy[county]=y[i];
    }
  }

  //generate all the points from distince value in x and y
  int count=-1,xx[8],yy[8];
  for (int i=0;i<3;i++)
    for (int j=0;j<3;j++) {
      if ((i==1) && (i==j)) continue;
      count++;
      xx[count]=resx[i];
      yy[count]=resy[j];
    }

  //check the first array equal to a array just generated
  for (int i=0;i<8;i++)
    for (int j=0;j<8;j++) {
      if ((tmpx[i]==xx[j]) && (tmpy[i]==yy[j])) {
        xx[j]=-1;
        yy[j]=-1;
        break;
      }
    }

  //check to find result
  int i;
  for (i=0;i<8;i++)
    if ((xx[i]!=-1) || (yy[i]!=-1)) break;
  if (i==8) cout<<"respectable";
  else cout<<"ugly";
  return 0;
}
