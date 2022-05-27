// Runtime: 6 ms, faster than 85.54% of C++ online submissions for Merge Two Sorted Lists.
// Memory Usage: 14.8 MB, less than 44.29% of C++ online submissions for Merge Two Sorted Lists.
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == NULL)
            return list2;
        if (list2 == NULL)
            return list1;
        
        ListNode *head;

        if (list1 -> val <= list2 -> val){
            head = list1;
            list1 = list1 -> next;
        }
        else {
            head = list2;
            list2 = list2 -> next;
        }

        ListNode *current = head;

        while(list1 || list2) {
            if (!list1) {
                current -> next = list2;
                list2 = list2 ->next;
                current = current ->next;
                // current -> next = NULL;
            }
            else if (!list2) {
                current -> next = list1;
                list1 = list1 ->next;
                current = current ->next;
                // current -> next = NULL;
            }
            else if (list1 -> val <= list2 -> val) {
                current -> next = list1;
                list1 = list1 ->next;
                current = current ->next;
                // current -> next = NULL;
            }
            else {
                current -> next = list2;
                list2 = list2 ->next;
                current = current ->next;
                // current -> next = NULL;
            }

        }
        return head;
    }
};

int main()
{
    Solution solution;
    vector<int> num_list1{1};
    vector<int> num_list2{2};
    ListNode *head1 = new ListNode(num_list1[0], NULL);
    ListNode *head2 = new ListNode(num_list2[0], NULL);
    ListNode *current = head1;
    int n = 1;

    for (int i = 1; i < num_list1.size(); i++){
        ListNode *new_node = new ListNode(num_list1[i], NULL);
        current -> next = new_node;
        current = current -> next;
    }

    current = head2;
    for (int i = 1; i < num_list2.size(); i++){
        ListNode *new_node = new ListNode(num_list2[i], NULL);
        current -> next = new_node;
        current = current -> next;
    }

    current = solution.mergeTwoLists(head1, head2);

    while (current){
        cout << current -> val << endl;
        current = current -> next;
    }
}