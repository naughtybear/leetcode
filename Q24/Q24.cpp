// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Swap Nodes in Pairs.
// Memory Usage: 7.6 MB, less than 7.06% of C++ online submissions for Swap Nodes in Pairs.
#include<bits/stdc++.h>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head -> next)
            return head;

        ListNode *current = head;
        head = head -> next;
        current -> next = head -> next;
        head -> next = current;
        
        while (current -> next && current -> next -> next) {
            ListNode* tmp = current -> next -> next;

            current -> next -> next = tmp -> next;
            tmp -> next = current -> next;
            current -> next = tmp;
            current = current -> next -> next;
        }
        return head;
    }
};

int main()
{
    Solution solution;
    vector<int> num_list{1,2,3,4,5};
    ListNode *head = new ListNode(num_list[0], NULL);
    ListNode *current = head;
    int n = 1;

    for (int i = 1; i < num_list.size(); i++){
        ListNode *new_node = new ListNode(num_list[i], NULL);
        current -> next = new_node;
        current = current -> next;
    }

    current = solution.swapPairs(head);

    while (current){
        cout << current -> val << endl;
        current = current -> next;
    }
}