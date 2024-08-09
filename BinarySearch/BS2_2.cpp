#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,ret=1e18,a[300004];
int check(int jealous){
    ll student=0;
    for(int i=0;i<m;i++){
        student += a[i]/jealous;
        if (a[i]%jealous)
            student++;
    }
    return (n>=student);
}
int main(){
    cin>>n>>m;
    ll left=1, right=0;
    for(int i=0;i<m;i++){
        cin>>a[i];
        right=max(a[i],right);
    }
    while(left<=right){
        ll mid=(left+right)/2;
        if (check(mid)){
            right=mid-1;
            ret=min(ret,mid);
        }
        else
            left=mid+1;
    }
    cout<<ret<<"\n";
}