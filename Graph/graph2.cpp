#include <bits/stdc++.h>
using namespace std;
//DFS

const int vertex = 10;
vector<int>adj[vertex];
int vis[vertex];
stack<int>s;
//using stack 
int main(){
    s.push(1);
    vis[1]=1;
    while (!s.empty()){
        int u=s.top();s.pop();
        for(auto v:adj[u]){
            if (vis[v])continue;
            s.push(v);vis[v]=1;
        }
    }
}
//using recursion
void dfs(int cur){
    vis[cur]=1;
    for(auto nxt:adj[cur]){
        if (vis[cur])
            continue;
        dfs(nxt);
    }
}
int main(){
    dfs(1);
}