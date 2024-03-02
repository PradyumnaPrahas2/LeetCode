class Solution {
    private:
    void insert_function(TreeNode* &Node,int value){
    if(Node==NULL){
        TreeNode * newNode=new TreeNode;
        newNode->val=value;
        newNode->left=NULL;
        newNode->right=NULL;
        Node=newNode;
        cout<<value;
        cout<<" Node inserted successfully"<<endl;
        return ;
    }
    else{
    if(value>Node->val){
        cout<<value<<" "<<Node->val<<" ";
         insert_function(Node->right,value);
    }
    else{
        cout<<value<<" "<<Node->val<<" ";
        insert_function(Node->left,value);
    }}
}
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
    insert_function(root,val);
    return root;
    }
};
