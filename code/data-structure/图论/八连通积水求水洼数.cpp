/*
n*m 园子,下雨后有积水，八连通积水被认为是连在一起,求出一共有多少水洼
八连通指的是相对于下图w的*部分

***
*w*
***
10 12
w........ww.
.www.....www
....ww...ww.
.........ww.
.........w..
..w......w..
.w.w.....ww.
w.w.w.....w.
.w.w......w.
..w.......w.
*/
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
int n,m;
char field[100][100];
void dfs(int x,int y)
{
    field[x][y] = '.';
    for(int dx=-1; dx<=1; dx++)
        for(int dy = -1; dy<=1; dy++)
        {
            int nx = x+dx,ny = y+dy;
            if(0<=nx&&nx<n&&0<=ny&&ny<m && field[nx][ny]=='w')
                dfs(nx,ny);
        }
    return ;
}
void solve()
{
    int res = 0;
    for(int i=0; i<n; i++)
    {
        for(int j = 0; i<m; j++)
        {
            if(field[i][j]=='w')
            {
                dfs(i,j);
                res++;
            }
        }
    }
    cout<<res<<endl;
}
int main()
{
    cin>>n;
    cin>>m;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            scanf("%c",&field[i][j]);
    solve();
    return 0;
}
