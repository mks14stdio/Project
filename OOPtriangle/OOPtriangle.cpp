
#include <iostream>

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
		else { CanMakeTriAngle(); }
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
	Triangle triangle(4, 20, 5);
	triangle.PrintType();

	triangle.CanMakeTriAngle();

}