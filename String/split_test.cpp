#include <bits/stdc++.h>
using namespace std;
string s;
size_t pos;
int main(){
    cin>>s;
    if(s.size())
        cout<<s[0];
    while(s.size() && (pos=s.find('-'))!=string::npos){
        if (s[pos+1]==0)
            break;
        cout<<s[pos+1];
        // s = s.substr(pos+1);
        s.erase(0,pos+1);
    }

}