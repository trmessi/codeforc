#include<iostream>
#include<unordered_set>
using namespace std;
void swap(int m, int n)
{
    int temp = m;
    m = n;
    n = temp;
}

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
    
};
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* Left = head;
    ListNode* Right = head;
    ListNode dd(0, head);
    dd.next = head;
    for (int i = 0; i < n; i++)
    {
        Right = Right->next;
    }
    while (Right->next != NULL)
    {
        Left = Left->next;
        Right = Right->next;
    }
    Left->next = Left->next->next;
    Left->next->next = NULL;
    return head;
}
string s = "aabaab!bb";
int lengthOfLongestSubstring(string s) {
    unordered_set<char> myset;
    int Left = 0;
    int Right = 0;
    unsigned long long ans = 0;
    while (Right<s.size())
    {
        auto it =myset.find(s[Right]);
        if (it!=myset.end())
        {
            while (s[Right] != s[Left])
            {
                myset.erase(s[Left]);
                Left++;
            }
            myset.erase(s[Left]);
            Left++;
        }
        myset.insert(s[Right]);
        Right++;
        ans = max(ans,myset.size());
    }
    return ans;
}
int main()
{
    lengthOfLongestSubstring(s);
}