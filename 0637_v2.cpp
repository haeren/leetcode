class Solution
{
public:
    vector<double> averageOfLevels(TreeNode* root)
    {   
        double sum = 0;
        int nodes = 0;
        
        queue<TreeNode*> Q;
        vector<double> result;
        Q.push(root);
        Q.push(NULL);
        
        while (!Q.empty())
        {
            TreeNode* node = Q.front(); Q.pop();
            
            if (node == NULL)
            {
                result.push_back(sum/nodes);
                sum = nodes = 0;
                if (!Q.empty())
                    Q.push(NULL);
            }
            else
            {
                sum += node->val;
                nodes++;

                if (node->left)
                    Q.push(node->left);

                if (node->right)
                    Q.push(node->right);
            }
        }
                
        return result;
    }
};