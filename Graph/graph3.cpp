//boj 3197 백조의호수//flood fill
//bfs로 풀 수 있을 것 같은데... 백조끼리 만났다는 것을 어떻게 알 수 있을까?bfs를 두번쓰면될랑가?
#include <bits/stdc++.h>
using namespace std;
int r,c,day;
pair<int,int>sVis[1504][1504];
char m[1504][1504];
int dy[4]={-1,0,1,0},dx[4]={0,-1,0,1};
queue<pair<int,int>>swan;
queue<pair<int,int>>water;
void melt(){
    int size=water.size();
    while (size--){
        int y,x;
        tie(y,x)=water.front();water.pop();
        for(int i=0;i<4;i++){
            int ny=y+dy[i];
            int nx=x+dx[i];
            if (ny<0||nx<0||ny>=r||nx>=c)
                continue;
            if (m[ny][nx]!='X')
                continue;
            m[ny][nx]='.';water.push({ny,nx});swan.push({ny,nx});
        }
    }
}
bool move(){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++)
            cout<<m[i][j];
        cout<<"\n";
    }
    cout<<"\n";
    while(!swan.empty()){
        int y,x;
        tie(y,x)=swan.front();swan.pop();
        for(int i=0;i<4;i++){
            int ny=y+dy[i];
            int nx=x+dx[i];
            if (ny<0||nx<0||ny>=r||nx>=c)
                continue;
            if(sVis[ny][nx].first>=0 || (sVis[y][x].first == ny && sVis[y][x].second == nx))
                continue;
            if (m[ny][nx]=='L'){
                cout<<"sVis[ny][nx]: "<<sVis[ny][nx].first<<" "<<sVis[ny][nx].second<<"\n";
                cout<<"y: "<<y<<", x: "<<x<<"\n";
               return false;
            }
            if (m[ny][nx]!='.')
                continue;
            sVis[ny][nx]={y,x};;swan.push({ny,nx});
        }
    }
    return true;
}
int main(){
    cin>>r>>c;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++)
            sVis[i][j]={-1,-1};
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>m[i][j];
            if (m[i][j]=='L'){
                swan.push({i,j});
            }
            if (m[i][j]=='.'){
                water.push({i,j});
            }
        }
    }
    // move();
    // melt();
    // if (move()==false)
    //     cout<<"ffffffffffffff\n";
    // melt();
    // if (move()==false)
    //     cout<<"ffffffffffffff\n";
    // melt();
    // if (move()==false)
    //     cout<<"ffffffffffffff\n";
    // if (move()==false)
    //     cout<<"ffffffffffffff\n";
    while(move()){
        sleep(4);
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cout<<"{"<<sVis[i][j].first<<","<<sVis[i][j].second<<"}";
            }
            cout<<"\n";
        }
        melt();
        day++;
    }
    cout<<day<<"\n";
}