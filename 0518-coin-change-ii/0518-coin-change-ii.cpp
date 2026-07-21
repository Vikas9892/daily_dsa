class Solution {
public:
int rec(vector<int>& coins,int amt,int i,int sum,vector<vector<int>> &dp){
    if(sum == amt){
        return 1;
    }
    if(sum > amt || i >= coins.size()){
        return 0;
    }

    if(dp[i][sum] != -1){
        return dp[i][sum];
    }

    int take = rec(coins, amt, i, sum + coins[i], dp);
    int skip = rec(coins, amt, i + 1, sum, dp);

    return dp[i][sum] = take + skip;
}

int change(int amount, vector<int>& coins) {
    vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
    return rec(coins, amount, 0, 0, dp);
}
};