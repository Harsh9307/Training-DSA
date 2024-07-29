#include<bits/stdc++.h>
using namespace std;
int fib(int n){
    if(n==0 || n==1) return n;

    return fib(n-1)+fib(n-2);
}
int Fib(int n)
{
    vector<int> dp(n+1,-1);
    if(n==0 ) return 0;
    if(n==1) return 1;

    if(dp[n]!=-1) return dp[n];
    int sp1=Fib(n-1);
    int sp2 = Fib(n-2);
    dp[n]=sp1+sp2;
    return dp[n];    
} 

// int FibTabulation(int n)
// {
    
//     return dp[n];
// }
int main(){
    int n;
    cin>>n;

    // int ans = Fib(n);
    
    vector<int> dp(n+1);
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    for(int i=0;i<n;i++){
        cout<<dp[i]<<" ";
    }
    cout<<endl;
    return 0;
    
}




