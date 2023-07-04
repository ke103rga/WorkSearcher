#include <unordered_map>
#include <unordered_set>
#include "Vacancy.h"
using namespace std;


#pragma once
class Vacancies {
	unordered_map<int, Vacancy*> vacancies;
public:
	Vacancies();
	bool savedChanges;

	Vacancy* findById(int id);//����� �� ��������������
	vector<int> findByParams(string vacancyName, int minSalary, int maxSalary, unordered_set<string> scedule);//����� �� ������ ��� ���������� ����������

	bool readFromJson(string filePath);//������ ������ �� �����
	bool saveChanges(string filePath);//���������� ���������

	bool deleteVacancy(int id);//�������� ��������
	bool addVacancy(Vacancy* newVacancy);//���������� ��������
};

#pragma once
extern Vacancies vacancies;
