//잘못된풀이
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,k,m;

int main(){
    std::ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m>>k;
    vector<long long> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    for(int i=n+1;i!=n+k+m+1;i++){
        vector<long long> vv(3);
        for(int j=0;j<3;j++){
            cin>>vv[j];
        }
        if (vv[0]==1){
            v[vv[1] - 1] = vv[2];
        }
        if (vv[0]==2){
            ll out=0;
            for(int k=vv[1]-1;k<=vv[2]-1;k++){
                out+=v[k];
            }
            cout<<out<<"\n";
        }
    }
}
// 연산을 범위만큼 반복하니 시간초과가 뜸. m과 k가 만까지 가능하므로 만x만 = 십억.