#include <iostream>
#include <utility>
#include <cstring>
using namespace std;
int n,a[20][20],d[20][20][3];
bool check(int y,int x,int dir){
    if (dir==0 || dir==2)
        return a[y][x] ? false:true;
    if (dir==1 && (a[y][x] || a[y-1][x] || a[y][x-1]))
        return false;
    return true;
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
    d[0][1][0]=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if (check(i,j+1,0)){
                d[i][j+1][0] += d[i][j][0];
                d[i][j+1][0] += d[i][j][1];
            }
            if (check(i+1,j+1,1)){
                d[i+1][j+1][1] += d[i][j][0];
                d[i+1][j+1][1] += d[i][j][1];
                d[i+1][j+1][1] += d[i][j][2];
            }
            if (check(i+1,j,2)){
                d[i+1][j][2] += d[i][j][2];
                d[i+1][j][2] += d[i][j][1];
            }
        }
    }
    cout<<d[n-1][n-1][0]+d[n-1][n-1][1]+d[n-1][n-1][2];
}