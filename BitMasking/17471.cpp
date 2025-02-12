#include <bits/stdc++.h>
using namespace std;
int n,people[11],adjcnt,ret=1e9;
int visited[11],cmp[11];
vector<int>adj[11];
int getCnt(vector<int>& v){
    int cnt=0;
    for(auto i:v){
        cnt+=people[i];
    }
    return cnt;
}
bool isConnected(vector<int>& v,int val){
    stack<int>st;   
    st.push(v.front());
    visited[v.front()]=1;
    while(st.size()){
        int here=st.top();
        st.pop();
        for(auto there:adj[here]){
            if (cmp[there]!=val)
                continue;
            if (visited[there])
                continue;
            st.push(there);
            visited[there]=1;
        }
    }
    for(auto i:v){
        if (visited[i]!=1)
            return false;
    }
    return true;
}
int check(vector<int>& a, vector<int>& b){
    if (isConnected(a,0)==false || isConnected(b,1)==false)
        return 1e9;
    return (abs(getCnt(b)-getCnt(a)));
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>people[i];
    }
    for(int i=1;i<=n;i++){
        cin>>adjcnt;
        int there;
        for(int j=0;j<adjcnt;j++){
            cin>>there;
            adj[i].push_back(there);
            adj[there].push_back(i);
        }
    }
    for(int i=1;i<(1<<n)-1;i++){
        vector<int>a;
        vector<int>b;
        memset(cmp,0,sizeof(cmp));
        memset(visited,0,sizeof(visited));
        for(int j=0;j<n;j++){
            if (i&(1<<j)){
                a.push_back(j+1);
            }else{
                b.push_back(j+1);
                cmp[j+1]=1;
            }
        }
        ret = min(ret,check(a,b));
    }
    if (ret==1e9)
        cout<<-1<<"\n";
    else
        cout<<ret<<"\n";
}
