#include <iostream>
#include <vector>
using namespace std;
int n,k,tmp,ret,dp[100001];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>k;
    dp[0]=1;
    for(int i=0;i<n;i++){
        cin>>tmp;
        for(int j=tmp;j<=k;j++){
            dp[j]+=dp[j-tmp];
        }
    }
    cout<<dp[k];
}