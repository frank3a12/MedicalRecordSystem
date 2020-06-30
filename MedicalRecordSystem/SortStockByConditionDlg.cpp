// SortStockByConditionDlg.cpp: 實作檔案
//

#include "pch.h"
#include "MedicalRecordSystem.h"
#include "SortStockByConditionDlg.h"
#include "afxdialogex.h"
//-----------------------------------------------------------------------------
#include <algorithm>
#include <sstream>
//-----------------------------------------------------------------------------

// SortStockByConditionDlg 對話方塊

IMPLEMENT_DYNAMIC(SortStockByConditionDlg, CDialogEx)

SortStockByConditionDlg::SortStockByConditionDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_SortStockByCondition, pParent)
	, mSortType(0)
{

}

SortStockByConditionDlg::~SortStockByConditionDlg()
{
}

void SortStockByConditionDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_RADIO_StockIndex, mSortType);
}


BEGIN_MESSAGE_MAP(SortStockByConditionDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_SortStockExecute, &SortStockByConditionDlg::OnBnClickedButtonSortstockexecute)
END_MESSAGE_MAP()


// SortStockByConditionDlg 訊息處理常式
//-----------------------------------------------------------------------------

void SortStockByConditionDlg::OnBnClickedButtonSortstockexecute()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	//----------------------------------------------------------------------------
	// 取得使用者參數
	UpdateData(TRUE);

	// 開始排序
	CString title = L"";
	if (mSortType == 0) {
		std::sort(mStockDB.begin(), mStockDB.end(), CompareType::CompareByStockIndex);
		title = L"股票代號";
	}
	else if (mSortType == 1) {
		std::sort(mStockDB.begin(), mStockDB.end(), CompareType::CompareByStockPrice);
		title = L"股價";
	}
	else if (mSortType == 2) {
		std::sort(mStockDB.begin(), mStockDB.end(), CompareType::CompareByCashDividend);
		title = L"現金股利";
	}
	else if (mSortType == 3) {
		std::sort(mStockDB.begin(), mStockDB.end(), CompareType::CompareByCashDividendYield);
		title = L"現金股利殖利率";
	}
	else if (mSortType == 4) {
		std::sort(mStockDB.begin(), mStockDB.end(), CompareType::CompareByEPS);
		title = L"EPS";
	}
	else if (mSortType == 5) {
		std::sort(mStockDB.begin(), mStockDB.end(), CompareType::CompareByROE);
		title = L"ROE";
	}

	// 顯示結果
	CString result = L"按照 " + title + L" 排序結果:\n";
	for (int i = 0; i < mStockDB.size(); i++) {
		StockDataStruct currData = mStockDB[i];
		
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
		tmpStr.erase(tmpStr.find_first_of('.') + 4, std::string::npos);
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