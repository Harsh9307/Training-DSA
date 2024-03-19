#include<bits/stdc++.h>
using namespace std;

int findCount(string str)
{
    int cnt =0;
    stack<char> st;
    for(int i =0;i<str.size();i++)
    {
        if(str[i]=='(') st.push(str[i]);
        else if(str[i]==')' && st.size()!=0) 
        {
            st.pop();
            cnt++;
        }
    }
    return cnt;
}

int main(){
    stack<int> st;
    string paren =")))(";
    int count=findCount(paren);
    cout<<count<<endl;
    return 0;
}