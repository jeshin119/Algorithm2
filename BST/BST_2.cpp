#include <bits/stdc++.h>
using namespace std;
int n,k;
long long ret;
pair<int,int>jul[300004];//가격,무게
multiset<int> bag;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>jul[i].second>>jul[i].first;
    }
    sort(jul,jul+n);
    for(int i=0;i<k;i++){
        int tmp;
        cin>>tmp;
        bag.insert(tmp);
    }
    for(int i=n-1;i>=0;i--){
        int m,v;
        tie(v,m)=jul[i];
        auto it=bag.lower_bound(m);
        if (it==bag.end())continue;
        ret+=v;
        bag.erase(it);
    }
    cout<<ret;
}