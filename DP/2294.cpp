/*
이 코드가 100^10000 이란 걸 알 수 있어야 함. O(n^k)
*/
#include <bits/stdc++.h>
using namespace std;
int n,k,INF=987654321, dp[100001],tmp;
vector<int>v;
int getMinCoin(int here){
    if (here<0)
        return INF;
    int& ret = dp[here];
    if (ret!=INF)
        return ret;
    for(auto there:v){
        ret=min(ret, getMinCoin(here-there) + 1);
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>k;
    fill(dp,dp+100001,INF);
    for(int i=1;i<=n;i++){
        cin>>tmp;
        v.push_back(tmp);
        dp[tmp]=1;
    }
    getMinCoin(k);
    if (dp[k]==INF)
        cout<<-1;
    else
        cout<<dp[k];
    return 0;
}