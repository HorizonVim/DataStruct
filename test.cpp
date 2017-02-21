#include<iostream>
#include "CirLinkList.h"
#include "ForwarLinkList.h"
#include "DequeLink.h"
#include "StackLink.h"

using namespace std;

int	main(void){
	int	d;

	/**************ForwarLinkList*************/
	ForwarLinkList<int> fll;

	cout << "=========================" << endl;
	cout << "ForwardLinkList" << endl;
	if(fll.empty())fll.print_data();	
	cout<<"Length:"<<fll.length() << endl;

	for (int i = 1; i <= 10; ++i)
		fll.push(i);
	fll.print_data();
	cout << "Length:" << fll.length() << endl;
	
	for (int i = 0; i < 1; ++i){
		fll.pop(d);
		cout << d << "\t";
	}
	cout << endl;
	fll.print_data();
	cout << "Length:" << fll.length() << endl;

	fll.insert(1, 50);
	fll.print_data();
	cout << "Length:" << fll.length() << endl;
	fll.insert(fll.length()+1, 0);
	fll.print_data();
	cout << "Length:" << fll.length() << endl;
	fll.insert(3, 10);
	fll.print_data();
	cout << "Length:" << fll.length() << endl;

	fll.remove(1, d);
	fll.print_data();
	cout << d << endl;
	cout << "Length:" << fll.length() << endl;
	fll.remove(fll.length() , d);
	cout << d << endl;
	fll.print_data();
	cout << "Length:" << fll.length() << endl;
	fll.remove(3, d);
	cout << d << endl;
	fll.print_data();
	cout << "Length:" << fll.length() << endl;


	/**************DequeLink*************/
	DequeLink<int>	dl;

	cout << endl;
	cout << "=========================" << endl;
	cout << "DequeLink" << endl;
	if(dl.empty())dl.print_data();
	cout << "Length:" << dl.length() << endl;

	for (int i = 1; i <= 10; ++i)
		dl.push(i+100);
	dl.print_data();
	cout << "Length:" << dl.length() << endl;

	for (int i = 0; i < 2; ++i){
		dl.pop(d);
		cout << d << "\t";
	}
	cout << endl;
	dl.print_data();
	cout << "Length:" << dl.length() << endl;

	dl.insert(1, 50);
	dl.print_data();
	cout << "Length:" <<dl.length() << endl;
	dl.insert(dl.length() + 1, 0);
	dl.print_data();
	cout << "Length:" << dl.length() << endl;
	dl.insert(3, 10);
	dl.print_data();
	cout << "Length:" << dl.length() << endl;

	dl.remove(1, d);
	cout << d << endl;
	dl.print_data();
	cout << "Length:" << dl.length() << endl;
	dl.remove(dl.length(), d);
	cout << d << endl;
	dl.print_data();
	cout << "Length:" << dl.length() << endl;
	dl.remove(3, d);
	cout << d << endl;
	dl.print_data();
	cout << "Length:" << dl.length() << endl;


	/*************CirLinkList******************/
	CirLinkList<int> cll;
	
	cout << endl;
	cout << "=========================" << endl;
	cout << "CirLinkList" << endl;
	if(cll.empty())cll.print_data();
	cout << "Length:" << cll.length() << endl;

	for (int i = 1; i <= 10; ++i)
		cll.push(i+200);
	cll.print_data();
	cout << "Length:" << cll.length() << endl;

	for (int i = 0; i < 3; ++i){
		cll.pop(d);
		cout <<d<< "\t";
	}
	cout << endl;
	cll.print_data();
	cout << "Length:" << cll.length() << endl;	

	cll.insert(1, 50);
	cll.print_data();
	cout << "Length:" << cll.length() << endl;
	cll.insert(cll.length() + 1, 0);
	cll.print_data();
	cout << "Length:" << cll.length() << endl;
	cll.insert(3, 10);
	cll.print_data();
	cout << "Length:" << cll.length() << endl;


	cll.remove(1, d);
	cout << d << endl;
	cll.print_data();
	cout << "Length:" << cll.length() << endl;
	cll.remove(cll.length(),d);
	cout << d << endl;
	cll.print_data();
	cout << "Length:" << cll.length() << endl;
	cll.remove(3, d);
	cout << d << endl;
	cll.print_data();
	cout << "Length:" << cll.length() << endl;

	/**************StackLink*************/
	StackLink<int>	sl;

	cout << endl;
	cout << "========================="<< endl;
	cout << "StackLink" << endl;
	if(sl.empty()) sl.print_data();
	cout << "Length:" << sl.length() << endl;

	for (int i = 1; i <= 10; ++i)
		sl.push(i + 300);
	sl.print_data();
	cout << "Length:" << sl.length() << endl;

	for (int i = 0; i < 4; ++i){
		sl.pop(d);
		cout << d << "\t";
	}
	cout << endl;
	sl.print_data();
	cout << "Length:" << sl.length() << endl;

	cout << sl.getTop()<<endl;

	return EXIT_SUCCESS;
}