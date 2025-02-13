#include <bits/stdc++.h>
using namespace std;
int n,w,dp[1004][1004],ret,t1,t2;
pair<int,int>p[1004];
int check(pair<int,int>& here ,pair<int,int>& there){
    return (abs(there.first-here.first) + abs(there.second-here.second));
}
int getSum(int a,int b){
    if (a==w+1 || b==w+1)
        return 0;
    if (dp[a][b])
        return dp[a][b];
    int next=max(a,b)+1;
    dp[a][b]=min(getSum(a,next) + check(p[b],p[next]), getSum(next,b) + check(p[a], p[next]));
    return dp[a][b];
}
void trace(){
    int a=0;
    int b=1;
    for(int i=2;i!=w+2;i++){
        if (dp[i][b] + check(p[a],p[i]) < dp[a][i] + check(p[i],p[b])){
            cout<<"1\n";
            a=i;
        }else{
            cout<<"2\n";
            b=i;
        }
    }
}
int main(){
    cin>>n>>w;
    p[0]={1,1};
    p[1]={n,n};
    for(int i=2;i<w+2;i++){
        cin>>t1>>t2;
        p[i]={t1,t2};
    }
    cout<<getSum(0,1)<<"\n";
    trace();
}