class Solution {
public:
    static vector<string> partitionString(string& s) {
        unordered_set<string> seen;
        string t="";
        vector<string> ans;
        for(char c: s){
            t+=c;
            if (!seen.count(t)){
                seen.insert(t);
                ans.push_back(t);
                t="";
            }
        }
        return ans;
    }
};