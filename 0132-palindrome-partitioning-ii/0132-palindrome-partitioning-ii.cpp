class Solution {
public:
    int minCut(string s) {

        int n = s.size();

        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for(int i = n - 1; i >= 0; i--) {
            for(int j = i; j < n; j++) {

                if(s[i] == s[j]) {

                    if(j - i <= 2) {
                        dp[i][j] = true;
                    }
                    else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }
            }
        }

        vector<int> cut(n, 0);

        for(int i = 0; i < n; i++) {

            if(dp[0][i]) {
                cut[i] = 0;
            }
            else {

                cut[i] = INT_MAX;

                for(int j = 0; j < i; j++) {

                    if(dp[j + 1][i]) {
                        cut[i] = min(cut[i], cut[j] + 1);
                    }
                }
            }
        }

        return cut[n - 1];
    }
};