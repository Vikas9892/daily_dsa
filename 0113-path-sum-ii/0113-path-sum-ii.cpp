/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void check(TreeNode* root, int sum, int targetSum , vector<vector<int>>& ans, vector<int>&v){
        if(root == NULL) return;

        v.push_back(root->val);
        sum += root->val;

        if(root->left == NULL && root->right == NULL){ // reached the LN--?now check for target SUM
            if(sum == targetSum){
                ans.push_back(v);
            }
        }

        check(root->left, sum, targetSum, ans, v);
        check(root->right, sum, targetSum, ans, v);

        v.pop_back();
        
        
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int>v;

        check(root, 0, targetSum, ans, v);
        return ans;
    }
};