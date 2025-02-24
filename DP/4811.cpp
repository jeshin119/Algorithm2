#include <iostream>
using namespace std;
typedef long long ll;
ll n,dp[31][31];
ll getString(int whole, int half){
    if (whole == 0 && half == 0)
        return 1;
    if (dp[whole][half])
        return dp[whole][half];
    if (whole>0)
        dp[whole][half] += getString(whole-1,half+1);
    if (half>0)
        dp[whole][half] += getString(whole,half-1);
    return dp[whole][half];
}
int main(){
    while (true){
        cin>>n;
        if (!n)
            return 0;
        cout<<getString(n,0)<<"\n";
    }
}