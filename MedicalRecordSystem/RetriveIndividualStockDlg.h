#pragma once


// RetriveIndividualStockDlg 對話方塊

class RetriveIndividualStockDlg : public CDialogEx
{
	DECLARE_DYNAMIC(RetriveIndividualStockDlg)

public:
	RetriveIndividualStockDlg(CWnd* pParent = nullptr);   // 標準建構函式
	virtual ~RetriveIndividualStockDlg();

// 對話方塊資料
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_RetriveIndividualStock };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支援

	DECLARE_MESSAGE_MAP()
};
