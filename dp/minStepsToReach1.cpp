#include<bits/stdc++.h>
using namespace std;

int find1(int n)
{
    
    if(n==1) return 0;
    int sp1=INT_MAX,sp2=INT_MAX,sp3=INT_MAX;
    if(n%2==0){
        sp1=find1(n/2)+1;
    } 
    else{
        sp2 =find1(n+1)+1;
        sp3 =find1(n-1)+1;
        }
    
    return min(min(sp2,sp3),sp1);
    

}
int find_memo(int n,vector<int> &dp)
{
    
    int sp1=INT_MAX,sp2=INT_MAX,sp3=INT_MAX;
    if(n==1) return 0;
    if(dp[n]!=-1) return dp[n];
    if(n%2==0){
        sp1=1+find_memo(n/2,dp);
    } 
    else{
        sp2 =1+find_memo(n+1,dp);
        sp3 =1+find_memo(n-1,dp);
        }
    
    return dp[n]=min(min(sp2,sp3),sp1);    

}
int main()
{
    int n;
    cin>>n;
    int steps=0;
    //int ans=find1(n);
    vector<int> dp(n+10,-1);
    int ans = find_memo(n,dp);
    cout<<ans<<endl;
    return 0;
}