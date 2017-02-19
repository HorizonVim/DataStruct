#include <iostream>
#include "DoubLinkList.h"
#include "ForwardLinkList.h"
#include "LinkListNode.h"

using namespace std;

 int	main(void){	
	DoubLinkList<int> l;
	//ForwardLinkList<int> l;
	for(int i=1;i<10;++i)
		l.insert(i,i);
	LinkListNode<int> *p=l.getHead();
	while (p)
	{
		cout<<p->d<<endl;
		p=p->n;
	}

	int num;
	l.remove(2, num);
	p = l.getHead();
	while (p)
	{
		cout << p->d << endl;
		p = p->n;
	}
	return EXIT_SUCCESS;
}