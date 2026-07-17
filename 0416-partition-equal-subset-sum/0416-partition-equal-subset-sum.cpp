class Solution {
public:
    void rec(vector<int>& nums,int i,int sum,bool &ans,vector<vector<int>> &dp){
        if(sum==0){
            ans=true;
            return;
        }
        if(i>=nums.size()-1 || sum<0){
            return;
        }
        if(dp[i][sum]!=-1){
            return;
        }
        dp[i][sum]=sum-nums[i];
        rec(nums,i+1,sum-nums[i],ans,dp);
        rec(nums,i+1,sum,ans,dp);
        
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        vector<vector<int>>dp(n+1,vector<int>(sum,-1));
        if(sum&1){
            return false;
        }
        else{
            sum=sum/2;
        }
        bool ans=false;
        rec(nums,0,sum,ans,dp
        );
        return ans;
    }
};