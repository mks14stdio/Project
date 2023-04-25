
#include <iostream>
#include <math.h>

class Triangle
{
public:

	Triangle(unsigned int A, unsigned int B, unsigned int C) {
		a = A;
		b = B;
		c = C;
	}
	unsigned int getA() { return a; }
	unsigned int getB() { return b; }
	unsigned int getC() { return c; }

	void setA(int A) { a = A; }
	void setB(int B) { b = B; }
	void setC(int C) { c = C; }

	void CanMakeTriAngle() {
		if (TriangleCheck()) {
			std::cout << "Этот треугольник можно построить\n";
		}
		else {std::cout << "Этот треугольник нельзя построить\n";
		}
	}
	unsigned int PerimeterTriangle() { 
		if (TriangleCheck()) {
			return a + b + c; 
		}
		return 0;
		}

	double AreaTriangle() {
		if (TriangleCheck()) {
			double p = static_cast<double>(PerimeterTriangle()) / 2.f;
			return sqrt(p * (p - a) * (p - b) * (p - c));
		}
		std::cout << "Нельзя найти площадь: ";
		CanMakeTriAngle();
		return 0.f;
	}

	void PrintType() {
		const char* Types[4] = { "разносторонний","равносторонний", "равнобедренный", "прямоугольный"};
		int cType = 0;

		if (TriangleCheck()) {
			if (a == b && b == c) {
				cType = 1;
			}
			else if (a == b || a == c || b == c) {
				cType = 2;
			}
			else if (a * a == b * b + c * c || b * b == a * a + b * b || c * c == a * a + b * b) {
				cType = 3;
			}
			std::cout << "Это " << Types[cType] << " треугольник\n";
		}
		else { std::cout << "Нельзя определить тип: ";  CanMakeTriAngle(); }
	}


private:
	bool TriangleCheck() {
		if ((a < b + c) && (b < a + c) && (c < a + b)) {
			return true;
		}
		return false;
	}

	unsigned int a, b, c;
};


int main()
{
	setlocale(LC_ALL, "rus");
	Triangle triangle(4, 20, 3);
	
	unsigned int perimeter = triangle.PerimeterTriangle();
	double area = triangle.AreaTriangle();

	std::cout << "Периметр: " << perimeter << " Площадь: " << area << std::endl;

	triangle.CanMakeTriAngle();
	triangle.PrintType();

}