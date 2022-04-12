
// BTL_HeDieuHanhDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "BTL_HeDieuHanh.h"
#include "BTL_HeDieuHanhDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CBTLHeDieuHanhDlg dialog



CBTLHeDieuHanhDlg::CBTLHeDieuHanhDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_BTL_HEDIEUHANH_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBTLHeDieuHanhDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, ID_BTN_DET, btn_det);
	DDX_Control(pDX, ID_LIST_CONT, list_cont_);
}

BEGIN_MESSAGE_MAP(CBTLHeDieuHanhDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CBTLHeDieuHanhDlg message handlers

BOOL CBTLHeDieuHanhDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	list_cont_.SetExtendedStyle(
		LVS_EX_FULLROWSELECT |	// Kiểu này cho phép chọn toàn bộ hàng của chế độ xem Báo cáo thay vì chỉ mục
		LVS_EX_GRIDLINES		// Các mục của điều khiển trong chế độ xem Báo cáo sẽ hiển thị với các đường lưới ngang phân tách các mục và các đường lưới dọc phân tách các mục hoặc danh mục cột
	);
	list_cont_.InsertColumn(
		0,				//Vị trí
		_T("Name"),		//Tên
		LVCFMT_LEFT,	// Căn lề
		200				// Độ rộng
	);
	list_cont_.InsertColumn(
		1,				//Vị trí
		_T("Status"),	//Tên
		LVCFMT_LEFT,	// Căn lề
		100				// Độ rộng
	);
	list_cont_.InsertColumn(
		2,				//Vị trí
		_T("CPU"),		//Tên
		LVCFMT_LEFT,	// Căn lề
		50				// Độ rộng
	);
	list_cont_.InsertColumn(
		3,				//Vị trí
		_T("Memory"),	//Tên
		LVCFMT_LEFT,	// Căn lề
		50				// Độ rộng
	);
	list_cont_.InsertColumn(
		4,				//Vị trí
		_T("Disk"),	//Tên
		LVCFMT_LEFT,	// Căn lề
		50				// Độ rộng
	);
	list_cont_.InsertColumn(
		5,				//Vị trí
		_T("Network"),	//Tên
		LVCFMT_LEFT,	// Căn lề
		60				// Độ rộng
	);

	list_cont_.InsertItem(0, _T("a"));
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CBTLHeDieuHanhDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CBTLHeDieuHanhDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CBTLHeDieuHanhDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

