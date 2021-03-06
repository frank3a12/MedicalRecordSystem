// SelectStockByConditionDlg.cpp: 實作檔案
//

#include "pch.h"
#include "MedicalRecordSystem.h"
#include "SelectStockByConditionDlg.h"
#include "afxdialogex.h"
#include "SimpleInputDlg.h"
//-----------------------------------------------------------------------------
#include <algorithm>
#include <string>
//-----------------------------------------------------------------------------

// SelectStockByConditionDlg 對話方塊

IMPLEMENT_DYNAMIC(SelectStockByConditionDlg, CDialogEx)

SelectStockByConditionDlg::SelectStockByConditionDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_SelectStockByCondition, pParent)
	, mUserBudget(0)
{

}

SelectStockByConditionDlg::~SelectStockByConditionDlg()
{
}

void SelectStockByConditionDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_TotalBudget, mUserBudget);
	DDX_Control(pDX, IDC_COMBO_RecommandType, mSelectComboBox);
}


BEGIN_MESSAGE_MAP(SelectStockByConditionDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_RecommandExecute, &SelectStockByConditionDlg::OnBnClickedButtonRecommandexecute)
END_MESSAGE_MAP()


// SelectStockByConditionDlg 訊息處理常式

//實作GreedyAlgorithm
//-----------------------------------------------------------------------------
void SelectStockByConditionDlg::FindBestCashDividendGreedy(int budget)
{
	CString result = L"";

	//先依照 現金股利 排序
	std::sort(mStockDB.begin(), mStockDB.end(), CompareType::CompareByCashDividend);

	//依序買，買到買不起為止
	int usedBudget = 0;
	int totalCashDividend = 0;
	for (unsigned int i = mStockDB.size() - 1; i > 0; i--) {
		StockDataStruct data = mStockDB[i];
		if (data.stockPrice * 1000 > (budget - usedBudget)) continue;	//此股票貴到超過預算，就只能pass

		while (usedBudget < budget && (budget - usedBudget) > data.stockPrice * 1000) {	//預算還有剩，而且剩下的預算夠買這檔
			result += L"買了一張股票代號(" + CString(std::to_wstring(data.stockIndex).c_str()) + L")的股票，價值" 
				+ CString(std::to_wstring(data.stockPrice * 1000).c_str()) + L"\n";
			usedBudget += data.stockPrice * 1000;
			totalCashDividend += data.cashDividend;
		}
	}
	result += L"最後剩下: " + CString(std::to_wstring(budget - usedBudget).c_str()) + L"元, ";
	result += L"累計股利: " + CString(std::to_wstring(totalCashDividend * 1000).c_str()) + L"元";

	::AfxMessageBox(result);
}

void SelectStockByConditionDlg::FindBestROEGreedy(int budget)
{
	CString result = L"";

	//先依照 ROE 排序
	std::sort(mStockDB.begin(), mStockDB.end(), CompareType::CompareByROE);

	//依序買，買到買不起為止
	int usedBudget = 0;
	for (unsigned int i = mStockDB.size() - 1; i > 0; i--) {
		StockDataStruct data = mStockDB[i];
		if (data.stockPrice * 1000 > (budget - usedBudget)) continue;	//此股票貴到超過預算，就只能pass

		while (usedBudget < budget && (budget - usedBudget) > data.stockPrice * 1000) {	//預算還有剩，而且剩下的預算夠買這檔
			result += L"買了一張股票代號(" + CString(std::to_wstring(data.stockIndex).c_str()) + L")的股票，價值"
				+ CString(std::to_wstring(data.stockPrice * 1000).c_str()) + L"\n";
			usedBudget += data.stockPrice * 1000;
		}
	}
	result += L"最後剩下: " + CString(std::to_wstring(budget - usedBudget).c_str()) + L"元";

	::AfxMessageBox(result);
}

//實作Dynamic Programming
//-----------------------------------------------------------------------------
void SelectStockByConditionDlg::FindBestTenDaySetDP(int budget, int stockIndex)
{
	CString result = L"";
	
	// Sort by Index
	std::sort(mStockDB.begin(), mStockDB.end(), CompareType::CompareByStockIndex);

	// Binary Search
	int index = SearchType::BinarySearch(mStockDB, (int)mStockDB.size(), stockIndex);
	if (index == -1)
		result = L"DB內無此資料!";
	else {

		// Start DP
		double hold[10];
		double rele[10];
		for (int i = 0; i < 10; ++i) {
			hold[i] = INT_MIN;
			rele[i] = 0;
		}
		double cur;
		for (int i = 0; i < 10; ++i) {
			cur = mStockDB[index].tenDaysPrices[i];
			for (int j = 9; j > 0; --j) {
				rele[j] = max(rele[j], hold[j] + cur);
				hold[j] = max(hold[j], rele[j - 1] - cur);
			}
		}

		result = L"最大獲利：" + CString(std::to_wstring(int(rele[9] * 1000)).c_str()) + L"元";
	}

	::AfxMessageBox(result);
}

void SelectStockByConditionDlg::OnBnClickedButtonRecommandexecute()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	//

	// 取得使用者參數
	UpdateData(TRUE);
	int currentSelect = mSelectComboBox.GetCurSel();

	// 根據不同選擇來做
	if (currentSelect == 0) {
		// 找現金股利總和最高
		FindBestCashDividendGreedy(mUserBudget);
	}
	else if (currentSelect == 1) {
		// 找ROE總和最高
		FindBestROEGreedy(mUserBudget);
	}
	else if (currentSelect == 2) {
		
		// 先讓User選擇要哪一檔
		SimpleInputDlg dlg;
		if (dlg.DoModal() != IDOK)
			return;
		int stockIndex = dlg.userValue;

		// 找10日最佳投資組合
		FindBestTenDaySetDP(mUserBudget, stockIndex);
	}
	else
		::AfxMessageBox(L"出現未預期的選擇");
}

