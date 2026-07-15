class Solution {
public:

    bool isPal(string &s, int i, int j) {
        while(i < j) {
            if(s[i] != s[j]) return false;
            i++; j--;
        }
        return true;
    }

    void rec(string &s, int start,
             vector<string> &path,
             vector<vector<string>> &ans) {

        if(start == s.size()) {
            ans.push_back(path);
            return;
        }

        for(int end = start; end < s.size(); end++) {

            if(isPal(s, start, end)) {

                path.push_back(s.substr(start, end-start+1));

                rec(s, end+1, path, ans);

                path.pop_back();   
            }
        }
    }

    vector<vector<string>> partition(string s) {

        vector<vector<string>> ans;
        vector<string> path;

        rec(s, 0, path, ans);

        return ans;
    }
};
