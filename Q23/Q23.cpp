// Runtime: 1436 ms, faster than 5.02% of C++ online submissions for Merge k Sorted Lists.
// Memory Usage: 13 MB, less than 86.26% of C++ online submissions for Merge k Sorted Lists
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return NULL;
        }
        else if (lists.size() == 1) {
            return lists[0];
        }

        ListNode *head;
        int min_index, min_val = INT_MAX;
        int remain = lists.size();

        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] == NULL){
                remain--;
                continue;
            }
            if (lists[i] -> val < min_val) { 
                min_index = i;
                min_val = lists[i] -> val;
            }
        }
        if (!remain)
            return NULL;
        head = lists[min_index];
        lists[min_index] = lists[min_index] -> next;
        if (lists[min_index] == NULL)
            remain--;

        ListNode *current = head;
        while(remain) {
            min_val = INT_MAX;

            for (int i = 0; i < lists.size(); i++) {
                if (lists[i] == NULL)
                    continue;
                if (lists[i] -> val < min_val) { 
                    min_index = i;
                    min_val = lists[i] -> val;
                }
            }
            current -> next = lists[min_index];
            current = current -> next;
            lists[min_index] = lists[min_index] -> next;
            if (lists[min_index] == NULL)
                remain--;
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

    vector<ListNode*> head;
    head.push_back(head1);
    head.push_back(head2);

    current = solution.mergeKLists(head);

    while (current){
        cout << current -> val << endl;
        current = current -> next;
    }
}