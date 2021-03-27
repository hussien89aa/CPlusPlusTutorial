
// header
class Rectangle {

public:

	// method
	int area();
	//void setValues(int width, int height);
	Rectangle(int width, int height);
	~Rectangle();

	Rectangle operator + (const Rectangle& rect);
private:
	// properties
	int width;
	int height;
};
