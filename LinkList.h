#ifndef	_LinkList_h_
#define	_LinkList_h_

#include "LinkListNode.h"

template<typename T>
class LinkList{
public:
	typedef unsigned int Index_type;

	LinkList()=default;
	
	unsigned	int	length()const{return len;}
	bool			empty()const{return len==0?true:false;}	

	LinkListNode<T>* setIdData(Index_type id, T& data);
	LinkListNode<T>* getHead(){return head;}
	LinkListNode<T>*	locate(Index_type id);

	virtual LinkListNode<T>*	insert(Index_type id, T& data) = 0;
	virtual LinkListNode<T>*	remove(Index_type id, T& data) = 0;

	
protected:
	unsigned int	len;
	LinkListNode<T>	*head=nullptr;
};



//set the data of index id
template<class T>
LinkListNode<T>* LinkList<T>::setIdData(Index_type id, T& data ){
	if (id<1 || id>len) return nullptr;
	if (empty()){
		LinkListNode<T>* n = new LinkListNode < T > ;
		n->d = data;
		head = n;
		return head;
		++len;
	}

	LinkListNode<T>* p = locate(id);
	if(p)	p->d = data;
	return(p);
}

template<class T>
LinkListNode<T>* LinkList<T>::locate(Index_type id){
	LinkListNode<T>	*p = head;
	int i = id;
	while (--i > 0)
		p = p->n;
	return p;
}

#endif