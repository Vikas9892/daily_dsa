/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
//morris traversal
    void recoverTree(TreeNode* root) {
        TreeNode* curr;
        TreeNode *first = NULL, *second = NULL;
        TreeNode *present = NULL, *last = NULL;

        while (root) {
            if (!root->left) {
                last = present;
                present = root;
                if (last && last->val > present->val) {
                    if (!first) {
                        first = last;
                    }
                    second = present;
                }
                root = root->right;
            } else {
                curr = root->left;
                while (curr->right && curr->right != root) {
                    curr = curr->right;
                }

                if (curr->right == NULL) {
                    curr->right = root;
                    root = root->left;
                }

                else {
                    curr->right = NULL;
                    last = present;
                    present = root;
                    if (last && last->val > present->val) {
                        if (!first) {
                            first = last;
                        }
                        second = present;
                    }
                    root = root->right;
                }
            }
        }

        int num=first->val;
        first->val=second->val;
        second->val=num;
    }
};