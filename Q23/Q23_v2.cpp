// Runtime: 28 ms, faster than 71.77% of C++ online submissions for Merge k Sorted Lists.
// Memory Usage: 13.3 MB, less than 72.86% of C++ online submissions for Merge k Sorted Lists.
// use min heap
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

struct CustomCompare {
    bool operator() (const ListNode* x, const ListNode* y) {
        return x -> val > y -> val;
    }
};
 
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *head = NULL, *current = NULL;
        priority_queue<ListNode*, vector<ListNode*>, CustomCompare> min_heap; 

        for (int i = 0; i < lists.size(); i++) {
            if (lists[i]) {
                min_heap.push(lists[i]);
                lists[i] = lists[i] -> next;
            }
        }

        if (min_heap.empty())
            return NULL;

        head = min_heap.top();
        min_heap.pop();
        if (head -> next) {
            min_heap.push(head -> next);
        }

        current = head;
        while (!min_heap.empty()) {
            current -> next = min_heap.top();
            current = current -> next;
            min_heap.pop();
            if (current -> next) {
                min_heap.push(current -> next);
            }
        }
        
        return head;
    }
};

int main()
{
    Solution solution;
    vector<int> num_list1{1, 2, 3};
    vector<int> num_list2{2, 4, 5};
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