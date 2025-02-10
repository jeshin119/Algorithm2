// 번갈아서 서로 이동하는경우

// 틀린점
/*
    while(q.size()){
        spread();
*/
// 위와 같이 작성하는 건 잘못됨. 왜냐하면 q.size()를 확인하고 front에 접근 후 spread를 하는게 지훈이가 이동가능한 모든방향을 탐색한게 아니기 때문. 가능한 방향 중 하나만 탐색한 것. 

#include <bits/stdc++.h>
using namespace std;
int r,c,visited[1004][1004],fvisited[1004][1004];
char a[1004][1004];
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
pair<int,int>jh;
vector<pair<int,int>>fire;
queue<pair<int,int>>q;
queue<pair<int,int>>fq;

void spread(){
    // cout<<"spread!\n";
    queue<pair<int,int>>tmpfq;
    while(fq.size()){
        int y=fq.front().first;
        int x=fq.front().second;
        // cout<<y<<" "<<x<<"\n";
        fq.pop();
        for(int i=0;i<4;i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny<0 || nx<0 || ny>=r || nx>=c)
                continue;
            if (fvisited[ny][nx])
                continue;
            if (a[ny][nx]=='#')
                continue;
            tmpfq.push({ny,nx});
            fvisited[ny][nx]=fvisited[y][x]+1;
        }
    }
    fq = tmpfq;
    // cout<<"spread end!\n";
}
int main(){
    cin>>r>>c;
    for(int i=0;i<r;i++){
        for (int j=0;j<c;j++){
            cin>>a[i][j];
            if (a[i][j]=='J'){
                if (i==r || j==c || i== 0 || j==0){
                    cout<<"1\n";
                    return 0;
                }
                q.push({i,j});
                visited[i][j]=1;
            }
            if (a[i][j]=='F'){
                fq.push({i,j});
                fvisited[i][j]=1;
            }
        }
    }
    while(q.size()){
        int y=q.front().first;
        int x=q.front().second;
        if (y==r || x==c || y== 0 || x==0){
            cout<<visited[y][x]+1<<"\n";
            return 0;
        }
        q.pop();
        for(int i=0;i<4;i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny<0 || nx<0 || ny>=r || nx>=c)
                continue;
            if (visited[ny][nx] || fvisited[ny][nx])
                continue;
            if (a[ny][nx]!='.')
                continue;
            q.push({ny,nx});
            visited[ny][nx]=visited[y][x]+1;
        }
        spread();
    }
    cout<<"IMPOSSIBLE\n";
}