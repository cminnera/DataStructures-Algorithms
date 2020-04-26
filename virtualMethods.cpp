//Clare Minnerath
//Lab 1 Part 0

// Lab 1 P0 Q1
#include <stdio.h>  
class Shape {
public:
	virtual ~Shape();
	virtual void draw();
};
class Circle : public Shape {
public:
/*	virtual*/ ~Circle();
/*	virtual*/ void draw();
};
Shape::~Shape() {
	printf("shape destructor\n");
}
void Shape::draw() {
	printf("Shape::draw\n");
}
Circle::~Circle() {
	printf("circle destructor\n");
}
void Circle::draw() {
	printf("Circle::draw\n");
}
int main() {
	Shape *shape = new Circle();
	shape->draw();
	delete shape;
	return 0;
}

// Goal enhance your understanding of the virtual keyword and method overriding

//Remove the virtual keyword from each location individually, 
//recompiling and running each time to see how the output changes.Can you predict what will and will not work ?
//Try making Shape::draw non - pure by removing = 0 from its declaration.
//Try changing shape(in main()) from a pointer to a stack - allocated variable.


//'Shape::draw' : pure specifier or abstract override specifier only allowed on virtual function
