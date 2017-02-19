#ifndef	_ForwardLinkList_h_
#define	_ForwardLinkList_h_

#include "LinkList.h"

template<class T>
class ForwardLinkList:public LinkList<T>{
public:
	typedef typename LinkList<T>::Index_type Index_type;
	
	LinkListNode<T>*	insert(Index_type id, T& data);
	LinkListNode<T>*	remove(Index_type id, T& data);

};



//add the data before id 
template<class T>
LinkListNode<T>* ForwardLinkList<T>::insert(Index_type id, T& data){
	if (empty()){
		LinkListNode<T>* n = new LinkListNode < T > ;
		n->d = data;
		head = n;
		++len;
		return head;
	}
	if (id<1 || id > len + 1) return nullptr;
	LinkListNode<T>* p = locate(id - 1);
	LinkListNode<T>* n = new LinkListNode < T > ;
	++len;
	n->d = data;
	if (p){//insert others 	
		n->n = p->n;
		p->n = n;
	}
	else {	//insert at the head
		n->n = head;
		head = n;
	}

	return(p);
}


//remove the data of index id
template<class T>
LinkListNode<T>* ForwardLinkList<T>::remove(Index_type id, T& data){
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