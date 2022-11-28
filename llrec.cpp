#include "llrec.h"

using namespace std;
//*********************************************
// Provide your implementation of llpivot below
//*********************************************
void llpivot (Node*& head, Node*& smaller, Node*& larger, int pivot){
	if(head == NULL){
		smaller = NULL;
		larger = NULL;
		return;
	}
	if(head->val <= pivot){
		smaller = head;
		Node* temp = head->next;
		head = NULL;
		llpivot(temp, smaller->next, larger, pivot);
	}
	else{
		larger = head;
		Node* temp = head->next;
		head = NULL;
		llpivot(temp, smaller, larger->next, pivot);

	}

}

