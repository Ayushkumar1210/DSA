class Solution {
public:
    int preorder_index = 0;

    TreeNode* build(vector<int>& preorder, long min_val, long max_val) {

        if (preorder_index == preorder.size())
            return nullptr;

        int val = preorder[preorder_index];

        if (val < min_val || val > max_val)
            return nullptr;

        TreeNode* root = new TreeNode(val);
        preorder_index++;

        root->left = build(preorder, min_val, root->val);
        root->right = build(preorder, root->val, max_val);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        preorder_index = 0;
        return build(preorder, LONG_MIN, LONG_MAX);
    }
};