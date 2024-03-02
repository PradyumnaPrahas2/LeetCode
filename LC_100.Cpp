class Solution {
    private:
    void check(TreeNode* LHS,TreeNode* RHS,vector<int> &l){
        if(LHS==NULL && RHS!=NULL){
            l.push_back(0);
            return ;
        }
        else if(LHS!=NULL && RHS==NULL){
            l.push_back(0);
            return;
        }
        else if(LHS==NULL && RHS==NULL){
            return;
        }
        if(LHS->val!=RHS->val){
            l.push_back(0);
        }
        check(LHS->left,RHS->left,l);
        check(LHS->right,RHS->right,l);
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> l;
        check(p,q,l);
        if(l.size()!=0){
            return false;
        }
        return true;
    }
};
