
#include <iostream>

using namespace std;

namespace in {
	class Shape {

	public:
		Shape(int width, int height) {
			cout << "Shape 1 created" << endl;
			this->width = width;
			this->height = height;
		}

		Shape(int width) {
			cout << "Shape 2 created" << endl;
			this->width = width;
		}

		virtual int area() = 0;


	protected:
		int width, height;

	};

	class Rectangle : public Shape {

	public:

		Rectangle(int width, int height) :Shape(width, height) {
			cout << "Rectangle created" << endl;
		}
		int area() {
			return this->width * this->height;
		}

	};

	class Triangle : public Shape {

	public:
		Triangle(int width, int height) :Shape(width, height) {
			cout << "Triangle created" << endl;
		}

		int area() {
			return this->width * this->height / 2;
		}

	};

	class Square : public Shape {

	public:
		Square(int width) :Shape(width) {
			cout << "Square created" << endl;
		}
		int area() {
			return this->width * this->width;
		}

	};
}