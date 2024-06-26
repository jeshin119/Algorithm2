#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <map>
using namespace std;
//n: total number of player, m: number of weak player
#define MAXNUM 20
int n,m,t,p,visited[MAXNUM],play[MAXNUM];
string player[MAXNUM];
string weaker[MAXNUM];
vector<string>player;
vector<string>weaker;

void normal(){
	int	th = n*60/p;
	int	init = th;
	srand(time(NULL));
	while(th){
		int _try=n;
		memset(visited,0,sizeof(visited));
		while(_try){
			int tmp = rand()%n;
			if (visited[tmp])
				continue;
			if (play[tmp]<init-th);
			visited[tmp]=1;
			play[tmp]++;
			_try--;
		}	
		th--;
	}
}
void consider_weaker(){

}
void prt(){

}
int numerr(){
	if (n>MAXNUM){
		cout<<"inputted total player number is more than MAXNUM."<<"\n";
		cout<<"MAXNUM : "<<MAXNUM<<"\n";
		return 1;
	}
	return 0;
}
int timeerr(){
	if (t<0 || p<0){
		cout<<"gametimes hour must be positive\n";
		return 1;
	}
	if (p>t*60){
		cout<<"gametimes hour must be positive\n";
		return 1;
	}
	return 0;
}
int care_input(){
	cout<<"input number of total player: ";
	cin>>n;
	cout<<"input number of weak player.: ";
	cin>>m;
	if (numerr())
		return 1;
	cout<<"input total gametime hours: \n";
	cin >>t;
	cout<<"inputper gametime minutes: \n";
	cin>>p;
	if (timeerr())
		return 1;
	return 0;
}
int	get_players_name(){
	if (!m)
	{
		cout<<"input each player's name seperated by space or enter: \n";
		for(int i=0;i<n;i++){
			string s;
			cin>>s;
			player.push_back(s);
		}
	}
	if (m)
	{
		cout<<"input each weaker player's name seperated by space or enter: \n";
		for(int i=0;i<m;i++){
			string s;
			cin>>s;
			weaker.push_back(s);
		}
		cout<<"input each normal player's name seperated by space or enter: \n";
		for(int i=0;i<n-m;i++){
			string s;
			cin>>s;
			player.push_back(s);
		}
	}
	return 0;
}
int matching_num_to_player(){
	get_players_name();
	return 0;
}
int main(){
	if (care_input())
		return 1;
	if (!m)
		normal();
	else
		consider_weaker();
	matching_num_to_player();
	prt();
	return 0;
}