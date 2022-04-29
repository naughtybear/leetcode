#include <bits/stdc++.h>

using namespace std;
/**
  Definition for singly-linked list.*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *current_1 = l1;
        ListNode *current_2 = l2;
        ListNode *output = new ListNode((current_1 -> val + current_2->val) % 10);
        ListNode *last = output;
        int carry = (current_1 -> val + current_2->val) / 10;
        
        
        //last -> val = (current_1 -> val + current_2->val) % 10;
        //carry = (current_1 -> val + current_2->val) / 10;
        //last -> next = NULL;
        current_2 = current_2 -> next;
        current_1 = current_1 -> next;
        while(current_1 != NULL || current_2 != NULL){
            // cout << current_1 -> val << ' ' << current_2 -> val << endl;
            // getchar();
            last -> next = new ListNode(0);
            last = last -> next;
            last -> next = NULL;
            if(current_1 == NULL){
                last -> val = (current_2 -> val + carry) % 10;
                carry = (current_2 -> val + carry) / 10;
                current_2 = current_2 -> next;
            }
            else if(current_2 == NULL){
                last -> val = (current_1 -> val + carry) % 10;
                carry = (current_1 -> val + carry) / 10;
                current_1 = current_1 -> next;
            }
            else{
                last -> val = (current_1 -> val + current_2 -> val + carry) % 10;
                carry = (current_1 -> val + current_2 -> val + carry) / 10;
                current_1 = current_1 -> next;
                current_2 = current_2 -> next;
            }
        }
        if(carry > 0){
            last ->next = new ListNode(carry);
            last = last -> next;
            //last -> val = carry;
            last -> next = NULL;
        }
        return output;
    }
};

int main()
{
    ListNode *l1 = NULL;
    ListNode *l2 = NULL;
    ListNode *output = NULL;
    Solution solution;

    l1 =  (ListNode*)malloc(sizeof(ListNode));
    l1 -> val = 2;
    l1 -> next = (ListNode*)malloc(sizeof(ListNode));
    l1 -> next -> val = 4;
    l1 -> next -> next = (ListNode*)malloc(sizeof(ListNode));
    l1 -> next -> next -> val = 3;
    l1 -> next -> next -> next = NULL;

    l2 =  (ListNode*)malloc(sizeof(ListNode));
    l2 -> val = 5;
    l2 -> next = (ListNode*)malloc(sizeof(ListNode));
    l2 -> next -> val = 6;
    l2 -> next -> next = (ListNode*)malloc(sizeof(ListNode));
    l2 -> next -> next -> val = 4;
    l2 -> next -> next -> next = NULL;

    output = solution.addTwoNumbers(l1, l2);
    while (output != NULL)
    {
        cout << output -> val << endl;
        output = output -> next;
    }
    
}