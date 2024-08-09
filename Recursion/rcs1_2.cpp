#include <iostream>
using namespace std;
using ll=long long;
int dc(ll a,ll b,ll c)
{
	if (b==0)
		return (1);
	if (b==1)
		return (a%c);
	// if a^b %c == mod, then, a^2b %c = mod*mod
	ll _mod = dc(a,b/2,c);
	_mod = _mod * _mod %c;
	if (b%2==0)return _mod;
	return (_mod * a%c);
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll a,c,b,mod=1; 
	cin>>a>>b>>c;
	cout << dc(a,b,c); // divide and conquer
	return 0;
}