#include <iostream>
#include <vector>
using namespace std;
int a[15][15],n,ret,cnt;
void	queen(int y,int x,vector<pair<int,int> >&v){
	for(int i=y+1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int flg=0;
			for(auto m : v){
				if (m.first == i){
					flg=1;
					break;
				}
				if (m.second == j){
					flg=1;
					break;
				}
				if (m.first -i == m.second -j){
					flg=1;
					break;
				}
				if (m.first -i == -m.second +j){
					flg=1;
					break;
				}
			}
			if (flg)
				continue;
			v.push_back({i,j});
			cnt++;
			break;
		}
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			vector<pair<int,int>>v;
			cnt=1;
			v.push_back({i,j});
			queen(i,j,v);
			if (cnt==n)
				ret++;
		}
	}
	cout<<ret;
}