class Solution {
    private:
    void traversal(TreeNode *node,vector<int> &l){
        if(node==NULL){
            return;
        }
        traversal(node->left,l);
        l.push_back(node->val);
        traversal(node->right,l);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        vector<int> l;
        traversal(root,l);
        int i,j;
        int minimum=100000000;
        for(i=0;i<l.size();i++){
            for(j=i+1;j<l.size();j++){
                if(abs(l[i]-l[j])<minimum){
                    minimum=abs(l[i]-l[j]);
                }
            }
        }
        return minimum;
    }
};
