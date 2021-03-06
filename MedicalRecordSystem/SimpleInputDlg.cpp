// SimpleInputDlg.cpp: 實作檔案
//

#include "pch.h"
#include "MedicalRecordSystem.h"
#include "SimpleInputDlg.h"
#include "afxdialogex.h"


// SimpleInputDlg 對話方塊

IMPLEMENT_DYNAMIC(SimpleInputDlg, CDialogEx)

SimpleInputDlg::SimpleInputDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_SimpleInputDlg, pParent), userValue(0)
{

}

SimpleInputDlg::~SimpleInputDlg()
{
}

void SimpleInputDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_SimpleInput, userValue);
}


BEGIN_MESSAGE_MAP(SimpleInputDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &SimpleInputDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// SimpleInputDlg 訊息處理常式


void SimpleInputDlg::OnBnClickedOk()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	UpdateData(TRUE);

	CDialogEx::OnOK();
}
