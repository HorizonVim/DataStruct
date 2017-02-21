#ifndef	_ForwarLinkList_h_
#define	_ForwarLinkList_h_

#include "LinkList.h"

template<class DT>
class ForwarLinkList:public LinkList<DT>{
public:
	typedef typename LinkList<DT>::uint uint;

	LinkListNode<DT>* insert(uint id, const DT& d);
	LinkListNode<DT>* remove(uint id, DT& d);

};

//insert
template<class DT>
LinkListNode<DT>* ForwarLinkList<DT>::insert(uint id, const DT& d){
	if (id<1 || id>len + 1 || (id!=1&& empty()) ) return nullptr;
	if (id == 1){
		LinkListNode<DT>* new_node = new LinkListNode < DT > ;
		new_node->data = d;
		new_node->next = head;
		++len;
		head = new_node;
		return head;
	}
	return insert_one(id, d);
}

template<class DT>
LinkListNode<DT>* ForwarLinkList<DT>::remove(uint id, DT& d){
	if (id<1 || id>len + 1 || empty()) return nullptr;
	if (id == 1){
		LinkListNode<DT>* new_node = head->next;
		d = head->data;
		--len;
		delete head;
		head = new_node;
		return head;
	}

	return remove_one(id, d);
}
#endif