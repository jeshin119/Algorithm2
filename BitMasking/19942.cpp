#include <bits/stdc++.h>
using namespace std;
int n,mp,mf,ms,mv,ret=1e9;
typedef struct data{
    int p;
    int f;
    int s;
    int v;
    int c;
} _data;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>mp>>mf>>ms>>mv;
    vector<_data>v(n+1);
    for(int i=0;i<n;i++){
        cin>>v[i].p>>v[i].f>>v[i].s>>v[i].v>>v[i].c;
    }
    vector<int>retlist{16};
    for(int i=0;i<(1<<n);i++){
        _data isok;
        memset(&isok,0,sizeof(isok));
        vector<int>list;
        for(int j=0;j<n;j++){
            if(i & (1<<j)){
                isok.p+=v[j].p;
                isok.f+=v[j].f;
                isok.s+=v[j].s;
                isok.v+=v[j].v;
                isok.c+=v[j].c;
                list.push_back(j);
            }
        }
        if (isok.p>=mp && isok.f>=mf && isok.s>=ms && isok.v>=mv && ret>=isok.c){
            if (ret == isok.c)
                retlist=min(retlist,list);
            else 
                retlist=list;
            ret=isok.c;
        }
    }
    if (ret==1e9){
        cout<<-1<<"\n";
        return 0;
    }
    cout<<ret<<"\n";
    for(auto t:retlist){
        cout<<t+1<<" ";
    }
    return 0;
}