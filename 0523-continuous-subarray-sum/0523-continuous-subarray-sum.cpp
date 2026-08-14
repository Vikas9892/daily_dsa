class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size();

        if (n < 2) {
            return false;
        }

        long long sum = 0;
        mp[0] = -1;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            int rem = sum % k;

            if (rem < 0) {
                rem += k;
            }

            if (mp.find(rem) != mp.end()) {
                if (i - mp[rem] >= 2) {
                    return true;
                }
            } else {
                mp[rem] = i;
            }
        }

        return false;
    }
};