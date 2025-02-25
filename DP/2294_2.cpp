#include <bits/stdc++.h>
using namespace std;
int n,k,dp[100001],tmp,INF=987654321;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>k;
    fill(dp,dp+100001,INF);
    dp[0]=0;
    for(int i=1;i<=n;i++){
        cin>>tmp;
        for(int j=tmp;j<=k;j++){
            dp[j]=min(dp[j],dp[j-tmp]+1);
        }
    }
    if (dp[k]==INF)
        cout<<-1;
    else
        cout<<dp[k];
}