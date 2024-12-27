class Solution {
public:
    int minimumOperations(TreeNode* root) {
        if (!root) return 0;

        queue<TreeNode*> q;
        q.push(root);
        int totalOperations = 0;

        while (!q.empty()) {
            int size = q.size();
            vector<int> levelValues;

            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                levelValues.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            totalOperations += countMinSwaps(levelValues);
        }

        return totalOperations;
    }

private:
    int countMinSwaps(vector<int>& values) {
        vector<pair<int, int>> indexedValues;
        for (int i = 0; i < values.size(); ++i) {
            indexedValues.emplace_back(values[i], i);
        }

        sort(indexedValues.begin(), indexedValues.end());

        vector<bool> visited(values.size(), false);
        int swaps = 0;

        for (int i = 0; i < indexedValues.size(); ++i) {
            if (visited[i] || indexedValues[i].second == i) continue;

            int cycleSize = 0;
            int j = i;

            while (!visited[j]) {
                visited[j] = true;
                j = indexedValues[j].second;
                cycleSize++;
            }

            if (cycleSize > 1) swaps += cycleSize - 1;
        }

        return swaps;
    }
};
