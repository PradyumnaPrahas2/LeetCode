class Solution {
    private:
    void traversal(TreeNode*root,TreeNode*prev,TreeNode*grandparent,vector<int>&l){
        if(root==NULL){
            return;
        }
        if(grandparent!=NULL && prev!=NULL){
            if(grandparent->val%2==0){
            l.push_back(root->val);
        }
        }
        grandparent=prev;
        prev=root;
        traversal(root->left,prev,grandparent,l);
        traversal(root->right,prev,grandparent,l);
    }
public:
    int sumEvenGrandparent(TreeNode* root) {
        vector<int> l;
        TreeNode*prev=NULL;
        TreeNode*grandparent=NULL;
        traversal(root,prev,grandparent,l);
        int ans=0;
        for(int i:l){
            ans+=i;
        }
        return ans;
    }
};
