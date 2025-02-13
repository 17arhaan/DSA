#include <queue>
#include <vector>
using namespace std;
class Solution {
public:
    int minOperations(vector<int>& cookies, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq(cookies.begin(), cookies.end());
        int ops = 0;
        while (pq.size() > 1 && pq.top() < k) {
            long long a = pq.top();
            pq.pop();
            long long b = pq.top();
            pq.pop();
            pq.push(a + 2 * b);
            ops++;
        }
        return (!pq.empty() && pq.top() >= k) ? ops : -1;
    }
};
