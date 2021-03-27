#include <iostream>
#include "Rectangle.hh"

using namespace std;



int main11() {
 

	{
		Rectangle rect1(10, 20);
		//rect1.setValues(10, 20);
		int result = rect1.area();
		//cout << "Width=" << rect1.width << ",Height=" << rect1.height;
		cout << "result=" << result << endl;


		Rectangle rect2(8, 5);
		//rect2.setValues(8, 5);
		int result2 = rect2.area();
		//cout << "Width=" << rect2.width << ",Height=" << rect2.height;
		cout << "result2=" << result2 << endl;

		 
		Rectangle Rect3 = rect1 + rect2;
		cout << "Rect3 Width=" << Rect3.area() << endl;
	}
 
	system("pause");

	return 0;
}