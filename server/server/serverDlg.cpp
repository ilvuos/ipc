
// serverDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "server.h"
#include "serverDlg.h"
#include "afxdialogex.h"
#include "SUserConfig.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CserverDlg �Ի���



CserverDlg::CserverDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_SERVER_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CserverDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CserverDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CserverDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CserverDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CserverDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CserverDlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// CserverDlg ��Ϣ�������

BOOL CserverDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CserverDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CserverDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CserverDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//�����㲥����������
void CserverDlg::OnBnClickedButton1()
{
	if (mMonitor.IsExist())
	{
		mMonitor.Stop();
		return;
	}
	mMonitor.Start();
}

//�����㲥�����ͻ���
void CserverDlg::OnBnClickedButton2()
{
	if (mBClient.IsExist())
	{
		mBClient.Stop();
		return;
	}
	mBClient.Start();
}


void CserverDlg::OnBnClickedButton3()
{
	int hour, min, second;
	int day, mon, year;
	char status=0;
	float N=0.0,E=0.0,su=0.0;
	char buff[128] = "$GPRMC,094213.00,A,2231.54351,N,11401.84251,E,6.976,202.58,220217,,,A*6F";
	//char buff[128] = "$GPRMC,094212.00,V,,,,,,,220217,,,N*75";
	char outBuf[128];
	int i=0,m=0;
	int count = strlen(buff);
	while (i<count)
	{
		if (buff[i] == ',')
		{
			m++;
			i++;
		}
		else {
			 i++;
	    	continue;
    	}

		if (m == 1)
		{
			sscanf_s(&buff[i], "%2d%2d%2d", &hour, &min, &second);
		}
		else if (m == 2)
		{
			sscanf_s(&buff[i], "%c",&status);

		}
		else if (m == 3)
		{
			sscanf_s(&buff[i], "%f",&N);
		}
		else if (m == 5)
		{
			sscanf_s(&buff[i], "%f",&E);
		}
		else if (m == 7)
		{
			sscanf_s(&buff[i], "%f",&su);
		}
		else if (m == 9)
		{
			sscanf_s(&buff[i], "%2d%2d%2d", &day, &mon, &year);
		}
	
		i++;
	}
	sprintf_s(outBuf, "%04d/%02d/%02d %02d:%02d:%02d N:%f E:%f %f km/h x:+0.000 y:+0.000 z:+0.000", year+2000, mon,day, hour,min,second,N,E,su);
}


void CserverDlg::OnBnClickedButton4()
{
	/*
	int   fd, size;   
	char  buffer[1024];  
	fd = open("/tmp/temp", O_WRONLY | O_CREAT); 
	read(fd, buffer,1024);
	close(fd);  
	fd = open("/tmp/temp", O_RDONLY);
	size = read(fd, buffer, sizeof(buffer));    
	close(fd);  
	TRACE("%s", buffer);
	*/
	CSUserConfig test;
	test.Open("D:\\kevin\\server\\server\\Debug\\user_config.xml",NULL);
	test.Remove(0x13);
}
