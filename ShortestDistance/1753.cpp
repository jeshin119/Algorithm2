#include <vector>
#include <queue>
#include <utility>
#include <iostream>
#include <algorithm>
using namespace std;
int V,E,K,u,v,w;
int dist[20004];
vector<pair<int,int> > adj[20004];
priority_queue<pair<int,int>,vector<pair<int,int> >, std::greater<pair<int,int>> > pq;
const int INF=1e9;
int main(){
    cin>>V>>E>>K;
    fill(dist,dist+20004,INF);
    for(int i=0;i<E;i++){
        cin>>u>>v>>w;
        adj[u].push_back(make_pair(w,v));
    }
    dist[K]=0;
    pq.push(make_pair(0,K));
    while(pq.size()){
        int hereDist=pq.top().first;
        int here=pq.top().second;
        pq.pop();
        if (dist[here]!=hereDist)
            continue;
        for(pair<int,int> there: adj[here]){
            if (dist[there.second] > there.first + dist[here]){
                dist[there.second] = there.first + dist[here];
                pq.push(make_pair(dist[there.second], there.second));
            }
        }
    }
    for(int i=1;i<V+1;i++){
        if (dist[i]==INF)
            cout<<"INF\n";
        else
            cout<<dist[i]<<"\n";
    }
}