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
	double tenDaysPrices[10];	//��10��ѻ�
};
typedef std::vector<StockDataStruct> StockDataStructVecT;

class CompareType 
{
public:
	static bool CompareByStockIndex(StockDataStruct &data1, StockDataStruct &data2);
	static bool CompareByStockPrice(StockDataStruct &data1, StockDataStruct &data2);
	static bool CompareByCashDividend(StockDataStruct &data1, StockDataStruct &data2);
	static bool CompareByCashDividendYield(StockDataStruct &data1, StockDataStruct &data2);
	static bool CompareByEPS(StockDataStruct &data1, StockDataStruct &data2);
	static bool CompareByROE(StockDataStruct &data1, StockDataStruct &data2);
};

class SearchType 
{
public:
	static int BinarySearch(StockDataStructVecT dataVec, int length, int stockIndex);
};