//boj 11404
#include <bits/stdc++.h>
using namespace std;
int n,m,a,b,c;
int dist[104][104];
const int INF=1e9;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    fill(&dist[0][0],&dist[0][0]+104*104,INF);
    cin>>n>>m;
    for(int i=0;i!=m;i++){
        cin>>a>>b>>c;
        dist[a][b] = min(dist[a][b],c);
    }
    for(int k=1;k!=n+1;k++)
        for(int j=1;j!=n+1;j++)
            for(int i=1;i!=n+1;i++)
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
    for(int i=1;i!=n+1;i++){
        for(int j=1;j!=n+1;j++){
            if (i==j)
                cout<<"0 ";
            else if (dist[i][j] == INF)
                cout<<"0 ";
            else
                cout<<dist[i][j]<<" ";
        }
        cout<<"\n";
    }
}