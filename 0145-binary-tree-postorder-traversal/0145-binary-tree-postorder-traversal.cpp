class Solution {
public:
    void postorder(TreeNode* root, vector<int>& ans) {
        // Base case: If the node does not exist, stop.
        if (root == nullptr) {
            return;
        }

        // Step 1: Traverse the left subtree.
        postorder(root->left, ans);

        // Step 2: Traverse the right subtree.
        postorder(root->right, ans);

        // Step 3: Visit the root.
        ans.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;

        postorder(root, ans);

        return ans;
    }
};