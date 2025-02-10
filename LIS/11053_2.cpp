//가장긴수열
//cnt 조건을 빼먹음
#include <bits/stdc++.h>
using namespace std;
int n,a[1004],cnt[1004],maxidx;
int main(){
    std::ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if (a[i] > a[j]){
                cnt[i] = max(cnt[j] + 1,cnt[i]);
                maxidx=i;
            }
        }
    }
    cout<<a[maxidx];
}