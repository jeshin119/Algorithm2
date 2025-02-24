#include <iostream>
using namespace std;
int n,dp[1000001];
void trace(int here){
    if (here==0)
        return ;
    cout<<here<<" ";
    if (here%3==0 && dp[here] == dp[here/3] + 1)
        trace(here/3);
    else if (here%2==0 && dp[here] == dp[here/2] + 1)
        trace(here/2);
    else if (here > 1 && dp[here] == dp[here-1] + 1)
        trace(here-1);
    return ;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    fill(dp,dp+1000001,987654321);
    dp[1]=0;
    for(int i=2;i<=n;i++){
        if (i%3==0)
            dp[i]=min(dp[i/3] + 1, dp[i]);
        if (i%2==0)
            dp[i]=min(dp[i/2] + 1, dp[i]);
        dp[i]=min(dp[i-1] + 1, dp[i]);
    }
    cout<<dp[n]<<"\n";
    trace(n);
}