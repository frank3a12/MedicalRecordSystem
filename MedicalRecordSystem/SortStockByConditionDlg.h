#pragma once
//-----------------------------------------------------------------------------
#include "StockDataStruct.h"
//-----------------------------------------------------------------------------

// SortStockByConditionDlg 對話方塊

class SortStockByConditionDlg : public CDialogEx
{
	DECLARE_DYNAMIC(SortStockByConditionDlg)

public:
	SortStockByConditionDlg(CWnd* pParent = nullptr);   // 標準建構函式
	virtual ~SortStockByConditionDlg();

public:
	void SetStockDB(StockDataStructVecT stockDB) { mStockDB = stockDB; };

// 對話方塊資料
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_SortStockByCondition };
#endif

private:
	StockDataStructVecT mStockDB;
	int mSortType;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支援

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonSortstockexecute();
};
