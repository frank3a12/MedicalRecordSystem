#pragma once
//-----------------------------------------------------------------------------
#include "StockDataStruct.h"
//-----------------------------------------------------------------------------

// SelectStockByConditionDlg 對話方塊

class SelectStockByConditionDlg : public CDialogEx
{
	DECLARE_DYNAMIC(SelectStockByConditionDlg)

public:
	SelectStockByConditionDlg(CWnd* pParent = nullptr);   // 標準建構函式
	virtual ~SelectStockByConditionDlg();

public:
	void SetStockDB(StockDataStructVecT stockDB) { mStockDB = stockDB; };

// 對話方塊資料
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_SelectStockByCondition };
#endif

private:
	void FindBestCashDividendGreedy(int budget);
	void FindBestROEGreedy(int budget);
	void FindBestTenDaySetDP(int budget, int stockIndex);

	StockDataStructVecT mStockDB;
	int mUserBudget;
	CComboBox mSelectComboBox;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支援

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonRecommandexecute();
};
