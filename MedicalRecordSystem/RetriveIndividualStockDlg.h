#pragma once
//-----------------------------------------------------------------------------
#include "StockDataStruct.h"
//-----------------------------------------------------------------------------

// RetriveIndividualStockDlg 對話方塊

class RetriveIndividualStockDlg : public CDialogEx
{
	DECLARE_DYNAMIC(RetriveIndividualStockDlg)

public:
	RetriveIndividualStockDlg(CWnd* pParent = nullptr);   // 標準建構函式
	virtual ~RetriveIndividualStockDlg();

public:
	void SetStockDB(StockDataStructVecT stockDB) { mStockDB = stockDB; };

// 對話方塊資料
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_RetriveIndividualStock };
#endif

private:
	StockDataStructVecT mStockDB;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支援

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonRetriveindividualstocksearch();
};
