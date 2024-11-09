#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> current;

        dfs(0, current, 0, target, candidates, res);
        return res;
    }

private:
    void dfs(int i, vector<int>& current, int total, int target, vector<int>& candidates, vector<vector<int>>& res) {
        if (total == target) {
            res.push_back(current);
            return;
        }
        
        if (i >= candidates.size() || total > target) {
            return;
        }

        current.push_back(candidates[i]);
        dfs(i, current, total + candidates[i], target, candidates, res);
        current.pop_back();

        dfs(i+1, current, total, target, candidates, res);
    }
};
