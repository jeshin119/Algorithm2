#include <iostream>
#include <unordered_set>
#include <unordered_map>
using namespace std;
void uos(){
    unordered_set<int>s;
    s.insert(10);s.insert(30);s.insert(40);
    if (s.find(20) == s.end())
        cout<<"No 20"<<"\n";
    cout<<"size : "<<s.size()<<"\n";
    cout<<"count : "<<s.count(10)<<"\n";
    for(int i:s){
        cout<<i<<"\n";
    }
}
void uoms(){
    unordered_multiset<int> ms;
    ms.insert(10);ms.insert(10);ms.insert(20); //set과 다르게 원소중복가능.
    for(auto i:ms){
        cout<<i<<" ";
    }
    cout<<"\n";
    ms.erase(10); // 10이 모두 지워짐
    for(auto i:ms){
        cout<<i<<" ";
    }
    cout<<"\n";
    //모두 안지우려면?
    ms.insert(10);ms.insert(10);
    ms.erase(ms.find(10));//이와같이사용
    for(auto i:ms){
        cout<<i<<" ";
    }
    cout<<"\n";
}
void um(){
    unordered_map<string,int> m;
    m["a"]=10;
    m["b"]=20;
    m["c"]=30;
    for(auto e:m){
        cout<<e.first<<" "<< e.second<<"\n";
    }
}
int main(){
    ios::sync_with_stdio(NULL);cin.tie(0);cout.tie(0);
    um();
}