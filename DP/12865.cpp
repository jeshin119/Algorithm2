#include <iostream>
#include <utility>
using namespace std;
int n,k,w,v,d[100001];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>w>>v;
        for(int j=k;j>=w;j--){
            d[j]=max(d[j],d[j-w]+v);
        }
    }
    cout<<d[k];
}