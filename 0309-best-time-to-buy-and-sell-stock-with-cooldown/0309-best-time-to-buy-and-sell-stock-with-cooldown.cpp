class Solution {
public:
    int f(int ind, int buy, int cool, vector<int>& prices, int n,
          vector<vector<vector<int>>>& dp) {

        if (ind >= n)
            return 0;

        if (dp[ind][buy][cool] != -1)
            return dp[ind][buy][cool];

        if (cool == 1)
            return dp[ind][buy][cool] = f(ind + 1, buy, 0, prices, n, dp);

        if (buy == 1) {
            return dp[ind][buy][cool] =
                max(-prices[ind] + f(ind + 1, 0, 0, prices, n, dp),
                    f(ind + 1, 1, 0, prices, n, dp));
        }

        return dp[ind][buy][cool] =
            max(prices[ind] + f(ind + 1, 1, 1, prices, n, dp),
                f(ind + 1, 0, 0, prices, n, dp));
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(2, vector<int>(2, -1)));

        return f(0, 1, 0, prices, n, dp);
    }
};