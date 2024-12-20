// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    void Recursive (TreeNode* left, TreeNode* right, int level) {
        if (left == nullptr || right == nullptr) {
            return;
        }

        if (level % 2 != 0) {
            int temp = left->val;
            left->val = right->val;
            right->val = temp;
        }

        Recursive(left->left, right->right, level + 1);
        Recursive(left->right, right->left, level + 1);
    }
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        Recursive(root->left, root->right, 1);
        return root;
    }
};