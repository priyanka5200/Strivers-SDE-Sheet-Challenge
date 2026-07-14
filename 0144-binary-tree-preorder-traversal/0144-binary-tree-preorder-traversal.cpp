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
    vector<int> ans;
    void preOrder(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        if (root != nullptr) {
            ans.push_back(root->val);
        }

        if (root->left != nullptr) {
            preOrder(root->left);
        }
        if (root->right != nullptr) {
            preOrder(root->right);
        }
        return;
    }
    vector<int> preorderTraversal(TreeNode* root) {

        preOrder(root);

        return ans;
    }
    //tc = O(3n) n= number of nodes
};