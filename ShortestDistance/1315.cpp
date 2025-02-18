#include <bits/stdc++.h>
using namespace std;
typedef struct d{
    int x;
    int y;
    int z;
}_data;
int n,visited[54],dp[1004][1004];
_data a[54];
int go(_data here){
    int& ret=dp[here.x][here.y];
    if (ret!=-1)
        return ret;
    ret=0;
    vector<int>v;
    for(int i=1;i<=n;i++){
        if (here.x >= a[i].x || here.y >= a[i].y){
            ret++;
            if (!visited[i]){
                visited[i]=1;
                here.z += a[i].z;
                v.push_back(i);
            }
        }
    }
    for(int p=0;p<=here.z;p++){
        int nextx=min(1000,here.x+p);
        int nexty=min(1000,here.y+here.z-p);
        ret=max(ret, go({nextx,nexty,0}));
    }
    for(auto t:v){
        visited[t]=0;
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i].x>>a[i].y>>a[i].z;
    memset(dp,-1,sizeof(dp));
    cout<<go({1,1,0})<<"\n";
}