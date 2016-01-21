#include <cstddef>
#include <iostream>

using std::cout;


struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	public:
		ListNode* oddEvenList(ListNode* head) {
			ListNode* previousNode = NULL;
			ListNode* nextNode = head->next;
			ListNode* currentNode = head;
			ListNode* evenHead = head->next;
			int cnt = 1;
			while (nextNode != NULL){
				previousNode = currentNode;
				currentNode->next = nextNode->next;
				currentNode = nextNode;
				nextNode = nextNode->next;
                        }
			if (cnt % 2 == 0) previousNode->next = evenHead;
			else currentNode->next = evenHead;

			return head;
		};
};

int main(){

	ListNode* node = new ListNode(1);
	ListNode* head = node;


	for (int i=2; i <= 5; ++i){
		ListNode* current = new ListNode(i);
		node->next = current;
		node = current;
	}
	Solution test;

	node = test.oddEvenList(head);
	while (node != NULL){
		cout << node->val << " ->";
		node = node->next;
	}
	//ListNode* head = &firstNode;
	//ListNode* currentNode = head;

	//for (int i=2; i <= 8; ++i){
	//	ListNode next(i);
	//	currentNode->next = &next;
	//	currentNode = current->next;
	//}

	//Solution.oddEvenList(head);
}
