#include <iostream>
#include <utility>
#include <cstring>
using namespace std;
int n,a[17][17],d[17][17][3];
bool ok(int y, int x, int direction){
    if (direction==0){
        int ny=y;
        int nx=x+1;
        if (ny>n-1 || nx>n-1)
            return false;
        if (a[ny][nx])
            return false;
    }
    if (direction==1){
        int ny=y+1;
        int nx=x+1;
        if (ny>n-1 || nx>n-1)
            return false;
        if (a[ny][nx] || a[ny][x] || a[y][x+1])
            return false;
    }
    if (direction==2){
        int ny=y+1;
        int nx=x;
        if (ny>n-1 || nx>n-1)
            return false;
        if (a[ny][nx])
            return false;
    }
    return true;
}
int go(int y, int x, int direction){
    if (y==n-1 && x==n-1){
        return a[y][x] ? 0 : 1;
    }
    int& ret=d[y][x][direction];
    if (~ret)
        return ret;
    ret=0;
    if (direction==0){
        if (ok(y,x,0))
            ret+=go(y,x+1,0);
        if (ok(y,x,1))
            ret+= go(y+1,x+1,1);
    }
    if (direction==1){
        if (ok(y,x,1))
            ret+=go(y+1,x+1,1);
        if (ok(y,x,0))
            ret+=go(y,x+1,0);
        if (ok(y,x,2))
            ret+=go(y+1,x,2);
    }
    if (direction==2){
        if (ok(y,x,1))
            ret+=go(y+1,x+1,1);
        if (ok(y,x,2))
            ret+=go(y+1,x,2);
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    memset(d,-1,sizeof(d));
    cout<<go(0,1,0);
}
