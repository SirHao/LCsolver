//
// Created by lucas on 2020/2/15.
//


#include <zconf.h>
#include <stdbool.h>

//* Definition for a binary tree node.
  struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
 };

//no.1 二叉树的最大深度
int maxDepth(struct TreeNode* root){
    if(root==NULL) return 0;
    int sub_left=maxDepth(root->left)+1;
    int sub_right=maxDepth(root->right)+1;

    return (sub_left>sub_right)?sub_left:sub_right;
}

//no.2 验证二叉搜索树
bool isValidBST(struct TreeNode* root)
{
    struct TreeNode* search;
    struct TreeNode* stack[10000] = { NULL };
    int top;
    int button;
    int list[10000];
    int i = 0;

    if (!root)
    {
        return true;
    }
    //初始化栈
    top = button = 0;
    //搜索指针初始化
    search = root;
    do
    {
        //有左孩子就入栈
        while (search != NULL)
        {
            stack[++top] = search;
            search = search->left;
        }
        //栈不为空
        if (top != button)
        {
            //出栈
            search = stack[top--];
            //访问结果输入到顺序表里
            list[i] = search->val;
            //因为二叉搜索树中序遍历是升序输出
            //所以当当前的元素大于等于前驱则为false
            if (i >= 1 && list[i] <= list[i-1])
            {
                return false;
            }
            //顺序表index后移
            i++;
            //右进一步
            search = search->right;
        }
    } while (top != button || search != NULL); //栈空判断
    return true;
}

//no.3  对称二叉树
bool isMirror (struct TreeNode* root1,struct TreeNode* root2){
    if (root1==NULL&&root2==NULL) return true;
    else if (root1!=NULL && root2!=NULL && root1->val == root2->val)return isMirror(root1->right,root2->left)&&isMirror(root1->left,root2->right);
    else return false;
}


bool isSymmetric(struct TreeNode* root) {
    return isMirror(root,root);
}

//no.4 二叉树的层次遍历
/*
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr){
            return result;
        }
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            vector<int> tmp;
            int qLen = q.size();
            for (int i = 0; i < qLen; ++i)
            {
                TreeNode *node = q.front();
                q.pop();
                tmp.push_back(node->val);
                if (node->left){
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            result.push_back(tmp);
        }
        return result;
    }
};
 */

//no.5将有序数组转换为二叉搜索树
/*
 class Solution {
        public:
        TreeNode* sortedArrayToBST(vector<int>& nums) {
            if(nums.empty()) return NULL;

            TreeNode* root=new TreeNode(nums[nums.size()/2]);
            vector<int> vec_l=vector<int>(nums.begin(),nums.begin()+nums.size()/2);
            vector<int> vec_r=vector<int>(nums.begin()+nums.size()/2+1,nums.end());
            root->left=sortedArrayToBST(vec_l);
            root->right=sortedArrayToBST(vec_r);

            return root;
        }
};*/


