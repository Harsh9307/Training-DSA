#include<bits/stdc++.h>
using namespace std;

int printFib(int n){
    if(n==0 ) return 0;
    if(n==1 ) return 1;
    return printFib(n-1)+printFib(n-2);
}
int main(){
    int num=printFib(10);
    cout<<num<<endl;
}