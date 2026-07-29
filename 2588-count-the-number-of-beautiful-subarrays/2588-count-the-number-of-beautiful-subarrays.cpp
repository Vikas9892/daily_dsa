class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {

        int n = nums.size();

        unordered_map<int,int> mp;

        mp[0]++;

        int pxr = 0;

        long long ans = 0;

        for(int i = 0; i < n; i++) {

            pxr ^= nums[i];

            ans += mp[pxr]++;

        }

        return ans;
    }
};