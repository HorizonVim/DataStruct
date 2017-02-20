#ifndef	_List_h_
#define	_List_h_

#include "LinkListNode.h"

template<typename DT>
class List{
public:
	bool		empty()const{ return (head == nullptr) ? true : false; }


	virtual bool push(DT& d)const = 0;
	virtual bool pop(DT& d)const = 0;
	

protected:
	LinkListNode<T>	*head = nullptr;	
};

#endif