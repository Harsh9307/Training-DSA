#include<bits/stdc++.h>
using namespace std;

int main(){
    stack<int> s;
    for(int i=1;i<=5;i++)
    {
        s.push(i);
    }
    while(s.size()!=0){
        cout<<s.top()<<endl;
        s.pop();
    }
    return 0;
}