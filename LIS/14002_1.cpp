#include <bits/stdc++.h>
using namespace std;
int a[1004],n,cnt[1004],pr[1004],last;
void prt_pr(int idx){
    if (idx==-1){
        return ;
    }
    prt_pr(pr[idx]);
    cout<<a[idx]<<" ";
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    fill(cnt,cnt+1004,1);
    fill(pr,pr+1004,-1);
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if (a[j]<a[i] && cnt[j]+1>cnt[i]){
                cnt[i]=cnt[j]+1;
                pr[i]=j;
            }
        }
        if (cnt[last]<cnt[i])
            last=i;
    }
    cout<<cnt[last]<<"\n";
    prt_pr(last);
}