#include <bits/stdc++.h>
using namespace std;
int n,a[21],ret=1e9;
void go(int here){
    if (here == n){
        int sum=0;
        for(int i=1;i<(1<<n);i*=2){
            int cnt=0;
            for(int j=0;j<n;j++){
                if (a[j]&i){
                    // printf("j:%d, a[j]: %d, i: %d\n",j, a[j],i);
                    cnt++;
                }
            }
            sum+=min(cnt,n-cnt);
        }
        ret=min(ret,sum);
        // printf("sum: %d\n",sum);
        return ;
    }
    go(here+1);
    a[here]=~a[here];
    go(here+1);
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    string s;
    for(int i=0;i<n;i++){
        cin>>s;
        int val=0;
        for(int j=0;j<n;j++){
            if (s[j]=='T'){
                val|=(1<<j);
            }
        }
        a[i]=val;
    }
    go(0);
    cout<<ret<<"\n";
}