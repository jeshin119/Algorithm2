#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;
int n,k,w,v,d[100001][101],ret;
pair<int,int>a[100001];
int go(int weight, int idx){
    if (weight==0 || idx==n){
        return 0;
    }
    int &ret=d[weight][idx];
    if (~ret)
        return ret;
    ret = go(weight, idx+1);
    if (weight-a[idx].first >=0){
        ret = max(ret, go(weight- a[idx].first , idx+1)+ a[idx].second);
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i].first>>a[i].second;
    }
    fill(&d[0][0],&d[0][0]+100001*101,-1);
    cout<<go(k,0);
    
}