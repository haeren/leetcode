class Solution
{
public:
    vector<int> largestValues(TreeNode* root)
    {
        vector<int> result;
        if (root == NULL) return result;
        
        queue<TreeNode*> Q;
        Q.push(root);
                
        while (!Q.empty())
        {
            int nodes = Q.size();
            int maxVal = INT_MIN;
            
            for (int i = 0; i < nodes; i++)
            {
                TreeNode* node = Q.front(); Q.pop();
                maxVal = max(maxVal, node->val);
                
                if (node->left)
                    Q.push(node->left);

                if (node->right)
                    Q.push(node->right);
            }
            
            result.push_back(maxVal);
        }
        
        return result;
    }
};