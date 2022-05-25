class Solution
{
    bool dfs(TreeNode* root, int targetSum, int pathSum)
    {
        if (root == NULL) return false;
        
        pathSum += root->val;
        
        if (root->left == NULL and root->right == NULL)
        {
            if (pathSum == targetSum) return true;
            else return false;
        }
        
        if (dfs(root->left, targetSum, pathSum)) return true;
        if (dfs(root->right, targetSum, pathSum)) return true;
        return false;
    }
    
public:
    bool hasPathSum(TreeNode* root, int targetSum)
    {
        if (root == NULL) return false;
        return dfs(root, targetSum, 0);
    }
};