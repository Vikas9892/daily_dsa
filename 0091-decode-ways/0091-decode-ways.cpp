class Solution {
    int f(int i,string &s,vector<int>&dp)
    {
        if(i>=s.size()) return 1;
        if(s[i]=='0') return 0;
        if(i==s.size()-1) return 1;
        if(dp[i]!=-1) return dp[i];

        int w=f(i+1,s,dp);
        if(s[i]<'2' || (s[i]=='2' && s[i+1]<='6'))
        {
            w+=f(i+2,s,dp);
        }
        return dp[i]=w;
    }
public:
    int numDecodings(string s) {
        int n=s.size();
        vector<int>dp(n,-1);
        return f(0,s,dp);
    }
};