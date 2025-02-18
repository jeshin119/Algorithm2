#include <bits/stdc++.h>
using namespace std;
int n,w[17][17],visited,INF=1e9,d[17][1<<17];
int go(int here, int visited){
    if (visited==(1<<n)-1){
        return w[here][0] ? w[here][0] : INF;
    }
    int& ret=d[here][visited];
    if (~ret)
        return (ret);
    ret=INF;
    for(int i=0;i<n;i++){
        if (visited&(1<<i))
            continue;
        if (w[here][i]==0)
            continue;
        ret = min(ret, go(i,visited|(1<<i)) + w[here][i]);
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cin>>w[i][j];
    }
    memset(d, -1, sizeof(d));
    cout<<go(0,1);
}