#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,k;
ll a,b,c;
void update(int i,ll val, vector<ll>& ps){
    while (i<n+1){
        ps[i]+=val;
        i+=i&-i;
    }
}
ll cal(int i, vector<ll>& ps){
    ll ret=0;
    while (i>0){
        ret+=ps[i];
        i-=i&-i;
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>m>>k;
    vector<ll> v(n+1);
    vector<ll> ps(n+1);
    for(int i=1;i<=n;i++){
        cin>>v[i];
        update(i,v[i],ps);
    }
    for(int i=0;i<m+k;i++){
        cin>>a>>b>>c;
        if (a==1){
            update(b,c-v[b],ps);
            v[b]=c;
        }
        if (a==2){
            cout<<cal(c,ps)-cal(b-1,ps)<<"\n";
        }
    }
}