class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int i = 0; i < n; i++){
            dp[i][i] = nums[i];
        }

        for(int len = 2; len <= n; len++){
            for(int i = 0; i + len - 1 < n; i++){
                int j = i + len - 1;

                int left = nums[i] - dp[i + 1][j];
                int right = nums[j] - dp[i][j - 1];

                dp[i][j] = max(left, right);
            }
        }

        if(dp[0][n - 1] >= 0){
            return true;
        }

        return false;
    }
};