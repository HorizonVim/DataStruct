#ifndef	_LinkListNode_h_
#define	_LinkListNode_h_

template<typename DT>
class LinkListNode{
public:
	DT	data;
	LinkListNode* next=nullptr;
};


#endif