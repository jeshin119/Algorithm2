#include <vector>
#include <deque>
using namespace std;
//sudo code
/*
BFS(G,u){
	u.visited=true;
	q.push(u);
	while(q.size()){
		u=q.front();
		q.pop();
		for(each v:G.adj[u]){
			if (visited[v]==false){
				visited[v]=true;
				q.push(v);
			}

		}
	}
}
*/

//가중치 같은 그래프에서 최단거리
//가중치가 다르면 다익스트라 , 벨만포드를 써야함
/*
BFS(G,u){
	u.visited=true;
	q.push(u);
	while(q.size()){
		u=q.front();
		q.pop();
		for (each v : G.adj[u]){
			if (v.visited==false){
				v.visited=u.visited+1
				BFS(G,v);
			}
		}
	}
}
*/

int main(){

}