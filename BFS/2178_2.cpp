#include <bits/stdc++.h>
using namespace std;
int n,m,a[104][104],visited[104][104],ret;
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
queue<pair<int,int>>q;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    string s;
    for(int i=0;i<n;i++){
        cin>>s;
        for(int k=0;k!=s.size();k++){
            a[i][k]=s[k]-'0';
        }
    }
    q.push({0,0});
    visited[0][0]=1;
    while (q.size()){
        int y=q.front().first;
        int x=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int ny=y+dy[i];
            int nx=x+dx[i];
            if (ny<0 ||nx<0 ||ny>=n || nx>=m)
                continue;
            if (visited[ny][nx])
                continue;
            if (a[ny][nx] == 0)
                continue;
            visited[ny][nx]=1+visited[y][x];
            q.push({ny,nx});
        }
    }
    cout<<visited[n-1][m-1];
}