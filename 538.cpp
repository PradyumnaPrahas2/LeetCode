class Solution {
    private:
    void traversal(TreeNode*root,vector<int>&l){
        if(root==NULL){
            return;
        }
        l.push_back(root->val);
        traversal(root->left,l);
        traversal(root->right,l);
    }
    void traversal2(TreeNode*&root,vector<int>l){
        if(root==NULL){
            return;
        }
        int s=root->val;
        for(int val:l){
            if(val>root->val){
                s=s+val;
            }
        }
        root->val=s;
        traversal2(root->left,l);
        traversal2(root->right,l);
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        vector<int> l;
        traversal(root,l);
        traversal2(root,l);
        return root;
    }
};
