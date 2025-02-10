#include <bits/stdc++.h>
using namespace std;
vector<string> v;
string s;
string delimeter;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>s;
    cin>>delimeter;
    size_t pos=0;
    while ((pos=s.find(delimeter))!=string::npos){
        if (s.substr(0,pos).size())
            v.push_back(s.substr(0,pos));
        s.erase(0,pos+1);
    }
    for(auto token:v){
        cout<<token<<"\n";
    }
}