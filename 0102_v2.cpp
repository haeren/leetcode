class Solution
{
    void dfs(TreeNode* root, int level, vector<vector<int>>& result)
    {
        if (root == NULL) return;
        
        if (level >= result.size())
            result.push_back({root->val});
        else
            result[level].push_back(root->val);
        
        dfs(root->left, level+1, result);
        dfs(root->right, level+1, result);
    }
    
public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> result;
        dfs(root, 0, result);
        return result;
    }
};