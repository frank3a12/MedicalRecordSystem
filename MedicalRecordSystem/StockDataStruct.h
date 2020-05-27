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

