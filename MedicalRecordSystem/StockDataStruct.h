#pragma once
//-----------------------------------------------------------------------------
#include <vector>
//-----------------------------------------------------------------------------

class StockDataStruct
{
public:
	StockDataStruct() {};
	~StockDataStruct() {};

	int stockIndex;	//股票代號
	double stockPrice; //股價
	double cashDividend; //現金股利
	double cashDividendYield; //現金股利殖利率
	double EPS;	//EPS
	double ROE;	//ROE
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