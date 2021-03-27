#include <iostream>
#include "Stack2.h"

#include "Shapes.h"

using namespace std;


int main13() {

	in::Rectangle r(10, 20);
	cout <<"Rectangle area:"<< r.area() << endl;

	in::Triangle t(10, 20);
	cout << "Triangle area:" << t.area() << endl;


	in::Square s(10);
	cout << "Square area:" << s.area() << endl;


	ds::Stack2<int> st;
	st.push(10);
	st.push(20);
	st.push(30);
	 
	cout << st.pop() <<"\t"<< st.getSize()<< endl;
	cout << st.pop() << "\t" << st.getSize() << endl;
	cout << st.pop() << "\t" << st.getSize() << endl;


	unsigned short x;
	unsigned long xx;
	cout << &x << endl<< sizeof(x) << endl << &xx << endl << sizeof(xx) <<  endl;

	system("pause");

	return 0;
}