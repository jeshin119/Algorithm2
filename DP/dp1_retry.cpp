//boj1463 1로 만들기 
//topdown으로 해보기
#include <bits/stdc++.h>
using namespace std;
int INF=987654321;
int a[1000004],n;

int go(int start){
    if (start<=1)
        return 0;
    int& ret = a[start];
    if (ret!=INF){
        return ret;
    }
    int q=INF;
    int w=INF;
    int e=INF;
    if (start%3==0){
        q= go(start/3)+1;
    }
    if (start%2==0){
        w= go(start/2)+1;
    }
    e=go(start-1)+1;
    return ret = min(q,min(w,e));
}
int main(){
    cin>>n;
    fill(a,a+1000004,INF);
    cout<<go(n)<<"\n";
}