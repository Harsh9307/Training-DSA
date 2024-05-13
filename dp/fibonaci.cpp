#include<bits/stdc++.h>
using namespace std;

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
int main(){
    int n;
    cin>>n;

    int ans = Fib(n);
    cout<<ans<<endl;
    return 0;
}