class Solution {
    private:
    void traversal(TreeNode*&node,int val,int depth,int i){
        if(node==NULL){
            return ;
        }
        if(i+1==depth){
                TreeNode*temp=node->left;
                node->left=new TreeNode(val);
                node->left->left=temp;
                TreeNode*temp2=node->right;
                node->right=new TreeNode(val);
                node->right->right=temp2;
                return;
    
        }
        traversal(node->left,val,depth,i+1);
        traversal(node->right,val,depth,i+1);
    }
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        traversal(root,val,depth,1);
        return root;
    }
};
