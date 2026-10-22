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
    int fun(TreeNode* root, int &sum)
    {
        if(root == NULL)return 0;
        int rootleft = fun(root->left,sum);
        int rootright = fun(root->right,sum);
        sum += abs(rootleft - rootright);
        return rootleft + rootright + root->val;

    }
    int findTilt(TreeNode* root) {
        int sum = 0;
         fun(root, sum);
         return sum;
        
    }
};