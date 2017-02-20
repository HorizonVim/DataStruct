#ifndef	_CirLinkList_h_
#define	_CirLinkList_h_

#include "LinkList.h"

template<class DT>
class CirLinkList:public LinkList{

};
template<class DT>
bool CirLinkList<DT>::push(DT& d){
	LinkListNode<DT>* new_node = new LinkListNode < DT > ;
	new_node->data = d;
	new_node->next = head;
	++len;
	if (empty())	{
		head = new_node;
		new_node->next = head;
	}
	
	LinkListNode<DT>* p = insert_one(len);
	p->next = new_node;
	return true;
}

template<typename DT>
bool	CirLinkList<DT>::pop(DT& d){
	if (empty())return false;
	LinkListNode<DT>* p=remove_one(len, d);
	p->next = head;
	return TRUE;

}

template<class DT>
LinkListNode<DT> CirLinkList<DT>::insert(uint id, DT& d){
	if (id<1 || id>len  || (id != 1 && empty())) return nullptr;
	if (id == 1){
		LinkListNode<DT>* new_node = new LinkListNode < DT > ;
		new_node->data = d;
		++len;
		new_node->next = head->next;
		head = new_node;
		new_node = locate(len);
		new_node->next = head;
		return head;
	}	
	return insert_one(id, d);
}

template<class DT>
LinkListNode<DT>* CirLinkList<DT>::remove(uint id, DT& d){
	if (id<1 || id>len  || empty()) return nullptr;
	if (id == 1){
		LinkListNode<DT>* new_node = head->next;
		--len;
		delete head;
		head = new_node;
		new_node = locate(len);
		new_node->next = head;
		return head;
	}

	return remove_one(id, d);
}

#endif