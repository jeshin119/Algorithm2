//boj 11724 연결요소의 개수.
#include <bits/stdc++.h>
using namespace std;
int n,m,a[1004][1004],u,v,ret,visited[1004][1004];
int dfs(int start,int end){
    visited[start][end]=1;
    for(int i=0;i<n;i++){
        if (visited[end][i])
            continue;
        if (a[end][i])
            dfs(end,i);
    }
}
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        a[u][v]=1;
        a[v][u]=1;
    }
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if (a[i][j])
                ret+=dfs(i,j);
        }
    }
    cout<<ret<<"\n";
}