#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m,c,p,tmp1,tmp2,ret,dp[100001];
int main(){
    while (true){
        scanf("%d %d.%d",&n,&tmp1,&tmp2);
        m=tmp1*100+tmp2;
        if (n==0 && m==0)
            return 0;
        memset(dp,0,sizeof(dp));
        ret=0;
        for(int i=0;i<n;i++){
            scanf("%d %d. %d",&c,&tmp1,&tmp2);
            p=tmp1*100+tmp2;
            for(int j=p;j<=m;j++){
                dp[j]=max(dp[j], dp[j-p]+c);
                ret=max(dp[j],ret);
            }
        }
        printf("%d\n",ret);
    }
}