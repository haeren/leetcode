class Solution
{
public:
    vector<double> averageOfLevels(TreeNode* root)
    {           
        queue<TreeNode*> Q;
        vector<double> result;
        Q.push(root);
        
        while (!Q.empty())
        {
            double sum = 0;
            int nodes = Q.size();
            
            for (int i = 0; i < nodes; i++)
            {
                TreeNode* node = Q.front(); Q.pop();
                sum += node->val;
                
                if (node->left)
                    Q.push(node->left);

                if (node->right)
                    Q.push(node->right);
            }
            
            result.push_back(sum/nodes);
        }
                
        return result;
    }
};