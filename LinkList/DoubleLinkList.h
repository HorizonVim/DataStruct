#ifndef	_DoubleLinkList_h_
#define	_DoubleLinkList_h_

#include <iostream>

template<class DT>
class Node{
public:
	DT	data;
	Node* next=nullptr;
	Node* front = nullptr;
};


template<class DT>
class DoubleLinkList{
public:
	typedef	unsigned int Index;

	Index	length()const{ return len; }
	bool		empty()const{ return (len == 0) ? true : false; }

	Node<DT>* locate(Index id);
	Node<DT>* insert(Index id, const DT& d);
	Node<DT>* remove(Index id, DT& d);
	Node<DT>* push(const DT& d);
	Node<DT>* pop(DT& d);
	
	void		print_data()const;

private:
	Index	len = 0;
	Node<DT>* head=nullptr;
	Node<DT>* tail = nullptr;
};

//locate
template<typename DT>
Node<DT>* DoubleLinkList<DT>::locate(Index Id){
	Node<DT>* p = head;
	Index i = Id;
	while (--i)
		p = p->next;
	return p;
}

//push
template<typename DT>
Node<DT>* DoubleLinkList<DT>::push(const DT& d){
	Node<DT>* new_node = new Node < DT > ;
	new_node->data = d;
	if (empty())head =tail= new_node;		
	else{
		new_node->front = tail;
		tail->next = new_node;
		tail = new_node;
	}
	++len;
	return new_node;
}


//pop
template<typename DT>
Node<DT>* DoubleLinkList<DT>::pop(DT& d){
	if (empty()) return nullptr;
	if (1 == len){
		d = head->data;
		delete head;
		tail = head = nullptr;
		--len;
		return tail;
	}
	else{
 		Node<DT>* p = locate(len - 1);
		d =tail->data;
		p->next = nullptr;
		delete tail;
		tail = p;
		--len;
		return tail;
	}
	
	return nullptr;
}


//insert
template<typename DT>
Node<DT>* DoubleLinkList<DT>::insert(Index id, const DT& d){
	if (id<1 || id>len  || (id > 1 && id < len +1 && empty()))return nullptr;
	
	Node<DT>* new_node = new Node < DT > ;
	new_node->data = d;	
	if (id == 1){
		if(empty())head =tail= new_node;
		else{
			new_node->next = head;
			head->front = new_node;
			head = new_node;
		}
	}
	else{
		Node<DT>* p = locate(id - 1);
		new_node->next = p->next;
		new_node->next->front = new_node;
		new_node->front = p;
		p->next = new_node;
	}
	++len;
	return new_node;
}

//locate
template<typename DT>
Node<DT>* DoubleLinkList<DT>::remove(Index id, DT& d){
	if (empty() || id<1 || id>len)return nullptr;
	if (1 == id){
		if (1 == len){
			d = head->data;
			delete head;
			--len;
			head = tail = nullptr;
		}
		else{
			Node<DT>* p = head->next;
			d =head->data;
			p->front = nullptr;
			delete head;
			head = p;
			--len;
			return p;
		}
	}
	else{
		Node<DT>* p = locate(id - 1);
		Node<DT>* n = p->next;
		d = n->data;
		--len;
		if (len == id-1){
			delete tail;
			tail = p;
			tail->next = nullptr;
			return tail;
		}
		else{
			d = n->data;
			n->next->front = p;
			p->next = n->next;
			delete n;
			return p;
		}
		
	}	
	return nullptr;
}

//locate
template<typename DT>
void DoubleLinkList<DT>::print_data()const{
	if (empty())std::cout<<"This list is empty"<<std::endl;
	Node<DT>* p = head;
	while (p){
		std::cout << p->data << " ";
		p = p->next;
	}
	std::cout << std::endl;
	std::cout <<"This length is "<<len <<std::endl;
}



#endif