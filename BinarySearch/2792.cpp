//boj 2792 보석상자
//생각치도 못함 binarysearch를.

#include <bits/stdc++.h>
using namespace std;
int n,m,ret;
void c2(int t,int g){

}
void check(int t,int g){
    int tmp;
    if (t>=g)
        tmp = t%g + t/g;
    else 
        tmp = t%g;
    ret=max(ret,tmp);
}
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int tmp;
        cin>>tmp;
        if (n%m == 0)
            check(tmp,n/m);
        else
            check(tmp,n/m+1);
    }
    cout<<ret<<"\n";
}