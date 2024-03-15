#include<bits/stdc++.h>
using namespace std;

void print(int s,int e)
{
    if(e>s) return;
    cout<<s<<endl;
    print(s-1,e);
    cout<<s<<endl;
}
int main(){
    print(5,1);
    return 0;
}