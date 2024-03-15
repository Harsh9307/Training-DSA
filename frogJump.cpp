#include<bits/stdc++.h>
using namespace std;

void jump(int steps, string path)
{
    if(steps==0){
        cout<<path<<endl;
        return;
    }else if( steps <0) return;

    jump(steps-1,path+to_string(1));
    jump(steps-2,path+to_string(2));
    jump(steps-3,path+to_string(3));
}
int main(){
    jump(5,"");
    return 0;
}