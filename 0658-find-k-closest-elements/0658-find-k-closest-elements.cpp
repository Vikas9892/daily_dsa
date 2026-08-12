class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size(), close_idx = 0;
        for (int i = 1; i < n; i++) {
            if (abs(arr[close_idx] - x) > abs(arr[i] - x)) {
                close_idx = i;
            }
        }
        int l = close_idx, r = close_idx;
        while (r - l + 1 < k) {
            if (l - 1 < 0) {
                r++;
            }
            else if (r + 1 >= n) {
                l--;
            }
            else if (abs(arr[r+1] - x) < abs(arr[l-1] - x)) {
                r++;
            }
            else {
                l--;
            }
        }
        return vector<int> (arr.begin() + l, arr.begin() + r + 1);
    }
};