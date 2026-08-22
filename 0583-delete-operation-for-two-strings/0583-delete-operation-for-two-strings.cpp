class Solution {
public:
    int minDistance(string s, string s1) {

        int n1 = s.length();
        int n2= s1.length();
        vector<vector<int>> dp(
            n1 + 1,
            vector<int>(n2 + 1, 0)
        );

        for(int i = n1 - 1; i >= 0; i--) {

            for(int j = n2 - 1; j >= 0; j--) {

                if(s[i] == s1[j]) {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                }
                else {
                    dp[i][j] = max(
                        dp[i + 1][j],
                        dp[i][j + 1]
                    );
                }
            }
        }
        cout<<dp[0][0]<<endl;
        return (s.length()-dp[0][0]+s1.length()-dp[0][0]);
    }
};