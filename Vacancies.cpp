#include <unordered_map>
#include "Vacancy.h"
#include "Change.h"
using namespace std;

class Vacancies {
	unordered_map<int, Vacancy*> vacancies;
	vector<Change*> changes;
public:
	Vacancies() {
		vacancies = unordered_map<int, Vacancy*>();
		changes = vector<Change*>();
	};

	bool savedChanges;
	Vacancy* findById(int id);//����� �� ��������������
	Vacancy* findByParams(string vacancyName = "*", int salary = 0, string scedule = "*");//����� �� ������ ��� ���������� ����������

	bool readFromJson(string filePath);//������ ������ �� �����
	bool saveChanges(string filePath);//���������� ���������

	bool deleteVacancy(int id);//�������� ��������
	bool addVacancy(Vacancy* newVacancy);//���������� ��������
};