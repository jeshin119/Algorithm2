/*
12:16~
*/
#include <iostream>
#include <stdlib.h>
using namespace std;
int n,m,a[51][51],v[51][51],d[51][51];
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
string s;
int dfs(int y,int x){
    if (y<0 || x<0 || y>n-1 || x>m-1 || a[y][x]=='H')
        return 0;
    if (v[y][x]){
        cout<<-1;
        exit(0);
    }
    int& r=d[y][x];
    if (r)
        return r;
    v[y][x]=1;
    for(int i=0;i<4;i++){
        int ny=y+dy[i]*a[y][x];
        int nx=x+dx[i]*a[y][x];
        r=max(r,dfs(ny,nx)+1);
    }
    v[y][x]=0;
    return r;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>s;
        for(int j=0;j<m;j++){
            s[j]!='H' ? a[i][j]=s[j]-'0' : a[i][j]=s[j];
        }
    }
    cout<<dfs(0,0);
    return 0;
}