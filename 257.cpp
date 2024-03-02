class Solution {
    private:
    void traversal(TreeNode* node,vector<string>&l,string s){
        if(node==NULL){
            return;
        }
        s=s+"->"+to_string(node->val);
        if(node->left==NULL && node->right==NULL){
            string x=s.substr(2,s.length()-2);
            l.push_back(x);
        }
        traversal(node->left,l,s);
        traversal(node->right,l,s);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> l;
        traversal(root,l,"");
        return l;
    }
};
