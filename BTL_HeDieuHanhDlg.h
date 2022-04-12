
// BTL_HeDieuHanhDlg.h : header file
//

#pragma once


// CBTLHeDieuHanhDlg dialog
class CBTLHeDieuHanhDlg : public CDialogEx
{
// Construction
public:
	CBTLHeDieuHanhDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BTL_HEDIEUHANH_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	CButton btn_det;
public:
	CListCtrl list_cont_;
};
