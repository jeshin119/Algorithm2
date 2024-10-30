#include <bits/stdc++.h>
using namespace std;
int n,a[24][24];
int flg[24][24];
int ret = 987654321;
int cmp1,cmp2;
vector<vector<int>>v;

void combi(int start,int n,vector<int>tmp){
    if(tmp.size() == n/2)
    {
        v.push_back(tmp);
        return ;
    }
    for(int i=start+1;i<n;i++){
        tmp.push_back(i);
        combi(i,n,tmp);
        tmp.pop_back();
    }
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>> a[i][j];
        }
   }
    vector<int>tmp;
    combi(-1,n,tmp);
    int cnt = v.size();
    while(cnt--){
        for(vector<int>e:v){
            fill(&flg[0][0],&flg[0][0]+n*n,0);
            cmp1 = 0;
            cmp2 = 0;
            for(int i=0;i<n;i++){
                for(int j:e){
                    if(i==j){
                        cmp1+=a[i][j]+a[j][i];
                    }
                    else{
                        cmp2+=a[i][j]+a[j][i];
                    }
                }
            }
        }
        ret = min(ret,abs(cmp1-cmp2));
    }
    cout<<ret;
}