#ifndef	_ForwardLinkList_h_
#define	_ForwardLinkList_h_

#include "LinkList.h"

template<class T>
class ForwardLinkList:public LinkList<T>{
public:
	typedef typename LinkList<T>::Index_type Index_type;
	LinkListNode<T>*	locate(Index_type id);
};

template<class T>
LinkListNode<T>* ForwardLinkList<T>::locate(Index_type id){
	LinkListNode<T>	*p = LinkList<T>::head;	
	int i =id;
	while(--i>0)
		p = p->n;
	return p;
}


#endif