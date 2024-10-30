#include <bits/stdc++.h>
using namespace std;
int n,a[24][24],ret;
void getmax(int (&a)[24][24]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ret=max(ret,a[i][j]);
        }
    }
}
void rotate(int (&a)[24][24]){
    int tmp[24][24];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            tmp[i][j]=a[n-j-1][i];
        }
    }
    memcpy(a,tmp,sizeof(a));
}
void move(int (&a)[24][24]){
    int tmp[24][24];
    for(int i=0;i<n;i++){
        int c=-1,d=0;
        for(int j=0;j<n;j++){
            if(a[i][j]==0)continue;
            if(d&&tmp[i][c]==a[i][j]){
                tmp[i][c]*=2;d=0;
            }
            else{
                tmp[i][++c]=a[i][j];d=1;
            }
        }
        for(c++;c<n;c++)tmp[i][c]=0;
    }
    memcpy(a,tmp,sizeof(a));
}

void go(int (&a)[24][24],int start){
    if(start==5){
        getmax(a);
        return ;
    }
    for(int i=0;i<4;i++){
        int tmp[24][24];
        memcpy(tmp,a,sizeof(a));
        move(tmp);
        go(tmp,start+1);
        rotate(a);
    }
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    go(a,0);
    cout<<ret<<"\n";
}