#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr1={1,1,2,3,3,4,4,4,5};
    vector<int> arr2={2,2,2,3,3,4,5,6,7};
    vector<int> temp;
    int index=0;
    int i=0,j=0;
    while(i<arr1.size() && j<arr2.size()){
        if(arr1[i]<arr2[j]){
            i++;
        }
        else if(arr1[i]==arr2[j]){
            temp.push_back(arr1[i]);
            i++;
            j++;
        }
        else{
            j++;
        }
    }

    for(int i=0;i<temp.size();i++){
        cout<<temp[i]<<" ";
    }    
    return 0;

}

