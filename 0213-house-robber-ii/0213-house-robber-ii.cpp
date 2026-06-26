class Solution {
public:
    int dp[105][2][2];

    void rec(vector<int>& nums, int i, int prevTaken, int firstTaken, int sum, int &ans) {
        if (i >= nums.size()) {
            ans = max(ans, sum);
            return;
        }

        if (dp[i][prevTaken][firstTaken] >= sum) {
            return;
        }

        dp[i][prevTaken][firstTaken] = sum;

        rec(nums, i + 1, 0, firstTaken, sum, ans);

        if (!prevTaken) {
            if (i == nums.size() - 1) {
                if (!firstTaken) {
                    rec(nums, i + 1, 1, firstTaken, sum + nums[i], ans);
                }
            } else {
                rec(nums, i + 1, 1, firstTaken || (i == 0), sum + nums[i], ans);
            }
        }
    }

    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }

        memset(dp, -1, sizeof(dp));

        int ans = 0;
        rec(nums, 0, 0, 0, 0, ans);

        return ans;
    }
};