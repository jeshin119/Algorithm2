#include <bits/stdc++.h>
using namespace std;
int n,a[1004];
int _prev[1004],cnt[1004],last;
void out(int start){
    if (start<0){
        return ;
    }
    out(_prev[start]);
    cout<<a[start]<<" ";
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    fill(_prev, _prev+1004, -1);
    fill(cnt,cnt+1004,1);
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if (a[j]<a[i] && cnt[j]+1 > cnt[i]){
                cnt[i]=cnt[j]+1;
                _prev[i]=j;
            }
        }
        if (cnt[last] < cnt[i])
            last=i;
    }
    cout<<cnt[last]<<"\n";
    out(last);
}   