// RetriveIndividualStockDlg.cpp: 實作檔案
//

#include "pch.h"
#include "MedicalRecordSystem.h"
#include "RetriveIndividualStockDlg.h"
#include "afxdialogex.h"


// RetriveIndividualStockDlg 對話方塊

IMPLEMENT_DYNAMIC(RetriveIndividualStockDlg, CDialogEx)

RetriveIndividualStockDlg::RetriveIndividualStockDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_RetriveIndividualStock, pParent)
{

}

RetriveIndividualStockDlg::~RetriveIndividualStockDlg()
{
}

void RetriveIndividualStockDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(RetriveIndividualStockDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_RetriveIndividualStockSearch, &RetriveIndividualStockDlg::OnBnClickedButtonRetriveindividualstocksearch)
END_MESSAGE_MAP()


// RetriveIndividualStockDlg 訊息處理常式


void RetriveIndividualStockDlg::OnBnClickedButtonRetriveindividualstocksearch()
{
	// TODO: 在此加入控制項告知處理常式程式碼

	// Get StockIndex
	CString stockIndex;
	GetDlgItem(IDC_EDIT_RetriveIndividualStockIndex)->GetWindowTextW(stockIndex);


}
