//boj 2579계단오르기
#include <bits/stdc++.h>
using namespace std;
int n,f[304],dp[304][2];
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>f[i];
    }
    dp[0][0]=f[0];
    dp[0][1]=0;
    dp[1][0]=f[1];
    dp[1][1]=f[0]+f[1];
    for(int i=2;i<n;i++){
        dp[i][0] = max(dp[i-2][0], dp[i-2][1]) + f[i];
        dp[i][1] = dp[i-1][0] + f[i];
    }
    cout<<max(dp[n-1][0],dp[n-1][1]);
}