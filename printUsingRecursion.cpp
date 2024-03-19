d#include<bits/stdc++.h>
using namespace std;

void print(int s,int e)
{
    if(s>e) return;
    cout<<s<<endl;
    print(s+1,e);
    cout<<s<<endl;
}
int main(){
    print(1,5);
    return 0;
}