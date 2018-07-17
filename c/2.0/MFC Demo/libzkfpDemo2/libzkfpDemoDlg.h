
// libzkfpDemoDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"

#define ENROLLCNT 3


// ClibzkfpDemoDlg �Ի���
class ClibzkfpDemoDlg : public CDialog
{
// ����
public:
	ClibzkfpDemoDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_LIBZKFPDEMO_DIALOG };

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
	HANDLE m_hDevice;
	HANDLE m_hDBCache;
	HANDLE m_hThreadWork;
	int m_imgFPWidth;
	int m_imgFPHeight;
	BOOL m_bIdentify;
	BOOL m_bRegister;
	BOOL m_bStopThread;
	int m_enrollIdx;
	
	unsigned char m_arrPreRegTemps[ENROLLCNT][MAX_TEMPLATE_SIZE];
	unsigned int m_arrPreTempsLen[3];
	int m_Tid;

	unsigned char* m_pImgBuf;

	//Last register template, use for verify
	unsigned char m_szLastRegTemplate[MAX_TEMPLATE_SIZE];
	int m_nLastRegTempLen;
	int m_nFakeFunOn;

	void DoRegister(unsigned char* temp, int len);
	void DoVerify(unsigned char* temp, int len);
	void ShowImage(unsigned char* pImgBuf);
	void ShowImageFile(char* FileName);
	void ShowImage(unsigned char* pImgBuf, int width, int height);
	static DWORD WINAPI ThreadCapture(LPVOID lParam);
	
	afx_msg void OnBnClickedBtnConn();
	afx_msg void OnBnClickedBtnDisconn();
	afx_msg void OnBnClickedBtnReg();
	afx_msg void OnBnClickedBtnDbclear();
	afx_msg void OnBnClickedBtnVerify();
	afx_msg void OnBnClickedBtnIdentify();
	afx_msg void OnClose();
	afx_msg void OnDestroy();
	afx_msg void OnBnClickedBtnRegByImg();
	afx_msg void OnBnClickedBtnIdentifyByImg();
};
