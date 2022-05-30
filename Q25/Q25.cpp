// Runtime: 11 ms, faster than 97.23% of C++ online submissions for Reverse Nodes in k-Group.
// Memory Usage: 11.5 MB, less than 32.47% of C++ online submissions for Reverse Nodes in k-Group.
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1)
            return head;
        
        ListNode *current, *last, *next;
        current = head;

        for (int i = 0; i < k - 1; i++) {
            if (!current)
                return head;
            current = current -> next;
        }
        last = head;
        head = reverseList(head, current);
        current = last -> next;


        while (1) {
            ListNode *start = current;

            if (!current)
                return head;

            for (int i = 0; i < k - 1; i++) {
                current = current -> next;
                if (!current)
                    return head;
            }

            last -> next = reverseList(start, current);
            last = start;
            current= start -> next;
        }
    }

    ListNode* reverseList (ListNode *start, ListNode *end) {
        ListNode *last, *current, *next;
        last = NULL;
        current = start;
        next = end -> next;

        while(last != end) {
            ListNode *tmp;
            tmp = current -> next;
            current -> next = last;
            last = current;
            current = tmp;
        }
        start -> next = next;
        
        return end;
    }
};

int main()
{
    Solution solution;
    vector<int> num_list{1,2,3,4,5};
    ListNode *head = new ListNode(num_list[0], NULL);
    ListNode *current = head;
    int n = 5;

    for (int i = 1; i < num_list.size(); i++){
        ListNode *new_node = new ListNode(num_list[i], NULL);
        current -> next = new_node;
        current = current -> next;
    }

    // current = solution.reverseList(head, head->next->next);
    current = solution.reverseKGroup(head, n);

    while (current){
        cout << current -> val << endl;
        current = current -> next;
    }
}