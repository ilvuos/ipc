
// serverDlg.h : ͷ�ļ�
//

#pragma once
#include "XBroadCastServer.h"
#include "MonitorFun.h"
#include "BClientFun.h"
// CserverDlg �Ի���
class CserverDlg : public CDialogEx
{
// ����
public:
	CserverDlg(CWnd* pParent = NULL);	// ��׼���캯��
	CMonitorFun       mMonitor;
	CBClientFun       mBClient;
// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SERVER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
};
