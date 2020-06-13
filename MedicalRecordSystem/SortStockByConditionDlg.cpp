// SortStockByConditionDlg.cpp: 實作檔案
//

#include "pch.h"
#include "MedicalRecordSystem.h"
#include "SortStockByConditionDlg.h"
#include "afxdialogex.h"


// SortStockByConditionDlg 對話方塊

IMPLEMENT_DYNAMIC(SortStockByConditionDlg, CDialogEx)

SortStockByConditionDlg::SortStockByConditionDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_SortStockByCondition, pParent)
{

}

SortStockByConditionDlg::~SortStockByConditionDlg()
{
}

void SortStockByConditionDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(SortStockByConditionDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_SortStockExecute, &SortStockByConditionDlg::OnBnClickedButtonSortstockexecute)
END_MESSAGE_MAP()


// SortStockByConditionDlg 訊息處理常式


void SortStockByConditionDlg::OnBnClickedButtonSortstockexecute()
{
	// TODO: 在此加入控制項告知處理常式程式碼
}
