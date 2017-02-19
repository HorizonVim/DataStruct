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
	LinkListNode<T>*	insert(Index_type id, T& data );
	LinkListNode<T>*	remove(Index_type id, T& data);
	LinkListNode<T>* setIdData(Index_type id, T& data);
	LinkListNode<T>* getHead(){return head;}
	
	virtual LinkListNode<T>*	locate(Index_type id)=0;


	
protected:
	unsigned int	len;
	LinkListNode<T>	*head=nullptr;
};

//add the data before id 
template<class T>
LinkListNode<T>* LinkList<T>::insert(Index_type id, T& data ){
	if (empty()){
		LinkListNode<T>* n = new LinkListNode < T > ;
		n->d = data;
		head = n;
		++len;
		return head;		
	}
	if (id<1 || id > len+1) return nullptr;
	LinkListNode<T>* p = locate(id - 1);
	LinkListNode<T>* n = new LinkListNode<T>;
	++len;
	n->d = data;
	if(p){//insert others 	
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
LinkListNode<T>* LinkList<T>::remove(Index_type id, T& data ){
	if (empty() || id<1 || id>len) return nullptr;
	
	LinkListNode<T>* p = locate(id-1);
	LinkListNode<T>* n = p->n;
	data = n->d;
	--len;
	if(id == 1){
		head = p->n;
		delete p;
		return head;
	}else	{		
		p->n =n->n;
		delete n;
	}
	return(p);
}

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

#endif