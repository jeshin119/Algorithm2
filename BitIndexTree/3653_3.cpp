//long long 으로 연산하면 시간초과남. e.g tr, cal에서 반환 및 ret을 long long 으로 하면.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n,m;
ll tr[200004];
int gap=100000;
map<int,int>mp;
void update(int i, int val){
    while (i<200004){
        tr[i]+=val;
        i+=i&-i;
    }
}
ll cal(int i){
    ll ret=0;
    while (i>0){
        ret+=tr[i];
        i-=i&-i;
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>t;
    while (t--){
        cin>>n>>m;
        memset(tr,0,sizeof(tr));
        mp.clear();
        for(int i=1;i<=n;i++){
            update(i+gap,1);
            mp[i]=i+gap;
        }
        int here;
        int mi=1+gap;
        for(int i=0;i<m;i++){
            cin>>here;
            cout << cal(mp[here])-1<<" ";
            update(mp[here], -1);
            update(--mi,1);
            mp[here]=mi;
        }
        cout<<"\n";
    }
}