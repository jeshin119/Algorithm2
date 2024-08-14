#include <bits/stdc++.h>
using namespace std;
//BFS

//일반적인형태
//if vertex is 10
vector<int>adj[10];
bool vis[10];
queue<int>q;
int main(){
    q.push(1);
    vis[1]=1;
    while (!q.empty()){
        int u=q.front();q.pop();
        for(auto v:adj[u]){
            if (vis[v])  continue;
            q.push(v); vis[v]=1;
        }
    }
}

//거리가 필요하다면
vector<int>adj[10];
int dist[10];
queue<int>q;
int main(){
    fill(dist,dist+10,-1);
    q.push(1);
    dist[1]=0;
    while(!q.empty()){
        int u=q.front();q.pop();
        for(auto v:adj[u]){
            if (dist[v]!=-1)continue;
            q.push(v); dist[v]=dist[u]+1;
        }
    }
}

//연결그래프가 아닐때
vector<int>adj[10];
int vis[10];
queue<int>q;
int main(){
    for(int i=0;i<10;i++){
        if (vis[i]) continue;
        q.push(i);vis[i]=1;
        while(!q.empty()){
            int u=q.front();q.pop();
            for(auto v:adj[u]){
                if (vis[v])continue;
                q.push(v);vis[v]=1;
            }
        }
    }
}