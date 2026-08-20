class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n= nums.size();
        
        for(int i=n-1;i>=1;i--){
            if(nums[i-1]<nums[i]){
                int k = i;
                while(k<=n-1&& nums[i-1]<nums[k]){
                    k++;
                }
                swap(nums[k-1],nums[i-1]);
                 reverse(nums.begin() +i, nums.end());
                return;
            }
            else{
                continue;
            }
        }
        reverse(nums.begin(),nums.end());
        
    }
};