#include <bits/stdc++.h>
using namespace std;
int t,dp[100001][4],tmp;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    dp[1][1]=1;
    dp[2][1]=1;dp[2][2]=1;
    dp[3][1]=1;dp[3][2]=1;dp[3][3]=1;
    for(int i=4;i<=10000;i++){
        dp[i][1]=1;
        dp[i][2]=dp[i-2][1]+dp[i-2][2];
        dp[i][3]=dp[i-3][1]+dp[i-3][2]+dp[i-3][3];
    }
    while (t--){
        cin>>tmp;
        cout<<dp[tmp][1]+dp[tmp][2]+dp[tmp][3]<<"\n";
    }
}