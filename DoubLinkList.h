#ifndef	_DoubLinkList_h_
#define	_DoubLinkList_h_

#include "LinkList.h"

template<class T>
class DoubLinkList:public LinkList<T>{
public:
	typedef typename LinkList<T>::Index_type Index_type;

	LinkListNode<T>*	insert(Index_type id, T& data) ;
	LinkListNode<T>*	remove(Index_type id, T& data);
};

template<typename T>
LinkListNode<T>*	DoubLinkList<T>::insert(Index_type id, T& data){
	if (empty()){
		LinkListNode<T>* n = new LinkListNode < T > ;
		n->d = data;
		head = n;
		++len;
		return head;
	}

	if (id <1 || id>len + 1) return nullptr;
	LinkListNode<T>* p = locate(id - 1);
	LinkListNode<T>* n = new LinkListNode < T > ;
	++len;
	n->d = data;
	if (p){//insert others 
		if (id == id + 1){
			n->n = p->n;
			n->n->h = n;
			p->n = n;
			n->h = p;
		}else{
			p->n = n;
			n->h = p;
		}		
	}
	else {	//insert at the head
		n->n = head;
		n->h = nullptr;
		head->h = n;
		head = n;
	}

	return(p);
}

template<class T>
LinkListNode<T>* DoubLinkList<T>::remove(Index_type id, T& data){
	if (empty() || id<1 || id>len) return nullptr;

	LinkListNode<T>* p = locate(id - 1);
	LinkListNode<T>* n = p->n;
	data = n->d;
	--len;
	if (id == 1){
		head = p->n;
		delete p;
		return head;
	}
	else	{
		p->n = n->n;
		delete n;
	}
	return(p);
}



#endif