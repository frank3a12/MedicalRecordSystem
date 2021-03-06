#pragma once


// SimpleInputDlg 對話方塊

class SimpleInputDlg : public CDialogEx
{
	DECLARE_DYNAMIC(SimpleInputDlg)

public:
	SimpleInputDlg(CWnd* pParent = nullptr);   // 標準建構函式
	virtual ~SimpleInputDlg();

	int userValue;

// 對話方塊資料
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_SimpleInputDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支援

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
