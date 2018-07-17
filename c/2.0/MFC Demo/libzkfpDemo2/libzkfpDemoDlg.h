
// libzkfpDemoDlg.h : 头文件
//

#pragma once
#include "afxwin.h"

#define ENROLLCNT 3


// ClibzkfpDemoDlg 对话框
class ClibzkfpDemoDlg : public CDialog
{
// 构造
public:
	ClibzkfpDemoDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_LIBZKFPDEMO_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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
