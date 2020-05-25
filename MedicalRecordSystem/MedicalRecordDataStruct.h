#pragma once

#include <list>
#include <string>

//病患嚴重程度
enum ConditionLevel {
	Serious = 0,
	Medium,
	Light
};

//醫療科別，參考資料：http://htmfiles.englishhome.org/main/med_division.htm
enum MedicalDepartment
{
	DivisionOfGeneralMedicine = 0,
	DivisionOfCardiology,
	DivisionOfNeurology,
	DivisionOfPediatrics
};

//看診日期
class VisitDate
{
public:
	VisitDate() {};
	~VisitDate() {};

public:
	int year;
	int month;
	int date;
};

//病歷資料
class MedicalRecord 
{
public:
	MedicalRecord() {};
	~MedicalRecord() {};

public:
	ConditionLevel conditionLevel;
	VisitDate visitDate;
};
typedef std::list<MedicalRecord> MedicalRecordListT;

//病患資料
class Patient
{
public:
	Patient() {};
	~Patient() {};

public:
	std::wstring name;
	int idNumber;
	MedicalRecordListT medicineRecordList;
};

