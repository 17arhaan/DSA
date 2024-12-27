class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        dfs(root, 0, result);
        return result;
    }

private:
    void dfs(TreeNode* node, int depth, vector<int>& result) {
        if (!node) return;
        if (depth == result.size()) result.push_back(node->val);
        else result[depth] = max(result[depth], node->val);
        dfs(node->left, depth + 1, result);
        dfs(node->right, depth + 1, result);
    }
};
