//boj 2042
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,k;
void update(ll val, int i, vector<ll>& t){
    while (i < t.size()){
        t[i] += val;
        i += i & -i;
    }
}
ll sum(int i, vector<ll>& t){
    ll out=0;
    while (i>0){
        out += t[i];
        i -= i& -i;
    }
    return out;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m>>k;
    vector<ll> v(n+1);
    vector<ll> t(n+1);
    for(int i=1;i<n+1;i++){
        cin>>v[i];
        update(v[i], i, t);
    }
    vector<ll> tmp(3);
    for(int i=1;i<m+k+1;i++){
        for(int j=0;j<3;j++){
            cin>>tmp[j];
        }
        if (tmp[0] == 1){
            update(tmp[2] - v[tmp[1]], tmp[1], t);
            v[tmp[1]] = tmp[2];
        }
        if (tmp[0] == 2){
            cout<<sum(tmp[2], t) - sum(tmp[1] - 1, t)<<"\n";
        }
    }
}