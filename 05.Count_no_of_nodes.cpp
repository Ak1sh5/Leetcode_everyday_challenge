//15th Nov 2022 level easy only
//TC:less than O(n) SC: O(n)
//We can apply just bfs or dfs and travese all nodes giving O(n) tc but this is slightly better

int countNodes(TreeNode* root) {
    if(root == NULL) {
        return 0;
    }
    int left = 0, right = 0;
    TreeNode *leftNode = root, *rightNode = root;
    while(leftNode != NULL) {
        left++;
        leftNode = leftNode->left;
    }
    
    while(rightNode != NULL) {
        right++;
        rightNode = rightNode->right;
    }
    
    if(left == right) {
        return pow(2,right) - 1;
    }
    
    return 1 + countNodes(root->left) + countNodes(root->right);
}
};
