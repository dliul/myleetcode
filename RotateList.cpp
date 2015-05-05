#include <iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(null)
}

class Solution {
	public:
		ListNode* rotateRight(ListNode* head, int k) {
			if (head->next == NULL) return head; 
			//ListNode *start;
			ListNode *end;
			ListNode *current;
			//start = head;
			end = head;
			current = end;
			for (int i = 0; i < k - 1 ; ++i) {
				if ( current->next != NULL )
					current = current->next;
			}
			if ( current->next == NULL) {
				current->next = head;
				head = end->next;
				end->next = NULL;
				return end->next;
			}

		}
};
