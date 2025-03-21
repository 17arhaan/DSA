class Solution {
    public:
        vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
            unordered_map<string, vector<string>> graph; // ingredient -> list of recipes that depend on it
            unordered_map<string, int> indegree; // recipe -> number of missing ingredients
            unordered_set<string> available(supplies.begin(), supplies.end());
            vector<string> result;
            for (int i = 0; i < recipes.size(); ++i) {
                indegree[recipes[i]] = ingredients[i].size();
                for (const string& ing : ingredients[i]) {
                    graph[ing].push_back(recipes[i]);
                }
            }
            queue<string> q;
            for (const string& supply : supplies) {
                q.push(supply);
            }
            while (!q.empty()) {
                string item = q.front();
                q.pop();
                for (const string& recipe : graph[item]) {
                    indegree[recipe]--;
                    if (indegree[recipe] == 0) {
                        result.push_back(recipe);
                        q.push(recipe); 
                    }
                }
            }
    
            return result;
        }
    };
    