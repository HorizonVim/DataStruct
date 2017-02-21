#ifndef	_List_h_
#define	_List_h_

#include "LinkListNode.h"
#include <iostream>

template<typename DT>
class List{
public:
	bool		empty()const{ return (head == nullptr) ? true : false; }


	virtual bool push(const DT& d)= 0;
	virtual bool pop(DT& d)= 0;
	virtual void print_data()const;
	

protected:
	LinkListNode<DT>	*head = nullptr;	
};

template<class DT>
void	List<DT>::print_data()const{
	if (nullptr == head)	std::cout << "This list is empty" << std::endl;
	else{
		LinkListNode<DT> *cur = head;
		while (cur!=nullptr){
			std::cout << cur->data <<" ";
			cur = cur->next;
		}
		std::cout << std::endl;
	}
}


#endif