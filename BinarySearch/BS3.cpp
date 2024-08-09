//BOJ1920수찾기
#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int>v;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    sort(v.begin(),v.end());
    cin>>m;
    for(int i=0;i<m;i++){
        int tmp;
        cin>>tmp;
        cout<<binary_search(v.begin(),v.end(),tmp)<<"\n";
    }
}