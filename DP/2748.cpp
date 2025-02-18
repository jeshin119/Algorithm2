//피보나치 수2
#include <bits/stdc++.h>
using namespace std;
long long n,a[94];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    a[0]=0;a[1]=1;
    for(int i=0;i<90;i++){
        a[i+2]=a[i]+a[i+1];
    }
    cin>>n;
    cout<<a[n];
}