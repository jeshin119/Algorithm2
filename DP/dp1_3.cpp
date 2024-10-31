#include <bits/stdc++.h>
using namespace std;
int a[1000004],n;
int f(int k){
    if (k<=1){
        return 0;
    }
    int q=f(k/3)+k%3+1;
    int w=f(k/2)+k%2+1;
    return (min(q,w));
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    cout<<f(n)<<"\n";
}