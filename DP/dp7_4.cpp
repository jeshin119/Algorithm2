#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
int n,a[1000004];
int f(int here){
    if (here==0){
        cout<<"\n";
        return 0;
    }
    cout<<here<<" ";
    if (here%3==0 && a[here]== a[here/3]+1)
        f(here/3);
    else if (here%2==0 && a[here] == a[here/2]+1)
        f(here/2);
    else if (here-1 && a[here] == a[here-1]+1)
        f(here-1);
    return 0;
}
int main(){
    cin>>n;
    fill(a,a+1000004,INF);
    a[1]=0;
    for(int i=0;i<=n;i++){
        if (i%3==0){
            a[i]=min(a[i/3]+1, a[i]);
        }
        if (i%2==0){
            a[i]=min(a[i/2]+1,a[i]);
        }
        a[i]=min(a[i-1]+1,a[i]);
    }
    cout<<a[n]<<"\n";
    f(n);
}