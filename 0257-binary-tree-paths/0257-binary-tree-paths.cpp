class Solution {
public:

    void find_path(TreeNode* root, string path, vector<string>& res)
    {
        if (root == NULL)
            return;

        path += to_string(root->val);

        // Leaf node
        if (root->left == NULL && root->right == NULL)
        {
            res.push_back(path);
            return;
        }

        path += "->";

        find_path(root->left, path, res);
        find_path(root->right, path, res);
    }

    vector<string> binaryTreePaths(TreeNode* root)
    {
        vector<string> res;

        if (root == NULL)
            return res;

        find_path(root, "", res);

        return res;
    }
};