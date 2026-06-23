class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string a = "123456789";

        int low_d = to_string(low).size();
        int high_d = to_string(high).size();

        vector<int> res;

        for(int len = low_d; len <= high_d; len++) {
            for(int i = 0; i <= 9 - len; i++) {
                int num = stoi(a.substr(i, len));

                if(num >= low && num <= high) {
                    res.push_back(num);
                }
            }
        }

        return res;
    }
};