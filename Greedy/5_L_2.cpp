#include <bits/stdc++.h>
using namespace std;
int n,a[24][24];
int ret=987654321;

int go(vector<int>stark,vector<int>link){
    int cmp1=0,cmp2=0;
    for(int i=0;i<n/2;i++){
        for(int j=0;j<n/2;j++){
            if(i==j)continue;
            cmp1+=a[stark[i]][stark[j]];
            cmp2+=a[link[i]][link[j]];
        }
    }
    return (abs(cmp1-cmp2));
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<(1<<n);i++){
        if(__builtin_popcount(i) !=n/2)
            continue;
        vector<int>stark;
        vector<int>link;
        for(int j=0;j<n;j++){
            if(i&(1<<j)){
                stark.push_back(j);
            }
            else{
                link.push_back(j);
            }
        }
        ret=min(ret,go(stark,link));
    }
    cout<<ret<<"\n";
}