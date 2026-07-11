using ll = long long;

class Solution {
public:
    ll rec(int i, string &s) {
        if (i == s.length()) {
            return 1;
        }

        int digit = s[i] - '0';
        ll ans = 0;

        ll b = 1;

        for (int j = i + 1; j < s.length(); j++) {
            b *= 9;
        }


        for (int j = 1; j < digit; j++) {
            ans += b;
        }
        if (digit == 0) {
            return ans;
        }
        ans += rec(i + 1, s);

        return ans;
    }

    long long countDistinct(long long n) {
        int dig = 0;
        ll a = n;

        while (a > 0) {
            a /= 10;
            dig++;
        }

        ll ans = 0;
        ll product = 1;

        for (int i = 1; i <= dig - 1; i++) {
            product *= 9;
            ans += product;
        }

        string s = to_string(n);
        ans += rec(0, s);

        return ans;
    }
};