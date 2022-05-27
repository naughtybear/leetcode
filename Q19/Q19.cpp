// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Remove Nth Node From End of List.
// Memory Usage: 10.7 MB, less than 34.30% of C++ online submissions for Remove Nth Node From End of List.
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head -> next)
            return NULL;

        int total = 0;
        ListNode *current = head;
        ListNode *last = head;

        while (current) {
            total++;
            current = current -> next;
        }

        current = head;

        while (total > n) {
            total--;
            last = current;
            current = current -> next;
        }

        if (current == head)
            return head -> next;
        else 
            last -> next = current -> next;
        
        return head;
    }
};

int main()
{
    Solution solution;
    vector<int> num_list{1, 2};
    ListNode *head = new ListNode(num_list[0], NULL);
    ListNode *current = head;
    int n = 1;

    for (int i = 1; i < num_list.size(); i++){
        ListNode *new_node = new ListNode(num_list[i], NULL);
        current -> next = new_node;
        current = current -> next;
    }

    current = solution.removeNthFromEnd(head, n);

    while (current){
        cout << current -> val << endl;
        current = current -> next;
    }
}