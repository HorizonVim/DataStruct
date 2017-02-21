#ifndef	_StackLink_h_
#define	_StackLink_h_

#include "List.h"

template<class DT>
class StackLink :public List < DT > {
public:
	typedef unsigned int uint;
	uint length()const{ return len; }
	DT&	getTop()const{ return head->data; }

	bool		push(const DT& d);
	bool		pop( DT& d);

private:
	uint len=0;
};

//push
template<class DT>
bool StackLink<DT>::push(const DT& d){
	LinkListNode<DT>* new_node = new LinkListNode < DT > ;
	new_node->data = d;
	new_node->next = head;
	head = new_node;
	++len;
	return true;
}

//push
template<class DT>
bool StackLink<DT>::pop( DT& d){
	if (empty())return false;
	LinkListNode<DT>* new_node = head->next ;
	d = head->data;
	delete head;
	head = new_node;
	--len;
	return true;
}




#endif