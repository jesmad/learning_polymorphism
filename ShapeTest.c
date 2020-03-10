#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "malloc.h"

#define PI 3.14159

typedef double (*VirtualMethodPointer)(void*);
//VirtualMethodPointer is a typedef for a pointer to a function (which takes a
//pointer to void) returning double (could return any primitive type other than double)

typedef VirtualMethodPointer * VTableType;


//Forward declaration of our structs

struct Shape;
struct Circle;
struct Triangle;
struct Square;
struct Rectangle;
struct Picture;

//-------------------------SHAPE------------------------------
struct Shape
{
	VTableType VPointer;
	char name[64];
};

//Shape.area()
double Shape_Area(struct Shape * _this)
{
	return 0.0;
}
//Shape.draw()
void Shape_Draw(struct Shape * _this)
{
	printf("Shape.draw()\n");
	return;
}
//Shape.description()
void Shape_Description(struct Shape * _this)
{
	printf("This function will be used to print the dimensions of a shape.\n");
	return;
}
//Prints _this->name
void Shape_MyName(struct Shape * _this)
{
	printf("This is my name %s\n", _this->name);
	return;
}
//Shape's VTABLE
VirtualMethodPointer Shape_VTable[] = 
{
	(VirtualMethodPointer)Shape_Area,			//VTABLE[0] -first virtual method
	(VirtualMethodPointer)Shape_Draw,			//VTABLE[1] -second virtual method
	(VirtualMethodPointer)Shape_Description		//VTABLE[2] -third virtual method
};
//Circle's Constructor
struct Shape * Shape_Shape(struct Shape * _this, char name[])
{
	_this->VPointer = Shape_VTable;
	strcpy(_this->name, name);
	return _this;
}
//-------------------------SHAPE------------------------------


//-------------------------TRIANGLE--------------------------

struct Triangle
{
	VTableType VPointer;
	int height;
	int base;
	char name[64];
};

//Triangle.area()
double Triangle_Area(struct Triangle * _this)
{
	return (double) ( (_this->height * _this->base) / 2.0 );
}
//Triangle.draw()
void Triangle_Draw(struct Triangle * _this)
{
	char * display = "\t\t*		          	\n"
					 "\t\t**             	\n"
					 "\t\t***           	\n"
					 "\t\t****          	\n"
					 "\t\t*****        		\n"
					 "\t\t******		 	\n"	
					 "\t\t*******			\n"	
					 "\t\t********		 	\n"	
					 "\t\t*********		 	\n"	
					 "\t\t**********		\n";	
	printf("%s", display);
	return;
}
//Triangle.description()
void Triangle_Description(struct Triangle * _this)
{
	printf("%s: height=%d, base=%d\n", _this->name, _this->height, _this->base);
}
//Triangle's VTABLE
VirtualMethodPointer Triangle_VTable[] = 
{
	(VirtualMethodPointer)Triangle_Area,	//Override Shape.area()
	(VirtualMethodPointer)Triangle_Draw,	//Override Shape.draw()
	(VirtualMethodPointer)Triangle_Description	//Override Shape.description()
};
//Triangle's Constructor
struct Triangle * Triangle_Triangle(struct Triangle * _this, char name[], int height, int base)
{
	Shape_Shape((struct Shape * )_this, name); //Call parent constructor 
	_this->VPointer = Triangle_VTable;		   //Setup vpointer
	_this->height = height;						
	_this->base = base;
	strcpy(_this->name, name);
	return _this;
}
//-----------------------------TRIANGLE----------------------------------

//----------------------------CIRCLE------------------------------------

struct Circle
{
	VTableType VPointer;
	int radius;
	char name[64];
};
//Circle.area()
double Circle_Area(struct Circle * _this)
{
	return (double) (PI * _this->radius * _this->radius);
}
//Circle.draw()
void Circle_Draw(struct Circle * _this)
{
	char * display = "		 **********		\n"
					 "\t        ************		\n"
					 "\t       **************		\n"
					 "\t       **************		\n"
					 "\t       **************		\n"
					 "\t        ************		\n"
					 "\t         **********			\n";
	printf("%s", display);
	return;
}
//Circle.description()
void Circle_Description(struct Circle * _this)
{
	printf("%s: radius=%d\n", _this->name, _this->radius);
	return;
}
//Circle's VTABLE
VirtualMethodPointer Circle_VTable[] =
{
	(VirtualMethodPointer)Circle_Area,
	(VirtualMethodPointer)Circle_Draw,
	(VirtualMethodPointer)Circle_Description
};
//Circle's constructor
struct Circle * Circle_Circle(struct Circle * _this, char name[], int radius)
{
	Shape_Shape((struct Shape *)_this, name);
	_this->VPointer = Circle_VTable;
	_this->radius = radius;
	strcpy(_this->name, name);
	return _this;
}
//----------------------------Circle-----------------------------------

//----------------------------Square-----------------------------------
struct Square
{
	VTableType VPointer;
	int side;
	char name[64];
};
//Square.area()
double Square_Area(struct Square * _this)
{
	return (double) (_this->side * _this->side);
}
//Sqaure.draw()
void Square_Draw(struct Square * _this)
{
	char * display = "\t\t  ********** \n"
					 "\t\t  ********** \n"
					 "\t\t  ********** \n"
					 "\t\t  ********** \n"
					 "\t\t  ********** \n"
					 "\t\t  ********** \n";
	printf("%s", display);
}
//Square.description()
void Square_Description(struct Square * _this)
{
	printf("%s: side=%d\n", _this->name, _this->side);
	return;
}
//Square's VTABLE
VirtualMethodPointer Square_VTable[] = 
{
	(VirtualMethodPointer)Square_Area,
	(VirtualMethodPointer)Square_Draw,
	(VirtualMethodPointer)Square_Description
};
//Square's Constructor
struct Square * Square_Square(struct Square * _this, char name[], int side)
{
	Shape_Shape((struct Shape *)_this, name);
	_this->VPointer = Square_VTable;
	_this->side = side;
	strcpy(_this->name, name);
	return _this;
}
//------------------------SQUARE---------------------------------------

struct Rectangle
{
	VTableType VPointer;
	int length;
	int width;
	char name[64];
};
//Rectangle.area()
double Rectangle_Area(struct Rectangle * _this)
{
	return (double) (_this->length * _this->width);
}
//Rectangle.draw()
void Rectangle_Draw(struct Rectangle * _this)
{
	char * display = "\t\t  ************  \n"
					 "\t\t  ************  \n"
					 "\t\t  ************  \n"
					 "\t\t  ************  \n"
					 "\t\t  ************  \n"
					 "\t\t  ************  \n"
					 "\t\t  ************  \n"
					 "\t\t  ************  \n"
					 "\t\t  ************  \n"
					 "\t\t  ************  \n"
					 "\t\t  ************  \n";
	printf("%s", display);
	return;
}
//Rectangle.description()
void Rectangle_Description(struct Rectangle * _this)
{
	printf("%s: length=%d, width=%d\n", (struct Shape *)_this->name, _this->length, _this->width);
	return;
}
//Rectangle's VTABLE
VirtualMethodPointer Rectangle_VTable[] = 
{
	(VirtualMethodPointer)Rectangle_Area,
	(VirtualMethodPointer)Rectangle_Draw,
	(VirtualMethodPointer)Rectangle_Description
};
//Rectangle's constructor
struct Rectangle * Rectangle_Rectangle(struct Rectangle * _this, char name[], int length, int width)
{
	Square_Square((struct Square *)_this, name, length);
	_this->VPointer = Rectangle_VTable;
	_this->length = length;
	_this->width = width;
	strcpy(_this->name, name);
	return _this;
}
//---------------------------Rectangle--------------------------------


//----------------------------PICTURE-----------------------------------
struct Picture
{
	int count;
	struct Shape * myList[8];
};
//Picture.drawAll()
void Picture_DrawAll(struct Picture * _this)
{
	int index;
	for (index = 0; index < _this->count; index++)
	{
		printf("\n");
		(_this->myList[index]->VPointer[1])(_this->myList[index]);
		printf("\n");
	}
	return;
}
//Picture.totalArea()
double Picture_TotalArea(struct Picture * _this)
{
	double total = 0.0;
	int index;
	for (index = 0; index < _this->count; index++)
	{
		total += (_this->myList[index]->VPointer[0])(_this->myList[index]);
	}
	return total;
}
//Picture.add()
void Picture_Add(struct Picture * _this, struct Shape * sh)
{
	if (_this->count >= 8)
	{
		printf("NO MORE SHAPES FIT IN PICTURE\n");
		return;
	}
	_this->myList[_this->count] = sh;
	_this->count += 1;
}
//Picture.printShapes()
void Picture_PrintShapes(struct Picture * _this)
{
	int index;
	for (index = 0; index < _this->count; index++)
	{
		(_this->myList[index]->VPointer[2])(_this->myList[index]);	//Shape.description()
		(_this->myList[index]->VPointer[1])(_this->myList[index]);	//Shape.draw()
		printf("\n");		
	}
	return;
}
//Picture's constructor
struct Picture * Picture_Picture(struct Picture * _this)
{
	_this->count = 0;
	return _this;
}


//---------------------------PICTURE------------------------------------

int main()
{
	//PICTURE
	struct Picture * p = (struct Picture * )malloc(sizeof(struct Picture));
	Picture_Picture(p);
		
	//TRIANGLE 1
	struct Triangle * t1 = (struct Triangle *)malloc(sizeof(struct Triangle));
	char triangle1[] = "First Triangle";
	int h1 = 5;
	int b1 = 5;
	Triangle_Triangle(t1, triangle1, h1, b1);

	//TRIANGLE 2
	struct Triangle * t2 = (struct Triangle *)malloc(sizeof(struct Triangle));
	char triangle2[] = "Second Triangle";
	int h2 = 4;
	int b2 = 3;
	Triangle_Triangle(t2, triangle2, h2, b2);
		
	//CIRCLE 1
	struct Circle * c1 = (struct Circle *)malloc(sizeof(struct Circle));
	char circle1[] = "First Circle";
	int r1 = 5;
	Circle_Circle(c1, circle1, r1);

	//CIRCLE 2
	struct Circle * c2 = (struct Circle *)malloc(sizeof(struct Circle));
	char circle2[] = "Second Circle";
	int r2 = 10;
	Circle_Circle(c2, circle2, r2);
	
	//SQUARE 1
	struct Square * s1 = (struct Square *)malloc(sizeof(struct Square));
	char square1[] = "First Square";
	int side1 = 5;
	Square_Square(s1, square1, side1);

	//SQUARE 2
	struct Square * s2 = (struct Square *)malloc(sizeof(struct Square));
	char square2[] = "Second Square";
	int side2 = 10;
	Square_Square(s2, square2, side2);

	//RECTANGLE 1
	struct Rectangle * REC1 = (struct Rectangle *)malloc(sizeof(struct Rectangle));
	char rec1[] = "First Rectangle";
	int len1 = 4;
	int width1 = 8;
	Rectangle_Rectangle(REC1, rec1, len1, width1);

	//RECTANGLE 2
	struct Rectangle * REC2 = (struct Rectangle *)malloc(sizeof(struct Rectangle));
	char rec2[] = "Second Rectangle";
	int len2 = 8;
	int width2 = 4;
	Rectangle_Rectangle(REC2, rec2, len2, width2);	
	
	//Add Shapes to the Picture	
	Picture_Add(p, (struct Shape *)t1);
	Picture_Add(p, (struct Shape *)t2);
	Picture_Add(p, (struct Shape *)c1);
	Picture_Add(p, (struct Shape *)c2);
	Picture_Add(p, (struct Shape *)s1);
	Picture_Add(p, (struct Shape *)s2);
	Picture_Add(p, (struct Shape *)REC1);
	Picture_Add(p, (struct Shape *)REC2);

	//Picture.totalArea(), Picture.drawAll(), Picture.printShapes()
	double TA = Picture_TotalArea(p);
	Picture_PrintShapes(p);
	printf("TOTAL AREA is %.3f\n", TA);
	Picture_DrawAll(p);

	//Deallocate memory 
	free(p);
	free(t1);
	free(t2);
	free(c1);
	free(c2);
	free(s1);
	free(s2);
	free(REC1);
	free(REC2);

	return 0;
}

