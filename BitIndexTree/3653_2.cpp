#include <bits/stdc++.h>
using namespace std;
int t,n,m,tr[200004];
map<int,int>mp;
void update(int i, int val){
    while (i<200004){
        tr[i]+=val;
        i+=(i&-i);
    }
}
void cal(int i){
    long long ret=0;
    while (i>0){
        ret+=tr[i];
        i-=(i&-i);
    }
    cout<<ret<<" ";
}
int main(){
    cin>>t;
    while(t--){
        cin>>n>>m;
        memset(tr,0,sizeof(tr));
        int updateIdx=100001;
        mp.clear();
        for(int i=1;i<n+1;i++){
            mp[i]=i+updateIdx;
            update(i+updateIdx, 1);
        }
        int here;
        for(int i=0;i<m;i++){
            cin>>here;
            int idx=mp[here];
            cal(here);
            update(idx,-1);
            update(--updateIdx,1);
            mp[here]=updateIdx;
        }
    }
}