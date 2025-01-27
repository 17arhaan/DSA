#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        vector<int> indegree(n, 0), visited(n, 0), dp(n, 0);
        
        for (int i = 0; i < n; ++i)
            indegree[favorite[i]]++;

        queue<int> q;
        for (int i = 0; i < n; ++i)
            if (indegree[i] == 0)
                q.push(i);
        
        while (!q.empty()) {
            int node = q.front(); q.pop();
            visited[node] = 1;
            int next = favorite[node];
            dp[next] = max(dp[next], dp[node] + 1);
            if (--indegree[next] == 0)
                q.push(next);
        }

        int chainPairs = 0, maxCycle = 0;

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                int cycleSize = 0, curr = i;
                while (!visited[curr]) {
                    visited[curr] = 1;
                    curr = favorite[curr];
                    cycleSize++;
                }

                if (cycleSize == 2) {
                    chainPairs += dp[i] + dp[favorite[i]] + 2;
                } else {
                    maxCycle = max(maxCycle, cycleSize);
                }
            }
        }

        return max(maxCycle, chainPairs);
    }
};
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        vector<int> indegree(n, 0), visited(n, 0), dp(n, 0);
        
        for (int i = 0; i < n; ++i)
            indegree[favorite[i]]++;

        queue<int> q;
        for (int i = 0; i < n; ++i)
            if (indegree[i] == 0)
                q.push(i);
        
        while (!q.empty()) {
            int node = q.front(); q.pop();
            visited[node] = 1;
            int next = favorite[node];
            dp[next] = max(dp[next], dp[node] + 1);
            if (--indegree[next] == 0)
                q.push(next);
        }

        int chainPairs = 0, maxCycle = 0;

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                int cycleSize = 0, curr = i;
                while (!visited[curr]) {
                    visited[curr] = 1;
                    curr = favorite[curr];
                    cycleSize++;
                }

                if (cycleSize == 2) {
                    chainPairs += dp[i] + dp[favorite[i]] + 2;
                } else {
                    maxCycle = max(maxCycle, cycleSize);
                }
            }
        }

        return max(maxCycle, chainPairs);
    }
};
