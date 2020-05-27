#pragma once
//-----------------------------------------------------------------------------
#include <vector>
//-----------------------------------------------------------------------------

class StockDataStruct
{
public:
	StockDataStruct() {};
	~StockDataStruct() {};

	int stockIndex;	//�Ѳ��N��
	double stockPrice; //�ѻ�
	double cashDividend; //�{���ѧQ
	double cashDividendYield; //�{���ѧQ�ާQ�v
	double EPS;	//EPS
	double ROE;	//ROE
};
typedef std::vector<StockDataStruct> StockDataStructVecT;

