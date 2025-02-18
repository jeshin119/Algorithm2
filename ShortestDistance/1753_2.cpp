#include <bits/stdc++.h>
using namespace std;
int v,e,k,u,tmpv,w,INF=1e9;
vector<pair<int,int>>adj[200004];
int dist[200004];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>v>>e>>k;
    fill(dist,dist+200004,INF);
    dist[k]=0;
    pq.push({0,k});
    for(int i=0;i<e;i++){
        cin>>u>>tmpv>>w;
        adj[u].push_back({w,tmpv});
    }
    while (pq.size()){
        int here=pq.top().second;
        int here_dist=pq.top().first;
        pq.pop();
        if (dist[here]!=here_dist)
            continue;
        for(auto there: adj[here]){
            int _there=there.second;
            int _there_dist=there.first;
            if (dist[_there] > dist[here] + _there_dist){
                dist[_there]=dist[here]+_there_dist;
                pq.push({dist[_there],_there});
            }
        }
    }
    for(int i=1;i<=v;i++){
        dist[i]!=INF ? cout<<dist[i]<<"\n" : cout<<"INF\n";
    }
}