class Solution {
    private:
    void traversal(TreeNode* node,vector<TreeNode*>&l,int val){
        if(node==NULL){
            return;
        }
        if(node->val==val){
            l.push_back(node);
            return;
        }
        traversal(node->left,l,val);
        traversal(node->right,l,val);
    }
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        vector<TreeNode*> l;
        traversal(root,l,val);
        if(l.size()==0){
            return NULL;
        }
        return l[0];
    }
};
