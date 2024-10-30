//1,2,3더하기4
#include <bits/stdc++.h>
using namespace std;
int t,a[10004],n;
int main(){
    a[0]=1;
    for(int i=1;i<=3;i++){
        for(int j=1;j<=10000;j++){
            if (j-i>=0)
                a[j]+=a[j-i];
        }
    }
    cin>>t;
    while(t--){
        cin>>n;
        cout<<a[n]<<"\n";
    }
}