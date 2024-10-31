//boj1463 1로 만들기 
//topdown으로 해보기
//최대값 1000000을 주면 stack-overflow가 발생. 백준에서는 통과. 함수호출이 너무 많아서 생긴 에러.
//만약 스택변수참조가 잘못됐다면, a[3]으로 선언하고 a[4]를 참조하는 경우, stack-buffer-overflow 라고 에러가 발생한다.
#include <iostream>
#include <algorithm>
using namespace std;
int INF=987654321;
int a[1000004],n;
// int cnt; //함수호출 횟수
int go(int here){
	// cnt++;
    if (here<=1)
        return 0;
	if (a[here]!=INF)
		return a[here];
    a[here]=go(here-1)+1;
    if (here%3==0){
        a[here]= min(go(here/3)+1,a[here]);
    }
    if (here%2==0){
        a[here]= min(go(here/2)+1,a[here]);
    }
    return a[here];
}
int main(){
    cin>>n;
    fill(a,a+1000004,INF);
    cout<<go(n)<<"\n";
	// cout<<"cnt: "<<cnt<<"\n";
}