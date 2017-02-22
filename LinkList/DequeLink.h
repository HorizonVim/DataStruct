#ifndef	_DequeLink_h_
#define	_DequeLink_h_

#include "LinkList.h"

template<class DT>
class DequeLink:public LinkList<DT>{
public:
	typedef typename LinkList<DT>::uint uint;
	virtual bool push(const DT& d);
	virtual bool pop(DT& d);

	//virtual
	LinkListNode<DT>* insert(uint id, const DT& d);
	LinkListNode<DT>* remove(uint id, DT& d);

private:
	LinkListNode<DT>* tail = nullptr;
};

//push
template<typename DT>
bool DequeLink<DT>::push(const DT& d){
	LinkListNode<DT>* new_node = new LinkListNode < DT > ;
	new_node->data = d;
	++len;
	if (empty())	head = tail = new_node;		
	else	{ 
		tail->next = new_node; 
		tail = new_node;
	}
	return true;
}
template<typename DT>
bool DequeLink<DT>::pop(DT& d){
	if (empty()) return false;
	LinkListNode<DT>* new_node =head->next ;
	d = head->data;
	delete head;
	--len;
	head = new_node;
	if (head == nullptr) tail = nullptr;
	return true;
}
template<typename DT>
LinkListNode<DT>* DequeLink<DT>::insert(uint id, const DT& d){
	if (id<1 || id>len + 1 || (id>=1&&id<=len+1&&empty())) return nullptr;

	if (id == 1){
		LinkListNode<DT>* new_node = new LinkListNode < DT > ;
		new_node->data = d;
		new_node->next = head;
		++len;
		head = new_node;
		if (empty())tail = head;
		return head;
	}
	tail = insert_one(id, d);
	return tail;
}

template<typename DT>
LinkListNode<DT>* DequeLink<DT>::remove(uint id, DT& d){
	if (id<1 || id>len + 1 || empty()) return nullptr;
	
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