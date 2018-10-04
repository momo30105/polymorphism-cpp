#include <iostream>
#include <stdlib.h>
using namespace std;
class compute_area //虛擬類別
{
public:
	double area;
	double pen;
	virtual void get_area() = 0; //純虛擬函式 
	virtual void get_value() = 0; //純虛擬函式 
	virtual void get_pen() = 0; //純虛擬函式 
	void print_area()
	{
		cout << "面積:" << area << endl;
	}
	void print_pen()
	{
		cout << "周長:" << pen << endl;
	}
};
class Rect :public compute_area   //class Rect 繼承自 compute_area
{
public:
	double x;
	double y;
	void get_area()
	{
		area = x*y;	//矩形面積:長*寬
	}
	void get_pen()
	{
		pen = (x + y) * 2;
	}
	void get_value()
	{
		cout << "請輸入長:";
		cin >> x;
		cout << "請輸入寬:";
		cin >> y;
	}
};
class Circle :public Rect	//class Circle 繼承自 Rect
{
public:
	double x;
	void get_area()
	{
		area = x*x*3.14;	//圓的面積:半徑平方*3.14
	}
	void get_pen()
	{
		pen = (x * 2)*3.14;		//圓的周長:直徑*3.14
	}
	void get_value()
	{
		cout << "請輸入半徑:";
		cin >> x;
	}
};
class Triangle :public compute_area		//class Triangle 繼承自 compute_area
{
public:
	double x;
	double y;
	void get_area()
	{
		area = x*y / 2;	//三角形面積:底*高/2
	}
	void get_pen()
	{
		pen = x + (sqrt((x / 2)*(x / 2) + y*y)) * 2;
	}
	void get_value()
	{
		cout << "請輸入等腰三角形底:";
		cin >> x;
		cout << "請輸入等腰三角形高:";
		cin >> y;
	}
};
void InputData(compute_area *ptr)
{
	ptr->get_value();
}
void PrintArea(compute_area *ptr)
{
	ptr->get_area();
	ptr->print_area();
}
void PrintPen(compute_area *ptr)
{
	ptr->get_pen();
	ptr->print_pen();
}
int main(void)
{
	Rect* A = new Rect;
	Circle* B = new Circle;
	Triangle *C = new Triangle;
	InputData(A); //可改寫為A->get_value(); 
	PrintArea(A); //可改寫為A->get_area(); A->print_area(); 
	PrintPen(A);
	cout << "---------------" << endl;
	InputData(B); //可改寫為B->get_value(); 
	PrintArea(B); //可改寫為B->get_area(); B->print_area();
	PrintPen(B);
	cout << "---------------" << endl;
	InputData(C);
	PrintArea(C);
	PrintPen(C);
	system("pause");
	return 0;
}