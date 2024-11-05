// To find the maximum depth of the tree we can apply a simple recursive approach...
// Where each function call will represent a subtree which has root node called as ‘root’...
// We traverse the binary tree by a recursive function starting from the root node...
class Solution {
public:
    int maxDepth(TreeNode* root) {
        // Base case...
        // If the subtree is empty i.e. root is NULL, return depth as 0...
        if(root == NULL)
            return 0;
        // if root is not NULL, call the same function recursively for its left child and right child...
        // When the two child function return its depth...
        // Pick the maximum out of these two subtrees and return this value after adding 1 to it...
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;     // Adding 1 is the current node which is the parent of the two subtrees...
    }
};