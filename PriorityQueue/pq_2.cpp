#include <bits/stdc++.h>
using namespace std;
int n,tmp,ret;
class cmp{
public:
    bool operator()(int a,int b){
        return (a>b);
    }
};
priority_queue<int,vector<int>,cmp>pq;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    while (n--){
        cin>>tmp;
        pq.push(tmp);
    }
    while (pq.size()>=2){
        int left,right,result;
        left = pq.top();pq.pop();
        right=pq.top();pq.pop();
        result=left+right;pq.push(result);
        ret+=result;
    }
    cout<<ret;
}