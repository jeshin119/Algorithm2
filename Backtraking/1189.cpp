#include <bits/stdc++.h>
using namespace std;
int r,c,k,visited[6][6];
int dy[4]={1,0,-1,0};
int dx[4]={0,-1,0,1};
char a[6][6];
int start(int y,int x){
    if (y==1 && x==c){
        return visited[y][x]==k ? 1: 0;
    }
    int ret=0;
    for(int i=0;i<4;i++){
        int ny=y+dy[i];
        int nx=x+dx[i];
        if (ny<1 || nx<1|| ny>r || nx>c)
            continue;
        if (visited[ny][nx] || a[ny][nx]=='T')
            continue;
        visited[ny][nx]=visited[y][x]+1;
        ret+=start(ny,nx);
        visited[ny][nx]=0;
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>r>>c>>k;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            cin>>a[i][j];
        }
    }
    visited[r][1]=1;
    cout<<start(r,1);
}