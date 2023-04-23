
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

	bool CanMakeTriAngle() {
		if ((a < b + c) && (b < a + c) && (c < a + b)) {
			return true;
		}
		return false;
	}

	void PrintType() {
		const char* Types[4] = { "разносторонний","равносторонний", "равнобедренный", "прямоугольный"};
		int cType = 0;

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


private:
	unsigned int a, b, c;
};


int main()
{
	setlocale(LC_ALL, "rus");
	Triangle triangle(12, 12, 12);
	triangle.PrintType();

	bool can = triangle.CanMakeTriAngle();
	std::cout << can << std::endl;

}