/*
1. 완탐으로하면 3^30
2. 실제로 문자열을 만들필요는 없고 아닌가? 실제로 만들어야 개수를 파악할 수 있는건가?
실제로 만드는 순간 dp배열만큼의 크기를 쓰고읽기를 하니 이건 안될 거 같고
그럼 문자열을 만들지 않고 어떻게 하지?
예시를 들어보면
3개일때 최대 가능한 경우는 이 개수 이하일때를 포함하는지?
처음은 무조건 W 끝은 무조건 H.
1개일경우는 경우의수가 한가지. 
2개일경우는 트리로 경우의 수를 생각하면 1개일 경우를 포함해서 1+1.
3개일경우는 2개일 경우 1+(dp[2]+dp[2]);
4개일경우는 1+(dp[3]+dp[3]) : 

3. 로직 어떻게?
기저사례, 메모리제이션, 초기화, 로직
*/
#include <bits/stdc++.h>
using namespace std;
int n,dp[31];
int h(int here){
    if (here<0){
        return dp[here];
    }
    int& ret=dp[here];
    if (ret)
        return ret;
    ret = h(here-1) + 
}
int main(){
    ios_base::sync_with_stdio(0);
    while (true){
        cin>>n;
        if (!n){
            cout<<"0\n";
            return 0;
        }
        if (dp[n]){
            cout<<dp[n]<<"\n";
            continue;
        }
        cout<<h()<<"\n";
    }
}