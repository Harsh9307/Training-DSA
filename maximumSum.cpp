#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> nums={3,-1,5,-100,4,2};

    int maxi =INT_MIN,sum=0;
    for(int i=0;i<nums.size();i++){
        sum+=nums[i];
        if(sum<0){
            sum=0;
        }
        maxi=max(maxi,sum);
    } 
    cout<<maxi<<endl ;
    return 0;

}

