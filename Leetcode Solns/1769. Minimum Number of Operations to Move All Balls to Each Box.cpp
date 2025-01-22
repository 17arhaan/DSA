class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> result(n, 0);
        
        int count = 0, operations = 0;
        for (int i = 0; i < n; ++i) {
            result[i] += operations;
            count += (boxes[i] == '1');
            operations += count;
        }
        
        count = 0;
        operations = 0;
        for (int i = n - 1; i >= 0; --i) {
            result[i] += operations;
            count += (boxes[i] == '1');
            operations += count;
        }
        
        return result;
    }
};
