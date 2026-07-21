class Solution {
public:
    int rec(vector<int>& nums, int target, int i, vector<vector<int>>& dp) {

    if (target < -1000 || target > 1000) {
        return 0;
    }

    if (i == nums.size()) {
        return target == 0;
    }

    if (dp[i][target + 1000] != -1) {
        return dp[i][target + 1000];
    }

    int plus = rec(nums, target - nums[i], i + 1, dp);
    int minus = rec(nums, target + nums[i], i + 1, dp);

    return dp[i][target + 1000] = plus + minus;
}
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<vector<int>> dp(nums.size(), vector<int>(2001, -1));
        return rec(nums, target, 0, dp);
    }
};