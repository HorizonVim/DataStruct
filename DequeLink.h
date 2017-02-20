#ifndef	_DequeLink_h_
#define	_DequeLink_h_

#include "LinkList.h"

template<class DT>
class DequeLink:public LinkList<DT>{
public:
	typedef typename LinkList<DT>::uint uint;
	virtual bool push(DT& d)const;
	virtual bool pop(DT& d)const;

private:
	LinkListNode<DT>* tail = nullptr;
};

//push
template<DT>
bool DequeLink<DT>::push(DT& d){
	LinkListNode<DT>* new_node = new LinkListNode < DT > ;
	new_node->data = d;
	++len;
	if (empty())	head = tail = new_node;		
	else	tail->next = new_node;
	return true;
}
template<DT>
bool DequeLink<DT>::pop(DT& d){
	if (empty()) return false;
	LinkListNode<DT>* new_node =head->next ;
	delete head;
	--len;
	head = new_node;
	if (head == nullptr) tail = nullptr;
	return true;
}
template<DT>
LinkListNode<DT>* DequeLink<DT>::insert(uint id, DT& d){
	if (id<1 || id>len + 1 || (id>=1&&id<=len+1&&empty())) return nullptr;

	if (id == 1){
		LinkListNode<DT>* new_node = new LinkListNode < DT > ;
		new_node->data = d;
		++len;
		head = new_node;
		if (empty())tail = head;
		return head;
	}
	tail = insert_one(id, d);
	return tail;
}

LinkListNode<DT>* DequeLink<DT>::remove(uint id, DT& d){
	if (id<1 || id>len + 1 empty()) return nullptr;
	
	if (id == 1){
		LinkListNode<DT>* new_node = head->next ;
		d = head->data;
		--len;
		delete head;
		head = new_node;
		return head;
	}
	tail = remove_one(id, d);
	return tail;
}

#endif