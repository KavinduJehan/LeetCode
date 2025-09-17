#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {} // in this line we are initializing the value of the node to x and next pointer to null
}; //definition for singly-linked list.
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0); // dummy node to simplify the code. dummy node means a node with value 0 and next pointer as null. 
        ListNode* current = dummy;  // the purpose of the dummy node is to make it easier to return the head of the new list later instead of handling special cases for the head node.
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            current->next = new ListNode(sum % 10);
            current = current->next;
        }

        return dummy->next;
    }
};

// in this code we are adding two numbers represented by linked lists. Each node contains a single digit and the digits are stored in reverse order, meaning that the 1's digit is at the head of the list. The function returns a new linked list representing the sum of the two numbers.