#include "inOut.hpp"

nodeSV* SortedMerge(nodeSV* a, nodeSV* b);
void FrontBackSplit(nodeSV* source, nodeSV** frontRef, nodeSV** backRef);
void ascendingOrderName(nodeSV *&head);
void MergeSort(nodeSV** headRef);
nodeSV* SortedMerge(nodeSV* a, nodeSV* b);
void FrontBackSplit(nodeSV* source, nodeSV** frontRef, nodeSV** backRef);
nodeSV *lastNode(nodeSV *head);
nodeSV *partition(nodeSV *first, nodeSV *last);
void quickSort(nodeSV *first, nodeSV *last);

void ascendingOrderName(nodeSV *&head){
	for(nodeSV *p = head; p != NULL; p = p -> next){
		nodeSV *min = p;
		for(nodeSV *q = p -> next; q != NULL; q = q -> next){
			if(q -> value.name < min -> value.name){
				min = q;
			}
		}
		Student tmp = min -> value;
		min -> value = p -> value;
		p -> value = tmp;
	}
}

void MergeSort(nodeSV** headRef)
{
    nodeSV *head = *headRef;
    nodeSV* a;
    nodeSV* b;
 
    /* Base case -- length 0 or 1 */
    if ((head == NULL) || (head -> next == NULL)) {
        return;
    }
 
    /* Split head into 'a' and 'b' sublists */
    FrontBackSplit(head, &a, &b);
 
    /* Recursively sort the sublists */
    MergeSort(&a);
    MergeSort(&b);
 
    /* answer = merge the two sorted lists together */
    *headRef = SortedMerge(a, b);
}
 
nodeSV* SortedMerge(nodeSV* a, nodeSV* b)
{
    nodeSV* result = NULL;
 
    /* Base cases */
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);
 
    /* Pick either a or b, and recur */
    if (a -> value.pointTraining <= b -> value.pointTraining) {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    return (result);
}
 

void FrontBackSplit(nodeSV* source, nodeSV** frontRef, nodeSV** backRef)
{
    nodeSV* fast;
    nodeSV* slow;
    slow = source;
    fast = source->next;
 
    /* Advance 'fast' two nodes, and advance 'slow' one node */
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }
 
    /* 'slow' is before the midpoint in the list, so split it in two
    at that point. */
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}

nodeSV *lastNode(nodeSV *head){
	nodeSV *tmp = head;
	while(tmp != NULL && tmp -> next != NULL){
		tmp = tmp -> next;
	}
	return tmp;
}

nodeSV *partition(nodeSV *first, nodeSV *last){
	nodeSV *pivot = first;
	nodeSV *front = first;
	float tmp = 0;

	while(front != NULL && front != last){
		if(front -> value.gpa < last -> value.gpa){
			pivot = first;

			tmp = first -> value.gpa;
			first -> value.gpa = front -> value.gpa;
			front -> value.gpa = tmp;

			first = first -> next;
		}

		front = front -> next;
	}
	// change last node value to current node
	tmp = first -> value.gpa;
	first -> value.gpa = last -> value.gpa;
	last -> value.gpa = tmp;
	return pivot;
}

void quickSort(nodeSV *first, nodeSV *last){
	if(first == last) 
	    return;
	nodeSV *pivot = partition(first, last);

	if(pivot != NULL && pivot -> next != NULL)
	    quickSort(pivot -> next, last);
	
	if(pivot != NULL && first != pivot)
	    quickSort(first, pivot);
}
