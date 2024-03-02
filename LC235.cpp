class Solution {
    void traversal(TreeNode* node,TreeNode* p,TreeNode* q,vector<TreeNode*>&l){
        if (node==NULL){
            return;
        }
        if(node->val==p->val|| node->val==q->val){
            l.push_back(node);
            return;
        }
        else if((node->val>p->val && node->val<q->val)||(node->val<p->val && node->val>q->val)){
            l.push_back(node);
            return;
        }
        else if(node->val>p->val && node->val>q->val){
            traversal(node->left,p,q,l);
        }
        else{
            traversal(node->right,p,q,l);
        }
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> l;
        traversal(root,p,q,l);
        for(int i=0;i<l.size();i++){
            return l[i];
        }
        return root;
    }
};
