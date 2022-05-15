class Solution
{
public:
    vector<double> averageOfLevels(TreeNode* root)
    {   
        int currentLevel = 0;
        double sum = 0;
        int nodes = 0;
        
        queue<pair<TreeNode*, int>> Q;
        vector<double> result;
        Q.push({root, currentLevel});
        
        while (!Q.empty())
        {
            auto [node, level] = Q.front(); Q.pop();
            
            if (level > currentLevel)
            {
                result.push_back(sum/nodes);
                sum = nodes = 0;
                currentLevel = level;
            }
            
            sum += node->val;
            nodes++;
            
            if (node->left)
                Q.push({node->left, level+1});
            
            if (node->right)
                Q.push({node->right, level+1});
        }
        
        if (nodes > 0)
            result.push_back(sum/nodes);
        
        return result;
    }
};