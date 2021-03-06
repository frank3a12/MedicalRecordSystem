// RetriveIndividualStockDlg.cpp: 實作檔案
//

#include "pch.h"
#include "MedicalRecordSystem.h"
#include "RetriveIndividualStockDlg.h"
#include "afxdialogex.h"
//-----------------------------------------------------------------------------
#include <algorithm>
#include <sstream>
//-----------------------------------------------------------------------------

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

	// Sort by index
	std::sort(mStockDB.begin(), mStockDB.end(), CompareType::CompareByStockIndex);

	// Get StockIndex
	CString stockIndexStr;
	GetDlgItem(IDC_EDIT_RetriveIndividualStockIndex)->GetWindowTextW(stockIndexStr);
	int stockIndex = _wtoi(stockIndexStr);

	// Binary search
	int index = SearchType::BinarySearch(mStockDB, (int)mStockDB.size(), stockIndex);

	// 顯示結果
	CString result = L"";

	if (index == -1)
		result = L"DB內無此資料!";
	else 
	{
		StockDataStruct currData = mStockDB[index];
		std::wstring tmpStr;
		tmpStr = std::to_wstring(currData.stockIndex);
		result += (L"代號: " + CString(tmpStr.c_str()) + L", ");

		tmpStr = std::to_wstring(currData.stockPrice);
		tmpStr.erase(tmpStr.find_first_of('.') + 3, std::string::npos);
		result += (L"股價: " + CString(tmpStr.c_str()) + L", ");

		tmpStr = std::to_wstring(currData.cashDividend);
		tmpStr.erase(tmpStr.find_first_of('.') + 3, std::string::npos);
		result += (L"股利: " + CString(tmpStr.c_str()) + L", ");

		tmpStr = std::to_wstring(currData.cashDividendYield);
		tmpStr.erase(tmpStr.find_first_of('.') + 3, std::string::npos);
		result += (L"殖利率: " + CString(tmpStr.c_str()) + L", ");

		tmpStr = std::to_wstring(currData.EPS);
		tmpStr.erase(tmpStr.find_first_of('.') + 3, std::string::npos);
		result += (L"EPS: " + CString(tmpStr.c_str()) + L", ");

		tmpStr = std::to_wstring(currData.ROE);
		tmpStr.erase(tmpStr.find_first_of('.') + 3, std::string::npos);
		result += (L"ROE: " + CString(tmpStr.c_str()) + L"\n");
	}

	::AfxMessageBox(result);
}
