class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();

        vector<bool> prev(m + 1, false), curr(m + 1, false);
        prev[0] = true;
        for (int j = 1; j <= m; j++) {
            prev[j] = isAllStars(p, j);
        }

        for (int i = 1; i <= n; i++) {

            curr[0] = false;

            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                    curr[j] = prev[j - 1];
                }
                else if (p[j - 1] == '*') {
                    curr[j] = prev[j] || curr[j - 1];
                }

                else {
                    curr[j] = false;
                }
            }

            prev = curr;
        }

        return prev[m];
    }

private:
    bool isAllStars(string &p, int len) {
        for (int i = 0; i < len; i++) {
            if (p[i] != '*')
                return false;
        }
        return true;
    }
};