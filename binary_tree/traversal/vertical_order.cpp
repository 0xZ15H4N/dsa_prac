#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*

The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. There may be multiple TreeNodes in the same row and same column. In such a case, sort these TreeNodes by their values.

Return the vertical order traversal of the binary tree.

Input: root = [3,9,20,null,null,15,7]
Output: [[9],[3,15],[20],[7]]
Explanation:
Column -1: Only TreeNode 9 is in this column.
Column 0: TreeNodes 3 and 15 are in this column in that order from top to bottom.
Column 1: Only TreeNode 20 is in this column.
Column 2: Only TreeNode 7 is in this column.

*/

class TreeNode{
    public:
        int val;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int data){
            this->val = data;
            this->left = NULL;
            this->right = nullptr;
        }
        ~TreeNode(){
            this->left = nullptr;
            this->right = nullptr;
        }
};


    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // horizontal distance , level, value
        map<int, map<int, vector<int>>> TreeNodes;
        queue<pair<TreeNode*, pair<int, int>>> q;
        vector<vector<int>> ans;

        if (root == NULL) {
            return ans;
        }
        q.push(make_pair(root, make_pair(0, 0)));
        while (!q.empty()) {
            pair<TreeNode*, pair<int, int>> temp = q.front();
            q.pop();
            TreeNode* frontTreeNode = temp.first;
            int hd = temp.second.first;
            int lvl = temp.second.second;
            TreeNodes[hd][lvl].push_back(frontTreeNode->val);

            if (frontTreeNode->left) {
                q.push(
                    make_pair(frontTreeNode->left, make_pair(hd - 1, lvl + 1)));
            }

            if (frontTreeNode->right) {
                q.push(make_pair(frontTreeNode->right,
                                 make_pair(hd + 1, lvl + 1)));
            }
        }
        for (auto& i : TreeNodes) {
            vector<int> col;
            for (auto& j : i.second) {
                auto& v = j.second;
                sort(v.begin(), v.end()); // important
                for (int x : v)
                    col.push_back(x);
            }
            ans.push_back(col);
        }

        return ans;
    }