//Copyright (c) 2018 Tony Chen. All rights reserved.
/*#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/
class Solution {
public:
    void Mirror(TreeNode *pRoot) {
        if(pRoot == NULL)return;
        
        //exchange left node and right node 
        TreeNode *temp = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = temp;
        
        //traverse
        Mirror(pRoot->left);
        Mirror(pRoot->right);
    }
};
```
Python代码如下：
```python
# Copyright (c) 2018 Tony Chen. All rights reserved.
# -*- coding:utf-8 -*-
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    # 返回镜像树的根节点
    def Mirror(self, root):
        if(root == None):return root
        root.left, root.right = root.right, root.left;
        Solution.Mirror(self, root.left)
        Solution.Mirror(self, root.right)
```
