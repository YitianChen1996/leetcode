#include "base.h"

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
	ListNode* add(ListNode *p1, ListNode *p2, int &carryIn) {
		if (p1->next == NULL && p2->next == NULL) {
			carryIn = (p1->val + p2->val) / 10;
			return new ListNode((p1->val + p2->val) % 10);
		} else {
			ListNode *nextNode = NULL, *retNode = NULL;
			nextNode = add(p1->next, p2->next, carryIn);
			int accuVal = p1->val + p2->val + carryIn;
			carryIn = accuVal / 10;
			retNode = new ListNode(accuVal % 10);
			retNode->next = nextNode;
			return retNode;
		}
	}

	void formatList(ListNode* &newL1, ListNode* &newL2) {
		ListNode *tempP1 = newL1, *tempP2 = newL2;
		int newL1Len = 0 newL2Len = 0;
		while (tempP1 != NULL) {
			newL1Len++;
			tempP1 = tempP1->next;
		}
		while (tempP2 != NULL) {
			newL2Len++;
			tempP2 = tempP2->next;
		}
		int diff = abs(newL1Len - newL2Len);
		if (diff == 0) { return; }
		ListNode *longer = (newL1Len > newL2Len) ? newL1 : newL2;
		ListNode *shorter = (newL1Len > newL2Len) ? newL2 : newL1;
		for (int i = 0; i < diff; i++) {
			ListNode *newShorterHead = new ListNode(0);
			newShorterHead->next = shorter;
			shorter = newShorterHead;
		}
		newL1 = longer;
		newL2 = shorter;
	}

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *newL1, *newL2, *ret;
		newL1 = l1;
		newL2 = l2;
		formatList(newL1, newL2);
		int carryIn = 0;
		ret = add(newL1, newL2, carryIn);
		if (carryIn != 0) {
			ListNode *temp = new ListNode(carryIn);
			temp->next = ret;
			ret = temp;
		}
		return ret;
    }
};

 int main() {
    return 0;
 }
