#include <bits/stdc++.h>
using namespace std;
int r,c,t,flg,ret;
int tmp[54][54],a[54][54];
int dy1[4]={0,-1,0,1};
int dx1[4]={1,0,-1,0};
int dy2[4]={0,1,0,-1};
int dx2[4]={1,0,-1,0};
vector<pair<int,int>>cl[2];

void spread(){
    fill(&tmp[0][0],&tmp[54][54],0);
    queue<pair<int,int>>q;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(a[i][j && a[i][j]!=-1]){
                q.push({i,j});
            }
        }
    }
    while(q.size()){
        int y=q.front().first;
        int x=q.front().second;
        q.pop();
        int per =a[y][x]/5;
        for(int i=0;i<4;i++){
            int ny=y+dy1[i];
            int nx=x+dx1[i];
            if(ny<0||nx<0||ny>=r||nx>=c)
                continue;
            if(a[ny][nx]==-1)
                continue; 
            tmp[ny][nx]+=per;
            a[ny][nx]-=per;
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
                a[i][j]+=tmp[i][j];
        }
    }
}

vector<pair<int,int>> cleaner(int sy,int sx,int dy[],int dx[]){
    vector<pair<int,int>>ret;
    int cnt =0;
    int y=sy;
    int x=sx;
    while(true){
        int ny=y+dy[cnt];
        int nx=x+dx[cnt];
        if(ny==sy&&nx==sx)
            break;
        if(ny<0||nx<0||ny>=r||nx>=c){
            cnt++;
            continue;
        }
        y=ny;
        x=nx;   
        ret.push_back({ny,nx});
    }
    return ret;
}

void mv(vector<pair<int,int>>&v){
    for(int i=v.size()-1;i>0;i--){
        a[v[i].first][v[i].second] = a[v[i-1].first][v[i-1].second];
    }
    a[v[0].first][v[0].second]=0;
}
int main()
{
    cin>>r>>c>>t;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>a[i][j];
            if(a[i][j]==-1 && !flg){
                flg=1;
                cl[0]=cleaner(i,j,dy1,dx1);
            }
            else if(a[i][j]==-1 && flg){
                cl[1]=cleaner(i,j,dy2,dx2);
            }
        }
    }
    while(t--){
        spread();
        mv(cl[0]);
        mv(cl[1]);
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(a[i][j]!=-1)
                ret+=a[i][j];
        }
    }
    cout<<ret<<"\n";
}