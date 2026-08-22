class Solution {
public:
    int minInsertions(string s) {
          string s1 = s;

        reverse(s1.begin(), s1.end());

        int n = s.length();

        vector<vector<int>> dp(
            n + 1,
            vector<int>(n + 1, 0)
        );

        for(int i = n - 1; i >= 0; i--) {

            for(int j = n - 1; j >= 0; j--) {

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

        return s.length() - dp[0][0];
        
    }
};