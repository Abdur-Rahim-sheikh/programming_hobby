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
``

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
``

You will serialize it as 100 10 . . 200 150 . . 300 . .

Now each (including subtrees) 'preorder traversal with null' has the property that number of null nodes = number of nodes + 1.

This allows you to create the tree, given the serialized version in one pass, as the first node is the root of the tree. Nodes that follow are the left subtree followed by right, which can be viewed to be like this:

100 (10 . .) (200 (150 . .) (300 . .))
To create the inorder traversal, you use a stack and push when you see a node and pop (onto a list) when you see a null. The resulting list is the inorder traversal (a detailed explanation for this can be found here: C++/C/Java: Anagrams - from original string to target;).
(stack_overflow)[https://stackoverflow.com/a/2676849/17957276]

## I used this idea to solve (achive memory limit of) a leetcode problem which is another fun problem.

(serialize-and-deserialize binary tree)[https://leetcode.com/problems/serialize-and-deserialize-binary-tree]

(my-solution)[https://leetcode.com/submissions/detail/789835962/]