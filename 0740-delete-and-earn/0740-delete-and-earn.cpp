class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<pair<int,int>> v;

        for (int x : nums) {
            if (v.empty() || v.back().first != x) {
                v.push_back({x, x});
            } else {
                v.back().second += x;
            }
        }

        int n = v.size();
        int ans = 0;

        int i = 0;
        while (i < n) {

            vector<int> a;
            a.push_back(v[i].second);

            int j = i + 1;
            while (j < n && v[j].first == v[j - 1].first + 1) {
                a.push_back(v[j].second);
                j++;
            }

            int prev2 = 0;
            int prev1 = a[0];

            for (int k = 1; k < a.size(); k++) {
                int cur = max(prev1, prev2 + a[k]);
                prev2 = prev1;
                prev1 = cur;
            }

            ans += prev1;
            i = j;
        }

        return ans;
    }
};