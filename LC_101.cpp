class Solution {
    private:
    void check(TreeNode *Nodel,TreeNode *Noder,vector<int> &l){
        if(Nodel!=NULL && Noder==NULL){
            l.push_back(1);
            return;
        }
        if(Nodel==NULL && Noder!=NULL){
            l.push_back(1);
            return;
        }
        if(Nodel==NULL && Noder==NULL){
            return ;
        }
        if(Nodel->val!=Noder->val){
            l.push_back(1);
        }
        check(Nodel->right,Noder->left,l);
        check(Nodel->left,Noder->right,l);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL){
            return false;
        }
        if(root->left==NULL && root->right!=NULL){
            return false;
        }
        if(root->left!=NULL && root->right==NULL){
            return false;
        }
        if(root->left==NULL && root->right==NULL){
            return true;
        }
        if(root->left->val!=root->right->val){
            return false;
        }
        vector<int> l;
        check(root->left,root->right,l);
        if(l.size()>0){
            return false;
        }
        return true;
    }
};
