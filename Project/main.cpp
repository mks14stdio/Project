#include <string>
#include <vector>
#include <iostream>

class Student {
private:
	std::string name;
	unsigned int age;
	std::vector<unsigned int> grades;

	bool gradeChecker(std::vector<unsigned int>& cGrades) {
		for (const auto i : cGrades) {
			if (i > 5 || i < 2) {
				std::cout << "������ ������ 5 ��� ������ 2" << std::endl;
				return false;
			}
			
		}
		return true;
	}

	bool gradeChecker(unsigned int cGrades) {
		if (cGrades > 5 || cGrades < 2) {
			std::cout << "������ ������ 5 ��� ������ 2" << std::endl;
			return false;
		}
		return true;
	}
	
public:
	Student() : name(""), age(0), grades(0) {}
	Student(std::string n, unsigned int a, std::vector<unsigned int> g) :
		name(n), age(a)
	{
		setGrades(g);
	}

	void setName(std::string n) { name = n; }
	void setAge(unsigned int a) { age = a; }
	void setGrades(std::vector<unsigned int>& nGrades) { 
		if (gradeChecker(nGrades)) {
			grades = nGrades;
		}

	}
	void addGrades(unsigned int nGrade) {
		if (gradeChecker(nGrade)) {
			grades.push_back(nGrade);
		}
	}
	void removeGrades() { grades.clear(); }

	void printInfo() {
		std::cout << "�������: " << name << " ";
		if (isExcellent())
			std::cout << "(��������)";
		std::cout << "\n�������: " << age << "\n";
		std::cout << "������: ";
		for (const auto i : grades)
			std::cout << i << " ";
		std::cout << "\n������� ����: " << arvGrades() << "\n\n";
	}
	std::string getName() { return name; }
	unsigned int getAge() { return age; }
	std::vector<unsigned int> getGrades() { return grades; }
	bool isExcellent() {
		if (arvGrades() > 4.5) {
			return true;
		}
		else { return false; }
	}


	float arvGrades() {
		if (!grades.empty()) {
			float summa = 0;
			float k = 0;
			for (const auto i : grades) {
					k++;
					summa += i;
			}
				return static_cast<float>(summa / k);
		}
		else { return 2.0; }
	}
};


int main() {
	setlocale(LC_ALL, "rus");
	std::vector<unsigned int> grad{ 5, 4, 5, 5, 5, 5};
	Student ivan("����", 16, grad);
	ivan.printInfo();

	Student kirill("������", 17, std::vector<unsigned int>{4, 3, 3, 3, 3});
	kirill.printInfo();

	Student oleg;
	oleg.printInfo();

	Student nikita("������", 16, std::vector<unsigned int>{4, 6, 4, 4, 1});
	nikita.printInfo();

	return 0;
}