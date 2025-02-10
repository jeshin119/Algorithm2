//아니 이게 왜 누적합이냐고.
//잘못된풀이. 볼 것없음.
#include <bits/stdc++.h>
using namespace std;
int k,m,n;
void update(int here,vector<int>& t){
    int val = t[here];
    while (here < t.size()){
        t[here]-=val;
        here += (here & -here);
    }
}
void cal(int here, vector<int>& t){
    long long out=0;
    while (here>0){
        out+=t[here];
        here-= (here & -here);
    }
    cout<<out<<" ";
}
int main(){
    cin>>k;
    for(int i=0;i<k;i++){
        cin>>n>>m;
        vector<int>t(n+1);
        for(int i=1;i<n+1;i++){
            t[i]=i-1;
        }
        for(int i=0;i<m;i++){
            int here=0;
            cin>>here;
            cal(here, t);
            update(here, t);
        }
    }

}