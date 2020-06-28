#include "pch.h"
#include "StockDataStruct.h"

bool CompareType::CompareByStockIndex(StockDataStruct &data1, StockDataStruct &data2)
{
	return (data1.stockIndex < data2.stockIndex);
}

bool CompareType::CompareByStockPrice(StockDataStruct &data1, StockDataStruct &data2)
{
	return (data1.stockPrice < data2.stockPrice);
}

bool CompareType::CompareByCashDividend(StockDataStruct &data1, StockDataStruct &data2)
{
	return (data1.cashDividend < data2.cashDividend);
}

bool CompareType::CompareByCashDividendYield(StockDataStruct &data1, StockDataStruct &data2)
{
	return (data1.cashDividendYield < data2.cashDividendYield);
}

bool CompareType::CompareByEPS(StockDataStruct &data1, StockDataStruct &data2)
{
	return (data1.EPS < data2.EPS);
}

bool CompareType::CompareByROE(StockDataStruct &data1, StockDataStruct &data2)
{
	return (data1.ROE < data2.ROE);
}

int SearchType::BinarySearch(StockDataStructVecT dataVec, int length, int stockIndex)
{
	int left = 0, right = length - 1;
	while (left <= right)
	{
		int middle = (right + left) / 2;

		if (dataVec[middle].stockIndex == stockIndex)
			return middle;

		if (dataVec[middle].stockIndex > stockIndex)
			right = middle - 1;
		else
			left = middle + 1;
	}
	return -1;
}