#include "Rectangle.hh"
#include <iostream>
using namespace std;

// implematation
int Rectangle::area() {
	int area = this->width * this->height;
	return area;
}

//void Rectangle::setValues(int width, int height) {
//	this->width = width;
//	this->height = height;
//}

Rectangle::Rectangle(int width, int height) {
	this->width = width;
	this->height = height;
	cout << "Rectangle is created width*height (" << this->width << "*" << this->height << ")\n";
}

Rectangle::~Rectangle() {
	cout << "Rectangle is deleted \n";
}

Rectangle Rectangle::operator + (const Rectangle& rect) {

	int width = this->width + rect.width;
	int height = this->height + rect.height;

	return Rectangle(width, height);
}