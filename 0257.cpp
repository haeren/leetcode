class Solution
{
    void dfs(TreeNode* root, vector<int>& path, vector<string>& paths)
    {
        if (root == NULL) return;
        
        if (root->left == NULL and root->right == NULL)
        {
            string str = "";
            
            for (int i = 0; i < path.size(); i++)
            {
                str.append(to_string(path[i]));
                str.append("->");
            }
            
            str.append(to_string(root->val));
            paths.push_back(str);
            return;
        }
        
        path.push_back(root->val);
        dfs(root->left, path, paths);
        dfs(root->right, path, paths);
        path.pop_back();
    }
    
public:
    vector<string> binaryTreePaths(TreeNode* root)
    {
        vector<int> path;
        vector<string> paths;
        
        dfs(root, path, paths);
        return paths;
    }
};