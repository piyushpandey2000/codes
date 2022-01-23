#include<bits/stdc++.h>

using namespace std;

int lcs(string a, string b, int i, int j, vector<vector<int>> &dp)
{
    if(i==0 || j==0)
        return 0;
    
    if(dp[i][j] != -1)
        return dp[i][j];
    
    if(a[i-1] == b[j-1])
        return dp[i][j] = 1+lcs(a, b, i-1, j-1, dp);
    
    return dp[i][j] = max(lcs(a, b, i-1, j, dp), lcs(a, b, i, j-1, dp));
}

string func2(string a, string b, int i, int j, vector<vector<int>> &dp)
{
    if(i==0 || j==0)
        return "";
        
    if(a[i-1] == b[j-1])
        return func2(a, b, i-1, j-1, dp)+a[i-1];
    
    if(dp[i-1][j]>dp[i][j-1])
        return func2(a, b, i-1, j, dp) + "-" + a[i-1];
        
    return func2(a, b, i, j-1, dp) + "+" + b[j-1];
}

void func(string a, string b)
{
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
    
    lcs(a, b, n, m, dp);
    
    cout<<func2(a, b, n, m, dp);
}

//XMJYAUZ
//XMJAATZ
int main()
{
    string a, b;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        func(a, b);
    }
}
