#include <iostream>
#include <cstring>
using namespace std;
int n,c,d[100001],m,p,ret;
float tmp;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    while (true){
        cin>>n>>tmp;
        if (!n && !tmp)
            return 0;
        memset(d,0,sizeof(d));
        ret=0;
        m=(tmp+0.005f)*100;
        for(int i=0;i<n;i++){
            cin>>c>>tmp;
            p=(tmp+0.005f)*100;
            for(int j=p;j<=m;j++){
                d[j]=max(d[j],d[j-p]+c);
                ret=max(d[j],ret);
            }
        }
        cout<<ret<<"\n";
    }
}