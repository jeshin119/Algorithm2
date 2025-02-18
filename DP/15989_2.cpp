#include <bits/stdc++.h>
using namespace std;
int t,d[10001],tmp;
int main(){
    cin>>t;
    d[0]=1;
    for(int i=1;i<=3;i++){
        for(int j=1;j<=10000;j++){
            if (j-i>=0){
                d[j]+=d[j-i];
            }
        }
    }
    while (t--){
        cin>>tmp;
        cout<<d[tmp]<<"\n";
    }
}