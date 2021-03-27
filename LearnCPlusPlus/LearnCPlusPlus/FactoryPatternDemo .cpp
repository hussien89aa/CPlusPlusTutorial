#include <iostream>
#include "Shapes.h"

using namespace std;
using namespace in;

enum class ShapeDraw{ Rectangle=1, Triangle=2, Square=3};

class ShapeFactory {

public:
	Shape* getShape(ShapeDraw shapeDraw, int width, int height) {

		Shape* shape = nullptr;

		switch (shapeDraw)
		{
		case ShapeDraw::Rectangle:
			shape = new Rectangle(width, height);
			break;
		case ShapeDraw::Triangle:
			shape = new Triangle(width, height);
			break;
		case ShapeDraw::Square:
			shape = new Square(width);
			break;
		default:
			shape = nullptr;
			break;
		}

		return shape;

	}
};

 

int main14() {
 
	ShapeFactory shapeFactory;
	int drawIndex = 0;
	while(true){
     
		cout << "Enter Option:\n1- for Rectangle \n2 for Triangle \n3 for Square \n0 to exit \n";
		cin >> drawIndex;
		Shape* shape = shapeFactory.getShape((ShapeDraw)drawIndex,10,20);
		if (shape == nullptr) {
			break;
		}
		cout <<"We draw:"<< typeid(shape).name()<< endl<< shape->area() << endl;
		delete shape;

	}
 
	system("pause");

	return 0;
}