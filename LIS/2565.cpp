//백준 전깃줄
//lowerbound를 사용해서 lis배열을 만들건데 
//1. 먼저 정렬해야 2. lower_bound가 알아서 위치를 찾아주니, 무조건 갱신시켜도 무방 3.목표값 이상의 값이 없다면 끝을 반환하므로 추가하면 됨
#include <bits/stdc++.h>
using namespace std;
int t,lis[504],len;
vector<pair<int,int>> v;
int main(){
    cin>>t;
    for(int i=0;i<t;i++){
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        auto it = lower_bound(lis,lis+len,v[i].second);
        if (*it==0)
            len++;
        *it=v[i].second;
    }
    cout<<t-len<<"\n";
}