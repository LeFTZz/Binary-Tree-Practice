/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void preorder(TreeNode* node,
			  TreeNode *search,
		   	  std::vector<TreeNode*> &path,
		   	  std::vector<TreeNode*> &result,
			  int &finish){
	if (!node || finish){
		return;
	}
	path.push_back(node);
	if (node == search){
		finish = 1;
		result = path;
	}
	preorder(node->left, search, path, result, finish);
	preorder(node->right, search, path, result, finish);
	path.pop_back();
}

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        std::vector<TreeNode*> path;
        std::vector<TreeNode*> p_path;
        std::vector<TreeNode*> q_path;
        int finish = 0;
        // Search for node p and store the path in p_path
        preorder(root,p,path,p_path,finish); 
        path.clear();
        finish = 0;
        // Search for node q and store the path in q_path
        preorder(root,q,path,q_path,finish);
        // find out which path has smaller length
        int length = 0;
        if(p_path.size()<q_path.size())
            length = p_path.size();
        else
            length = q_path.size();
        // compare two paths and find the common ancester
        TreeNode* LCA = 0;
        for(int i = 0; i < length; i++){
            if(p_path[i] == q_path[i]){
                LCA = p_path[i];
            }
        }
        return LCA;
        
    }

};
