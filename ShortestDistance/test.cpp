#include <iostream>
using namespace std;
int main(){
    int d[14][14];
    fill(&d[0][0],&d[0][0]+14*14,2);
    cout<<d[1][15];
}