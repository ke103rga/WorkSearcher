#include <unordered_map>
#include <unordered_set>
#include "Vacancy.h"
using namespace std;


#pragma once
class Vacancies {
	unordered_map<int, Vacancy> vacancies;
	int nextId;
public:
	Vacancies();
	bool savedChanges = true;

	Vacancy* findById(int id);//����� �� ��������������
	vector<int> findByParams(string vacancyName, int minSalary, int maxSalary, unordered_set<string> scedule);//����� �� ������ ��� ���������� ����������

	bool readFromTXT(string filePath);//������ ������ �� �����
	bool saveChanges(string filePath);//���������� ���������

	bool deleteVacancy(int id);//�������� ��������
	int addVacancy(Vacancy newVacancy);//���������� ��������

	int getNextId();
};

#pragma once
extern Vacancies vacancies;
#pragma once
extern string DB_FILE_PATH;
