#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k;
vector<pair<ll,ll>> jul;
vector<ll>bag;
int putted[300004];
ll weight,price,tmp,ret;


int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>weight>>price;
        jul.push_back({weight,price});
    }
    for(int i=0;i<k;i++){
        cin>>tmp;
        bag.push_back(tmp);
    }
    sort(bag.begin(),bag.end());
    sort(jul.begin(),jul.end());
    for(int i=0;i<k;i++){
        int index=-1;
        for(int j=0;j<n;j++){
            if (putted[j])
                continue;
            if (bag[i]<jul[j].first)
                break;
            if (index==-1 && !putted[j])
                index=j;
            if (jul[index].second <= jul[j].second)
                index = j;
        }
        ret+=jul[index].second;
        putted[index]=1;
    }
    cout<<ret<<"\n";
}