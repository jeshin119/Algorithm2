#include <bits/stdc++.h>
using namespace std;
int n,m,a[1004][1004],ret;
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
int check(int therey,int therex,pair<int,int>& p){
    return (abs(therey-p.first) + abs(therex-p.second));
}
int main(){
    cin>>n>>m;
    pair<int,int>p1={1,1};
    pair<int,int>p2={n,n};
    vector<int>who;
    while (m--){
        int y,x;
        cin>>y>>x;
        int v1=check(y,x,p1);
        int v2=check(y,x,p2);
        printf("v1: %d, v2: %d\n",v1,v2);
        if (v1<=v2){
            ret+=v1;
            p1={y,x};
            who.push_back(1);
        }else{
            ret+=v2;
            p2={y,x};
            who.push_back(2);
        }
    }
    cout<<ret<<"\n";
    for(int i:who){
        cout<<i<<"\n";
    }
}