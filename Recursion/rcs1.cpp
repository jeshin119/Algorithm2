#include <iostream>
using namespace std;
using ll = long long;
int get(ll a,ll b,ll c){
	if (b==1)
		return (a%c);
	ll _mod = get(a,b/2,c);
	_mod = _mod * _mod % c;
	if (b%2==0) return _mod;
	return _mod *a %c;

}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll a,c,b,mod=1; 
	cin>>a>>b>>c;
	cout << get(a,b,c);
	return 0;
}