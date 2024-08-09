//BOJ 2776 암기왕
#include <bits/stdc++.h>
using namespace std;
int t,n,tmp,ret;
void check(int start, int end, int cmp,vector<int> &v){
    int size;

    size = (end-start)/2 + start;
    if (start > end ){
        ret = 0;
        return ;
    }
    if (v[size]==cmp){
        ret=1;
        return ;
    }
    if (v[size]>=cmp){
        check(start,size-1,cmp,v);
    }
    else{
        check(size+1,end,cmp,v);
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>t;
    while(t--){
        vector<int> v;
        cin>>n;
            cin>>tmp;
            v.push_back(tmp);
        }
        sort(v.begin(),v.end());
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>tmp;
            check(0, v.size()-1, tmp, v);
            cout << ret <<'\n';
        }
    }
}