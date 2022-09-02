# Efficiently store binary tree (linked list) to an array.


One method which I like is to store the preorder traversal, but also include the 'null' nodes in there. Storing the 'null' nodes removes the need for also storing the inorder of the tree.

Some advantages of this method

You can do better storage than pre/post + inorder method in most practical cases.
Serialization just takes one traversal
Deserialization can be done in one pass.
The inorder traversal can be gotten in one pass without constructing the tree, which might be useful if the situation calls for it.
For example say you had a binary tree of 64 bit integers, you can store an extra bit after each node saying whether the next is a null node or not (the first node is always the root). Null nodes, you can represent by a single bit.

So if there are n nodes, the space usage would be 8n bytes + n-1 indicator bits + n+1 bits for null nodes = 66*n bits.

In the pre/post + inorder you will end up using 16n bytes= 128*n bits.

So you save a space of 62*n bits over this pre/post + inorder method.

Consider the tree
```

       100
      /   \
     /     \
    /       \
   10       200
  / \       /  \
 .   .     150  300
          / \    / \
         .   .   .  .
where the '.' are the null nodes.
```

You will serialize it as 100 10 . . 200 150 . . 300 . .

Now each (including subtrees) 'preorder traversal with null' has the property that number of null nodes = number of nodes + 1.

This allows you to create the tree, given the serialized version in one pass, as the first node is the root of the tree. Nodes that follow are the left subtree followed by right, which can be viewed to be like this:

100 (10 . .) (200 (150 . .) (300 . .))
To create the inorder traversal, you use a stack and push when you see a node and pop (onto a list) when you see a null. The resulting list is the inorder traversal (a detailed explanation for this can be found here: C++/C/Java: Anagrams - from original string to target;).
[stack_overflow](https://stackoverflow.com/a/2676849/17957276)

## I used this idea to solve (achive memory limit of) a leetcode problem which is another fun problem.

[serialize-and-deserialize binary tree](https://leetcode.com/problems/serialize-and-deserialize-binary-tree)

[my-solution](https://leetcode.com/submissions/detail/789835962/)

```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
// stackoverflow
private:
string int_to_hex(int i){
  stringstream stream;
// to write upto 1000 we need 3 bit and left bit for sign
// so 1000 = 03e8
    stream << setfill ('0') << setw(4) << hex << abs(i);
    string tem = stream.str();
    if(i<0) tem[0] = '1';
    return tem;
}
int hex_to_int(string hex){
    int val = 0,tem;
    for(int i=1;i<4;i++){
        tem = hex[i]-'0';
        if(hex[i]>='a' and hex[i]<='f'){
            tem = hex[i]-'a'+10;
        }
        val = val*16+tem;
    }
    // cout<<hex<<' '<<val<<endl;
    return hex[0]=='0'?val:-val;
}
    
TreeNode* makeTree(string &data,int &idx){
    idx++;
    if(data[idx*4]=='9') return nullptr;
    
    TreeNode* node = new TreeNode(hex_to_int(data.substr(idx*4,4)));
    
    node->left = makeTree(data,idx);
    node->right = makeTree(data,idx);
    return node;
}
public:
//     if we push 9 to denote null
    void preOrderTraverse(TreeNode* node,string &ans){
        if(node==nullptr){
            ans+="9999";
            return;
        }
        ans += int_to_hex(node->val);
        
        preOrderTraverse(node->left,ans);
        preOrderTraverse(node->right,ans);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans;
        preOrderTraverse(root,ans);
        // cout<<ans;
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
//         data coming in preorder this representation saves lots of memory
        int lower = -1;
        return makeTree(data,lower);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
```