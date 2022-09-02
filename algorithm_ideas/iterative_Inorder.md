# need to implement a class where function "next" will travers next node for in order, and "hasNext" will return if the inorderTraversal is completed or not

```/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
stack<TreeNode*> st;
TreeNode *cur,*tem;
public:
    BSTIterator(TreeNode* root) {
        cur = root;
    }
    
    int next() {
        while(cur!=nullptr) {
            st.push(cur);
            cur = cur->left;
        }
        tem = st.top();
        st.pop();
        cur = tem->right;
        return tem->val;
    }
    
    bool hasNext() {
        return !(cur==nullptr and st.empty());
    }
};
```