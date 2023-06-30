#include "Vacancy.h"

#pragma once
class Change {
public:
	Change(Vacancy* vacancy, int vacancyId, string action) {
		this->vacancy = vacancy;
		this->vacancyId = vacancyId;
		this->action = action;
	}
	Vacancy* vacancy;
	int vacancyId;
	string action;
};