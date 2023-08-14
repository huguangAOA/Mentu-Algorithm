class Solution {
public:
    void update(string &s, unordered_map<string, int> &indeg, unordered_map<string, unordered_set<string>> &g) {
        for (auto x : g[s]) {
            indeg[x] -= 1;
            if (indeg[x] == 0) update(x, indeg, g);
        }
        return ;
    }
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, int> indeg;
        unordered_map<string, unordered_set<string>> g;
        int n = recipes.size();
        for (int i = 0; i < n; i++) {
            indeg[recipes[i]] = ingredients[i].size();
            for (auto x : ingredients[i]) {
                g[x].insert(recipes[i]);
            }
        }
        for (auto x : supplies) {
            indeg[x] = 0;
            update(x, indeg, g);
        }
        vector<string> ret;
        for (auto x : recipes) if (indeg[x] == 0) ret.push_back(x); 
        return ret;
    }
};