#include <iostream>
#include <stdlib.h>
using namespace std;
class compute_area //�������O
{
public:
	double area;
	double pen;
	virtual void get_area() = 0; //�µ����禡 
	virtual void get_value() = 0; //�µ����禡 
	virtual void get_pen() = 0; //�µ����禡 
	void print_area()
	{
		cout << "���n:" << area << endl;
	}
	void print_pen()
	{
		cout << "�P��:" << pen << endl;
	}
};
class Rect :public compute_area   //class Rect �~�Ӧ� compute_area
{
public:
	double x;
	double y;
	void get_area()
	{
		area = x*y;	//�x�έ��n:��*�e
	}
	void get_pen()
	{
		pen = (x + y) * 2;
	}
	void get_value()
	{
		cout << "�п�J��:";
		cin >> x;
		cout << "�п�J�e:";
		cin >> y;
	}
};
class Circle :public Rect	//class Circle �~�Ӧ� Rect
{
public:
	double x;
	void get_area()
	{
		area = x*x*3.14;	//�ꪺ���n:�b�|����*3.14
	}
	void get_pen()
	{
		pen = (x * 2)*3.14;		//�ꪺ�P��:���|*3.14
	}
	void get_value()
	{
		cout << "�п�J�b�|:";
		cin >> x;
	}
};
class Triangle :public compute_area		//class Triangle �~�Ӧ� compute_area
{
public:
	double x;
	double y;
	void get_area()
	{
		area = x*y / 2;	//�T���έ��n:��*��/2
	}
	void get_pen()
	{
		pen = x + (sqrt((x / 2)*(x / 2) + y*y)) * 2;
	}
	void get_value()
	{
		cout << "�п�J���y�T���Ω�:";
		cin >> x;
		cout << "�п�J���y�T���ΰ�:";
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
	InputData(A); //�i��g��A->get_value(); 
	PrintArea(A); //�i��g��A->get_area(); A->print_area(); 
	PrintPen(A);
	cout << "---------------" << endl;
	InputData(B); //�i��g��B->get_value(); 
	PrintArea(B); //�i��g��B->get_area(); B->print_area();
	PrintPen(B);
	cout << "---------------" << endl;
	InputData(C);
	PrintArea(C);
	PrintPen(C);
	system("pause");
	return 0;
}