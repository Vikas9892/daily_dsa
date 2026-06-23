class Solution {
public:
    int minNumberOfFrogs(string cr) {
        vector<int> cnt(5, 0);
        int cur = 0;
        int ans = 0;

        for(char c : cr) {
            if(c == 'c') {
                cnt[0]++;
                cur++;
                ans = max(ans, cur);
            }
            else if(c == 'r') {
                if(cnt[0] == 0) {
                    return -1;
                }
                cnt[0]--;
                cnt[1]++;
            }
            else if(c == 'o') {
                if(cnt[1] == 0) {
                    return -1;
                }
                cnt[1]--;
                cnt[2]++;
            }
            else if(c == 'a') {
                if(cnt[2] == 0) {
                    return -1;
                }
                cnt[2]--;
                cnt[3]++;
            }
            else if(c == 'k') {
                if(cnt[3] == 0) {
                    return -1;
                }
                cnt[3]--;
                cur--;
            }
            else {
                return -1;
            }
        }

        if(cur != 0) {
            return -1;
        }

        return ans;
    }
};