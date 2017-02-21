#ifndef	_LinkList_h_
#define	_LinkList_h_

#include "List.h"

template<class DT>
class LinkList :public List < DT > {
public:
	typedef	unsigned int	uint;

	uint	length()const{ return len; }

	LinkListNode<DT>* locate(uint id);
	LinkListNode<DT>* setData(uint id, const DT& d);
	LinkListNode<DT>* insert_one(uint id, const DT& d);
	LinkListNode<DT>* remove_one(uint id, DT& d);

	virtual bool push(const DT& d);
	virtual bool pop(DT& d);
	virtual LinkListNode<DT>* insert(uint id, const DT& d) = 0;
	virtual LinkListNode<DT>* remove(uint id, DT& d) = 0;
	
protected:
	uint	len=0;
};

//locate
template<typename DT>
LinkListNode<DT>* LinkList<DT>::locate(uint id){
	LinkListNode<DT>* cur = head;
	uint i = id;
	while (--i)
		cur = cur->next;
	return cur;
}

//setData
template<typename DT>
LinkListNode<DT>* LinkList<DT>::setData(uint id, const DT& d){
	if (empty() && id==1){
		LinkListNode<DT>* new_node = new LinkListNode < DT > ;
		new_node->data = d;
		head = new_node;
		++len;
		return head;
	}
	LinkListNode* cur = locate(id);
	cur->data = d;
	return cur;
}

//push
template<class DT>
bool LinkList<DT>::push(const DT& d){
	if (empty()){
		LinkListNode<DT>* new_node = new LinkListNode < DT > ;
		new_node->data = d;
		head = new_node;
		++len;
		return true;
	}else
		insert_one(len+1, d);
	return true;
}

//push
template<class DT>
bool LinkList<DT>::pop(DT& d){
	if (empty())return false;
	remove_one(len, d);
	return true;
}

//insert_one
template<typename DT>
LinkListNode<DT>* LinkList<DT>::insert_one(uint id, const DT& d){
	LinkListNode<DT>* cur = locate(id - 1);
	LinkListNode<DT>* new_node = new LinkListNode < DT > ;
	new_node->data = d;
	++len;
	new_node->next = cur->next;
	cur->next = new_node;
	return new_node;
}

//remove_one
template<typename DT>
LinkListNode<DT>* LinkList<DT>::remove_one(uint id, DT& d){
	LinkListNode<DT>* cur = locate(id - 1);
	LinkListNode<DT>* new_node = cur->next;
	d = new_node->data;
	--len;
	cur->next = new_node->next;
	delete new_node;
	return cur;
}



#endif 