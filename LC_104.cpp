class Solution {
    private:
    void traversal(TreeNode* node,vector<int> &l,int value){
        if(node==NULL){
            l.push_back(value);
            return;
        }
        traversal(node->left,l,value+1);
        traversal(node->right,l,value+1);
    }
public:
    int maxDepth(TreeNode* root) {
        vector<int> l;
        traversal(root,l,0);
        for(int i=0;i<l.size();i++){
            cout<<l[i]<<" ";
        }
        return *max_element(l.begin(),l.end());
    }
};
