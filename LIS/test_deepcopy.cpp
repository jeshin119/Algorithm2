// cin으로 변수에 값을 받고 배열에 다시 넣었을 때 깊은복사가 이뤄지는지?
// 주소값을 참조한게 아니라 값을 참조했으므로 깊은 복사가 이뤄진다.

#include <bits/stdc++.h>
using namespace std;
pair<int,int>a[10];
int i,j;
int main(){
    int t=3;
    while (t--){
        cin>>i>>j;
        a[t].first=i; a[t].second=j;
    }
    for(int k=2;k>=0;k--){
        cout<<a[k].first<<' '<<a[k].second<<"\n";
    }
}