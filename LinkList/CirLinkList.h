#ifndef	_CirLinkList_h_
#define	_CirLinkList_h_

#include "LinkList.h"

template<class DT>
class CirLinkList:public LinkList<DT>{
public:
	
	bool		push(const DT& d);
	bool		pop(DT& d);
	void		print_data()const;

	LinkListNode<DT>* insert(uint id, const DT& d);
	LinkListNode<DT>* remove(uint id, DT& d);
};

//print_list
template<typename DT>
void CirLinkList<DT>::print_data()const{
	if (nullptr == head) std::cout << "This list is empty" << std::endl;
	else{
		LinkListNode<DT> *cur = head;
		do{
			std::cout << cur->data <<" ";
			cur = cur->next;
		} while (cur != head);
		
		std::cout << std::endl;
	}
}

//push
template<class DT>
bool CirLinkList<DT>::push(const DT& d){
	LinkListNode<DT>* new_node = new LinkListNode < DT > ;
	new_node->data = d;
	new_node->next = head;
	
	if (empty())	{
		head = new_node;
		new_node->next = head;
	}
	else{
		LinkListNode<DT>* p = locate(len);
		p->next = new_node;
	}
	++len;
	return true;
}

//pop
template<typename DT>
bool	CirLinkList<DT>::pop(DT& d){
	if (empty())return false;
	LinkListNode<DT>* p=remove_one(len, d);
	p->next = head;
	return true;

}

template<class DT>
LinkListNode<DT>* CirLinkList<DT>::insert(uint id, const DT& d){
	if (id<1 || id>len+1  || (id != 1 && empty())) return nullptr;
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
	if (id == len + 1){
		LinkListNode<DT>* new_node = insert_one(id, d);
		new_node->next = head;
		return new_node;
	}
	return insert_one(id, d);
}

template<class DT>
LinkListNode<DT>* CirLinkList<DT>::remove(uint id, DT& d){
	if (id<1 || id>len  || empty()) return nullptr;
	if (id == 1){
		LinkListNode<DT>* new_node = head->next;
		d = head->data;
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