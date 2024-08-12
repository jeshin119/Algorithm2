#include <bits/stdc++.h>
using namespace std;
int n,tmp;
struct cmp{
    bool operator()(int a,int b){
        if (abs(a)==abs(b)){
            return (a>b);
        }
        return (abs(a)>abs(b));
    }
};
priority_queue <int,vector<int>,cmp> pq;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>tmp;
        if (tmp==0&&pq.size()){
            cout<<pq.top()<<"\n";pq.pop();
            continue;
        }
        if (tmp==0&&pq.size()==0){
            cout<<"0"<<"\n";
            continue;
        }
            pq.push(tmp);
    }
}