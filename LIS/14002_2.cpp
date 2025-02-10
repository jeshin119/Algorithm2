// 로직이 맞다면 참조값이 잘못되지 않았는지 확인해보고 반례는 같은 성질의 부분 집합이 있는 경우를 생각해보자.

/*
    if (a[i]>a[j] && cnt[i]<cnt[j]+1){
        cnt[i]=cnt[j]+1;
        _prev[i]=j;
        maxidx=i;
    }
}
위와 같이 첫번째 if문에서 maxidx=i로 무조건 갱신시켰다.
이러면 4 5 6 7 1 2 3 와 같은 수열이 들어왔을 때와 같이 더 큰 오름차순의 수열이 앞에 있어도 maxidx가 후위치의 오름차순을 가리키니 오답이다.

위 내용을 생각해내지 못하고 반례를 찾아봐서 알 수 있었다.
*/
#include <bits/stdc++.h>
using namespace std;
int n,cnt[1004],a[1004],_prev[1004],maxidx;
void prt_prev(int idx){
    if(idx==-1)
        return ;
    prt_prev(_prev[idx]);
    cout<<a[idx]<<" ";
}
int main(){
    cin>>n;
    fill(cnt,cnt+1004,1);
    fill(_prev,_prev+1004,-1);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if (a[i]>a[j] && cnt[i]<cnt[j]+1){
                cnt[i]=cnt[j]+1;
                _prev[i]=j;
            }
        }
        if (cnt[maxidx]<cnt[i])
            maxidx=i;
    }
    cout<<cnt[maxidx]<<"\n";
    prt_prev(maxidx);
}