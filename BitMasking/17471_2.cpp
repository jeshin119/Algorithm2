#include <bits/stdc++.h>
using namespace std;
int n,m,a[11],visited[11],cmp[11],tmp,ret=1e9;
vector<int>adj[11];
pair<int,int>dfs(int here,int val){
    visited[here]=1;
    pair<int,int> r={1,a[here]};
    for(auto there: adj[here]){
        if (cmp[there]!=val)
            continue;
        if (visited[there])
            continue;
        pair<int,int>_tmp=dfs(there,val);
        r.first+=_tmp.first;
        r.second+=_tmp.second;
    }
    return r;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>m;
        for(int j=1;j<=m;j++){
            cin>>tmp;
            adj[i].push_back(tmp);
            adj[tmp].push_back(i);
        }
    }
    for(int i=1;i<(1<<n)-1;i++){
        memset(visited,0,sizeof(visited));
        memset(cmp,0,sizeof(cmp));
        int idx1;
        int idx2;
        for(int j=0;j<n;j++){
            if (i&(1<<j)){
                idx1=j+1;
            }else{
                cmp[j+1]=1;
                idx2=j+1;
            }
        }
        pair<int,int>go1=dfs(idx1,0);
        pair<int,int>go2=dfs(idx2,1);
        if (go1.first + go2.first == n){
            ret = min(ret, abs(go1.second-go2.second));
        }
    }
    if (ret==1e9)
        cout<<-1<<"\n";
    else
        cout<<ret<<"\n";
}