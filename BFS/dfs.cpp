#include <vector>
using namespace std;
const int n=10;
int visited[n];
vector<int>adj[n];

//sudo code
/*
DFS(u,adj){
	u.visited == true;
	for(each v:adj[u]){
		if v.visited == false
			DFS(v);
	}
}
*/

void dfs1(int here){
	visited[here]=1;
	for(int there:adj[here]){
		if (visited[there])
			continue;
		dfs1(there);
	}
}

void dfs2(int here){
	if (visited[here])
		return ;
	visited[here] = 1;
	for(int there : adj[here]){
		dfs2(there);
	}
}

int main(){

}