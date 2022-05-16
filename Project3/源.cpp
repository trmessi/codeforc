#include<unordered_map>
#include<unordered_set>
#include<vector>
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
    //
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