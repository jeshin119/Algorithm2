#include <bits/stdc++.h>
using namespace std;
int t,w,a[1004],dp[1004][2][34];
int go(int _time,int _where,int _cnt){
    if (_cnt<0)
        return -1e9;
    if (_time==t)
        return 0;
    int& ret=dp[_time][_where][_cnt];
    if (ret!=-1)
        return (ret);
    return ret = max(go(_time + 1, _where^1, _cnt - 1), go(_time + 1, _where, _cnt)) + (_where == a[_time] - 1); 
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>t>>w;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<t;i++){
        cin>>a[i];
    }
    cout<<max(go(0,1,w-1),go(0,0,w))<<"\n";
}