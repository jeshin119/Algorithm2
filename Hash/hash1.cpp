#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <algorithm>
using namespace std;
int n;
deque<string> d;
void using_dq(){
    unordered_map <string,int> m;
    cin>>n;
    for(int i=0;i<n;i++){
        string s;
        string ss;
        cin>>s>>ss;
        if (ss == "enter"){
            m[s]=1;
        }
        else{
            m[s]=0;
        }
    }

    for(auto e:m){
        if (e.second == 1)
            d.push_back(e.first);
    }
    sort(d.begin(),d.end(),greater());
    for(auto e:d)
        cout<<e<<"\n";
}
void using_nodq(){
    unordered_set <string> set;
    cin>>n;
    for(int i=0;i<n;i++){
        string s;
        string ss;
        cin>>s>>ss;
        if (ss == "enter"){
            set.insert(s);
        }
        else{
            set.erase(s);
        }
    }
    vector<string> v(set.begin(),set.end());
    sort(v.begin(),v.end(),greater());
    for(auto e:v){
        cout<<e<<"\n";
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    using_nodq();
}