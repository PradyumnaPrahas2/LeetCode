class Solution {
    private:
    void traversal(TreeNode*&root){
        if(root==NULL){
            return;
        }
        vector<int> l;
        vector<int> r;
        if(root->left!=NULL && root->right!=NULL){
            traversal2(root->left,l);
            traversal2(root->right,r);
            int left=accumulate(l.begin(),l.end(),0);
            int right=accumulate(r.begin(),r.end(),0);
            root->val=abs(left-right);
        }
        else if(root->left!=NULL){
            traversal2(root->left,l);
            int left=accumulate(l.begin(),l.end(),0);
            root->val=abs(left);
        }
        else if(root->right!=NULL){
            traversal2(root->right,r);
            int right=accumulate(r.begin(),r.end(),0);
            root->val=abs(right);
        }
        else{
            root->val=0;
        }
        traversal(root->left);
        traversal(root->right);
    }
    void traversal2(TreeNode *root,vector<int>&l){
        if(root==NULL){
            return;
        }
        l.push_back(root->val);
        traversal2(root->left,l);
        traversal2(root->right,l);
    }
public:
    int findTilt(TreeNode* root) {
        traversal(root);
        vector<int> l;
        traversal2(root,l);
        for(int v:l){
            cout<<v<<" ";
        }
        return accumulate(l.begin(),l.end(),0);
    }
};
