class Solution
{
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root)
    {
        vector<vector<int>> result;
        if (root == NULL) return result;
        
        queue<TreeNode*> Q;
        Q.push(root);
                
        while (!Q.empty())
        {
            int nodes = Q.size();
            result.push_back({});
            int index = result.size() - 1;
            
            for (int i = 0; i < nodes; i++)
            {
                TreeNode* node = Q.front(); Q.pop();
                result[index].push_back(node->val);
                
                if (node->left)
                    Q.push(node->left);

                if (node->right)
                    Q.push(node->right);
            }
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};