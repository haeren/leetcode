class Solution
{
public:
    int maxLevelSum(TreeNode* root)
    {        
        int maxSum = INT_MIN;
        int maxLevel = -1;
        int level = 0;
        queue<TreeNode*> Q;
        Q.push(root);
                
        while (!Q.empty())
        {
            double sum = 0;
            int nodes = Q.size();
            level++;
            
            for (int i = 0; i < nodes; i++)
            {
                TreeNode* node = Q.front(); Q.pop();
                sum += node->val;
                
                if (node->left)
                    Q.push(node->left);

                if (node->right)
                    Q.push(node->right);
            }
            
            if (sum > maxSum)
            {
                maxSum = sum;
                maxLevel = level;
            }
        }
                
        return maxLevel;
    }
};