// 1. 0으로 나누는 것 조심. 애초에 0으로 나눠지지 않도록 세팅해야. 그래서 l의 초기값이 1.
// 2. binary search할때 l<r으로해야하는지 l<r로 해야하는지? : 
/*
조건	while (l < r)	while (l <= r)
목적	특정 조건을 만족하는 첫 위치 찾기 (lower/upper bound)	값이 존재하는지 확인
탐색 종료 조건	l == r	l > r
mid값 포함 여부	r = mid (mid 포함)	r = mid - 1 (mid 제외)
결과	l 또는 r이 원하는 값	값이 존재하면 mid, 없으면 추가 처리 필요
*/
// 3. check에서 num과 n의 관계를 반환할때 같은경우는 어떻게해야하는지?


#include <bits/stdc++.h>
using namespace std;
int n,m,a[300004],l=1,r,ret=1e9;
bool check(int jelas){
    int num=0;
    for(int i=0;i<m;i++){
        num+=a[i]/jelas;
        if (a[i]%jelas)
            num++;
    }
    // cout<<"num: "<<num<<"\n";
    return (num <= n);
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a[i];
        r=max(r,a[i]);
    }
    while (l<=r){
        // cout<<"start\n";
        // cout<<"l: "<<l<<", ";
        // cout<<"r: "<<r<<"\n";
        int jelas=(l+r)/2;
        if (check(jelas)){
            r=jelas-1;
            ret=min(ret,jelas);
        }else
            l=jelas+1;
        // cout<<"end\n";
    }
    cout<<ret<<"\n";
}