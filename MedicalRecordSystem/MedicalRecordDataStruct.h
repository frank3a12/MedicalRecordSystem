#pragma once

#include <list>
#include <string>

//�f�w�Y���{��
enum ConditionLevel {
	Serious = 0,
	Medium,
	Light
};

//������O�A�ѦҸ�ơGhttp://htmfiles.englishhome.org/main/med_division.htm
enum MedicalDepartment
{
	DivisionOfGeneralMedicine = 0,
	DivisionOfCardiology,
	DivisionOfNeurology,
	DivisionOfPediatrics
};

//�ݶE���
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

//�f�����
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

//�f�w���
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

