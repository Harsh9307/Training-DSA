#include<bits/stdc++.h>
using namespace std;

void printAllPath(int i, int j , int x, int y,int rows ,int col,string path){
    if(i>rows || j>col) {        
        return;
    }else if(i==x && j==y){
        cout<<path<<endl;
    }

    printAllPath(i,j+1,x,y,rows,col,path+"R ");
    printAllPath(i+1,j,x,y,rows,col,path+"D ");
    


}
int main(){
    
    int starti=0,startj=0,endi=2,endj=2;
    printAllPath(starti,startj,endi,endj,3,3,"");
    return 0;
}