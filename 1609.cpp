class Solution
{
public:
    bool isOdd(int x)
    {
        return x & 0x1;
    }
    
    bool isEvenOddTree(TreeNode* root)
    {
        int index = -1; 
        queue<TreeNode*> Q;
        Q.push(root);
                
        while (!Q.empty())
        {
            index++;
            int size = Q.size();
            
            for (int i = 0; i < size; i++)
            {
                TreeNode* node = Q.front(); Q.pop();
                if (isOdd(index) and isOdd(node->val)) return false;
                if (!isOdd(index) and !isOdd(node->val)) return false;
                               
                if (i < size-1)
                {
                    TreeNode* nextNode = Q.front();                    
                    if (isOdd(index) and node->val <= nextNode->val) return false;
                    if (!isOdd(index) and node->val >= nextNode->val) return false; 
                }
                
                if (node->left) Q.push(node->left);
                if (node->right) Q.push(node->right);
            }
        }
        
        return true;
    }
};