#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<stack>
#include<string.h>
using namespace std;
  struct ListNode {
      int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* Left;
        ListNode* Right;
        Left = head;
        Right = head;
        while (Right->next != nullptr)
        {
            Right = Right->next->next;
            Left = Left->next;
        }
        return Left;
    }
};
void swap(int** m, int** n)
{
    //指针学习，
    int* temp = *m;
    *m = *n;
    *n = temp;
}
int main()
{
    int i = 3;
    int j = 4;
    int* p = i;
    int* l = j;
    swap(&p, &l);
    cout << *p;
}
bool checkInclusion(string s1, string s2) {
    unordered_map<string,int> mymap
    //然后把s1的排列放在哈希set
    int Left = 0;
    int size = s1.size();
    int Right = size - 1;
    for (int i=0;i<size;i++)
    {
        mymap.insert(s2[i]);
    }
    do
    {

    } 
    while (Right < size);
    
    }
vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> myset;
    int count = 0;
    vector<int> sum;
    if (nums1.size() > nums2.size())
    {
        for (int i = 0; i < nums1.size(); i++)
        {
            myset.insert(nums1[i]);
        }
        for (int i = 0; i < nums2.size(); i++)
        {

            if (myset.find(nums2[i]) != myset.end())
            {
                sum.push_back(nums2[i]);
                count++;
            }
        }
    }
    else
    {
        for (int i = 0; i < nums2.size(); i++)
        {
            myset.insert(nums2[i]);
        }
        for (int i = 0; i < nums1.size(); i++)
        {

            if (myset.find(nums1[i]) != myset.end())
            {
                sum.push_back(nums1[i]);
                count++
            }
        }
    }
    return sum;
}
int maxAreaOfIsland(vector<vector<int>>& grid) {
    stack<std::pair<int, int>> mystack;
    int ans = 0;

    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j] == 2)
                continue;
            if (grid[i][j] == 0)
                continue;
            mystack.push(pair<int, int>(i, j));

            while (!mystack.empty())
            {
                if (grid[i][j] == 2)
                    continue;
                if (grid[i][j] == 0)
                    continue;
                int coun = 0;
                pair<int, int> mypair = mystack.top();
                mystack.pop();
                if (grid[mypair.first - 1][mypair.second] == 1) { mystack.push(pair<int, int>(mypair.first - 1, mypair.second)); coun++; grid[mypair.first - 1][mypair.second] = 0; }
                if (grid[mypair.first + 1][mypair.second] == 1) {
                    mystack.push(pair<int, int>(mypair.first + 1, mypair.second)); coun++;  grid[mypair.first + 1][mypair.second] = 0;
                }
                if (grid[mypair.first][mypair.second - 1] == 1) {
                    mystack.push(pair<int, int>(mypair.first, mypair.second - 1)); coun++;
                    grid[mypair.first][mypair.second - 1] = 0;
                }
                if (grid[mypair.first][mypair.second + 1] == 1) {
                    mystack.push(pair<int, int>(mypair.first, mypair.second + 1)); coun++;
                    grid[mypair.first][mypair.second + 1] = 0;
                }
                ans = max(ans, (int)mystack.size());
            }
        }
    }
    return ans;
}
/*给你两棵二叉树： root1 和 root2 。

想象一下，当你将其中一棵覆盖到另一棵之上时，两棵树上的一些节点将会重叠（而另一些不会）。你需要将这两棵树合并成一棵新二叉树。合并的规则是：如果两个节点重叠，那么将这两个节点的值相加作为合并后节点的新值；否则，不为 null 的节点将直接作为新二叉树的节点。

返回合并后的二叉树。

注意 : 合并过程必须从两个树的根节点开始。

来源：力扣（LeetCode）
链接：https ://leetcode.cn/problems/merge-two-binary-trees
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    
};
TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    if (t1 == nullptr) {
        return t2;
    }
    if (t2 == nullptr) {
        return t1;
    }
    auto merged = new TreeNode(t1->val + t2->val);
    merged->left = mergeTrees(t1->left, t2->left);
    merged->right = mergeTrees(t1->right, t2->right);
    return merged;
}
//给定一个?完美二叉树?，其所有叶子节点都在同一层，每个父节点都有两个子节点。二叉树定义如下：

struct Node {
    int val;
    Node* left;
    Node* right;
    Node* next;
}
/*填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。

初始状态下，所有?next 指针都被设置为 NULL。*/

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
Node* connect(Node* root) {
    if (root == NULL) return NULL;
    connection(root);
    return root;
}
void connection(Node* root) {
    if (root->left == NULL) return;
    root->left->next = root->right;
    if (root->next != NULL) {
        root->right->next = root->next->left;
    }
    connection(root->left);
    connection(root->right);
}
/*给定一个由 0 和 1 组成的矩阵 mat?，请输出一个大小相同的矩阵，其中每一个格子是 mat 中对应位置元素到最近的 0 的距离。

两个相邻元素间的距离为 1 。

来源：力扣（LeetCode）
链接：https ://leetcode.cn/problems/01-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    
}