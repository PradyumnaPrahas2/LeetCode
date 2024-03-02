class Solution {
    private:
    void check_for(TreeNode* node,vector<int>&l){
        if(node==NULL){
            return;
        }
        l.push_back(node->val);
        check_for(node->left,l);
        check_for(node->right,l);
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        list<TreeNode*> l;
        vector<vector<int>> l2;
        l.push_back(root);
        vector<int> b;
        int f;
        while(l.size()!=0){
            TreeNode* node=l.front();
            b.erase(b.begin(),b.end());
            check_for(node,b);
            f=0;
            for(int val:b){
                if(val==p->val || val==q->val){
                    f++;
                }
            }
            if(f>=2){
                l2.push_back(b);
            }
            if(node->left){
                l.push_back(node->left);
            }
            if(node->right){
                l.push_back(node->right);
            }
            l.pop_front();
        }
        int x;
        x=l2[l2.size()-1][0];
        TreeNode *ans=new TreeNode;
        ans->left=NULL;
        ans->right==NULL;
        ans->val=x;
        return ans;
    }
};
