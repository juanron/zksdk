
// libzkfpDemoDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "libzkfpDemo.h"
#include "libzkfpDemoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

RGBQUAD g_GrayTable[256] = {0x0};



// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// ClibzkfpDemoDlg �Ի���




ClibzkfpDemoDlg::ClibzkfpDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(ClibzkfpDemoDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_hDBCache = NULL;
	m_hDevice = NULL;
	m_bStopThread = FALSE;
	m_hThreadWork = NULL;
	m_Tid = 1;
	m_bRegister = FALSE;
	m_pImgBuf = NULL;
}

void ClibzkfpDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(ClibzkfpDemoDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BTN_CONN, &ClibzkfpDemoDlg::OnBnClickedBtnConn)
	ON_BN_CLICKED(IDC_BTN_DISCONN, &ClibzkfpDemoDlg::OnBnClickedBtnDisconn)
	ON_BN_CLICKED(IDC_BTN_REG, &ClibzkfpDemoDlg::OnBnClickedBtnReg)
	ON_BN_CLICKED(IDC_BTN_DBCLEAR, &ClibzkfpDemoDlg::OnBnClickedBtnDbclear)
	ON_BN_CLICKED(IDC_BTN_VERIFY, &ClibzkfpDemoDlg::OnBnClickedBtnVerify)
	ON_BN_CLICKED(IDC_BTN_IDENTIFY, &ClibzkfpDemoDlg::OnBnClickedBtnIdentify)
	ON_WM_CLOSE()
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BTN_REG_BY_IMG, &ClibzkfpDemoDlg::OnBnClickedBtnRegByImg)
	ON_BN_CLICKED(IDC_BTN_IDENTIFY_BY_IMG, &ClibzkfpDemoDlg::OnBnClickedBtnIdentifyByImg)
END_MESSAGE_MAP()


// ClibzkfpDemoDlg ��Ϣ�������

BOOL ClibzkfpDemoDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	GetDlgItem(IDC_BTN_CONN)->EnableWindow(TRUE);
	GetDlgItem(IDC_BTN_DISCONN)->EnableWindow(FALSE);
	GetDlgItem(IDC_BTN_REG)->EnableWindow(FALSE);
	GetDlgItem(IDC_BTN_DBCLEAR)->EnableWindow(FALSE);
	GetDlgItem(IDC_BTN_VERIFY)->EnableWindow(FALSE);
	GetDlgItem(IDC_BTN_IDENTIFY)->EnableWindow(FALSE);
	m_nLastRegTempLen = 0;
	for(int i = 0; i < 256; i++)
	{
		g_GrayTable[i].rgbRed = i;
		g_GrayTable[i].rgbGreen = i;
		g_GrayTable[i].rgbBlue = i;
		g_GrayTable[i].rgbReserved = 0;
	}
	m_bIdentify = TRUE;
	m_bRegister = FALSE;
	m_hDBCache = NULL;
	m_hDevice = NULL;
	m_bStopThread = FALSE;
	m_hThreadWork = NULL;
	m_nFakeFunOn = 0;
	memset(m_szLastRegTemplate, 0x0, MAX_TEMPLATE_SIZE);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void ClibzkfpDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void ClibzkfpDemoDlg::OnPaint()
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
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR ClibzkfpDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void ClibzkfpDemoDlg::ShowImage(unsigned char* pImgBuf)
{
	ShowImage(pImgBuf, m_imgFPWidth, m_imgFPHeight);
}

void ClibzkfpDemoDlg::ShowImage(unsigned char* pImgBuf, int width, int height)
{
	CImage *cimFP = NULL;
	CStatic *imgFP = (CStatic *)GetDlgItem(IDC_STC_FPIMG);
	if (NULL == imgFP)
	{
		return;
	}
	CDC *cdcFP = imgFP->GetDC();
	if (NULL == cdcFP)
	{
		return;
	}
	HDC hdcFP = cdcFP->m_hDC;
	if (NULL == hdcFP)
	{
		return;
	}
	cdcFP->SetStretchBltMode(HALFTONE);

	cimFP = new CImage();
	cimFP->Create(width, height, 8);
	cimFP->SetColorTable(0, 256, g_GrayTable);
	for(int i = 0; i < height; i++)
	{				
		memcpy(cimFP->GetPixelAddress(0, i), (unsigned char*)pImgBuf + width * i, width);
	}			
	//������ʾ
	cimFP->StretchBlt(hdcFP, 0, 0, width, height);
	if(cimFP)
	{
		cimFP->Destroy();
		delete cimFP;
	}
	return;
}

DWORD WINAPI ClibzkfpDemoDlg::ThreadCapture(LPVOID lParam)
{
	ClibzkfpDemoDlg* pDlg = (ClibzkfpDemoDlg*)lParam;
	if (NULL != pDlg)
	{
		pDlg->m_bStopThread = FALSE;
		while(!pDlg->m_bStopThread)
		{
			unsigned char szTemplate[MAX_TEMPLATE_SIZE];
			unsigned int tempLen = MAX_TEMPLATE_SIZE;
			int ret = ZKFPM_AcquireFingerprint(pDlg->m_hDevice, pDlg->m_pImgBuf, pDlg->m_imgFPWidth*pDlg->m_imgFPHeight, szTemplate, &tempLen);
			if (ZKFP_ERR_OK == ret)
			{
				if (1 == pDlg->m_nFakeFunOn)	//FakeFinger Test
				{
					int nFakeStatus = 0;
					unsigned int retLen = sizeof(int);
					if (0 == ZKFPM_GetParameters(pDlg->m_hDevice, 2004, (unsigned char*)&nFakeStatus, &retLen))
					{
						if ((nFakeStatus & 31) != 31)
						{
							pDlg->SetDlgItemText(IDC_EDIT_RESULT, _T("Is Fake Finger?"));
							continue;
						}
					}
				}
				pDlg->ShowImage(pDlg->m_pImgBuf);
				if(pDlg->m_bRegister)
				{
					pDlg->DoRegister(szTemplate, tempLen);
				}
				else
				{
					pDlg->DoVerify(szTemplate, tempLen);
				}
			}
			
			Sleep(100);
		}
	}
	return 0;
}

void ClibzkfpDemoDlg::DoVerify(unsigned char* temp, int len)
{
	if (m_nLastRegTempLen > 0)	//have enroll one more template
	{
		CString strLog;
		if (m_bIdentify)
		{
			int ret = ZKFP_ERR_OK;
			unsigned int tid = 0;
			unsigned int score = 0;
			ret = ZKFPM_Identify(m_hDBCache, temp, len, &tid, &score);
			if (ZKFP_ERR_OK != ret)
			{
				strLog.Format(_T("Identify fail, ret = %d"), ret);
				SetDlgItemText(IDC_EDIT_RESULT, strLog);
			}
			else
			{
				strLog.Format(_T("Identify succ, tid=%d, score=%d"), tid, score);
				SetDlgItemText(IDC_EDIT_RESULT, strLog);
			}
		}
		else
		{
			int ret = ZKFPM_MatchFinger(m_hDBCache, m_szLastRegTemplate, m_nLastRegTempLen, temp, len);
			if (ZKFP_ERR_OK > ret)
			{
				strLog.Format(_T("Match finger fail, ret = %d"), ret);
				SetDlgItemText(IDC_EDIT_RESULT, strLog);
			}
			else
			{
				strLog.Format(_T("Match succ, score=%d"), ret);
				SetDlgItemText(IDC_EDIT_RESULT, strLog);
			}
		}
	}
	else
	{
		SetDlgItemText(IDC_EDIT_RESULT, _T("You need enroll a reg-template first!"));
	}
}

void ClibzkfpDemoDlg::DoRegister(unsigned char* temp, int len)
{
	CString strLog;
	if (m_enrollIdx >= ENROLLCNT)
	{
		m_enrollIdx = 0;	//restart enroll
		return;
	}
	if (m_enrollIdx > 0)
	{
		if (0 >= ZKFPM_MatchFinger(m_hDBCache, m_arrPreRegTemps[m_enrollIdx-1], m_arrPreTempsLen[m_enrollIdx-1], temp, len))
		{
			m_enrollIdx = 0;
			m_bRegister = FALSE;
			SetDlgItemText(IDC_EDIT_RESULT, _T("Please press the same finger while registering"));
			return;
		}
	}
	m_arrPreTempsLen[m_enrollIdx] = len;
	memcpy(m_arrPreRegTemps[m_enrollIdx], temp, len);
	if (++m_enrollIdx >= ENROLLCNT)
	{
		int ret = 0;
		unsigned char szRegTemp[MAX_TEMPLATE_SIZE] = {0x0};
		unsigned int cbRegTemp = MAX_TEMPLATE_SIZE;
		ret = ZKFPM_GenRegTemplate(m_hDBCache, m_arrPreRegTemps[0], m_arrPreRegTemps[1], m_arrPreRegTemps[2], szRegTemp, &cbRegTemp);
		m_enrollIdx = 0;
		m_bRegister = FALSE;
		if (ZKFP_ERR_OK == ret)
		{
			ret = ZKFPM_AddRegTemplateToDBCache(m_hDBCache, m_Tid++, szRegTemp, cbRegTemp);
			if (ZKFP_ERR_OK == ret)
			{
				memcpy(m_szLastRegTemplate, szRegTemp, cbRegTemp);
				m_nLastRegTempLen = cbRegTemp;
				SetDlgItemText(IDC_EDIT_RESULT, _T("Register succ"));
			}
			else
			{
				strLog.Format(_T("Register fail, because add to db fail, ret=%d"), ret);
				SetDlgItemText(IDC_EDIT_RESULT, strLog);
			}
		}
		else
		{
			SetDlgItemText(IDC_EDIT_RESULT, _T("Register fail"));
			return;
		}
	}
	else
	{
		strLog.Format(_T("You still need press %d times finger"), ENROLLCNT-m_enrollIdx);
		SetDlgItemText(IDC_EDIT_RESULT, strLog);
	}
}

void ClibzkfpDemoDlg::OnBnClickedBtnConn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (NULL == m_hDevice)
	{
		if (ZKFPM_Init() != ZKFP_ERR_OK)
		{
			SetDlgItemText(IDC_EDIT_RESULT, _T("Init ZKFPM fail"));
			return;
		}
		if ((m_hDevice = ZKFPM_OpenDevice(0) ) == NULL)
		{
			SetDlgItemText(IDC_EDIT_RESULT, _T("Open sensor fail"));
			ZKFPM_Terminate();
			return;
		}
		m_hDBCache = ZKFPM_CreateDBCache();
		if (NULL == m_hDBCache)
		{
			SetDlgItemText(IDC_EDIT_RESULT, _T("Create DBCache fail"));
			ZKFPM_CloseDevice(m_hDevice);
			ZKFPM_Terminate();
			return;
		}
		/*int nDPI = 750;
		ZKFPM_SetParameters(m_hDevice, 3, (unsigned char*)&nDPI, sizeof(int));*/
		//Set FakeFun On
		m_nFakeFunOn = 1;
		ZKFPM_SetParameters(m_hDevice, 2002, (unsigned char*)&m_nFakeFunOn, sizeof(int));

		TZKFPCapParams zkfpCapParams = {0x0};
		ZKFPM_GetCaptureParams(m_hDevice, &zkfpCapParams);
		m_imgFPWidth = zkfpCapParams.imgWidth;
		m_imgFPHeight = zkfpCapParams.imgHeight;
		m_pImgBuf = new unsigned char[m_imgFPWidth*m_imgFPHeight];
		m_nLastRegTempLen = 0;
		GetDlgItem(IDC_BTN_CONN)->EnableWindow(FALSE);
		GetDlgItem(IDC_BTN_DISCONN)->EnableWindow(TRUE);
		GetDlgItem(IDC_BTN_REG)->EnableWindow(TRUE);
		GetDlgItem(IDC_BTN_DBCLEAR)->EnableWindow(TRUE);
		GetDlgItem(IDC_BTN_VERIFY)->EnableWindow(TRUE);
		GetDlgItem(IDC_BTN_IDENTIFY)->EnableWindow(TRUE);
		m_hThreadWork = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ThreadCapture, this, 0, NULL);
		memset(&m_szLastRegTemplate, 0x0, sizeof(m_szLastRegTemplate));

		SetDlgItemText(IDC_EDIT_RESULT, _T("Init Succ"));
		m_Tid = 1;
		m_enrollIdx = 0;
		m_bRegister = FALSE;
	}
	else
	{
		SetDlgItemText(IDC_EDIT_RESULT, _T("Already Init"));
	}
}

void ClibzkfpDemoDlg::OnBnClickedBtnDisconn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (NULL != m_hDevice)
	{
		if (NULL != m_pImgBuf)
		{
			delete [] m_pImgBuf;
			m_pImgBuf = NULL;
		}
		m_bStopThread = TRUE;
		if (NULL != m_hThreadWork)
		{
			WaitForSingleObject(m_hThreadWork, INFINITE);
			CloseHandle(m_hThreadWork);
			m_hThreadWork = NULL;
		}
		if (NULL != m_hDBCache)
		{
			ZKFPM_CloseDBCache(m_hDBCache);
			m_hDBCache = NULL;
		}
		ZKFPM_CloseDevice(m_hDevice);
		ZKFPM_Terminate();
		m_hDevice = NULL;
		SetDlgItemText(IDC_EDIT_RESULT, _T("Close Succ"));
		m_Tid = 1;
		GetDlgItem(IDC_BTN_CONN)->EnableWindow(TRUE);
		GetDlgItem(IDC_BTN_DISCONN)->EnableWindow(FALSE);
		GetDlgItem(IDC_BTN_REG)->EnableWindow(FALSE);
		GetDlgItem(IDC_BTN_DBCLEAR)->EnableWindow(FALSE);
		GetDlgItem(IDC_BTN_VERIFY)->EnableWindow(FALSE);
		GetDlgItem(IDC_BTN_IDENTIFY)->EnableWindow(FALSE);
	}
}

void ClibzkfpDemoDlg::OnBnClickedBtnReg()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (NULL != m_hDevice)
	{
		if (!m_bRegister)
		{
			m_bRegister = TRUE;
			m_enrollIdx = 0;
			SetDlgItemText(IDC_EDIT_RESULT, _T("Doing register, please press your finger 3 times!"));
		}
	}
}

void ClibzkfpDemoDlg::OnBnClickedBtnDbclear()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (NULL != m_hDevice && NULL != m_hDBCache)
	{
		ZKFPM_ClearDBCache(m_hDBCache);
		SetDlgItemText(IDC_EDIT_RESULT, _T("IN-Memory DB Clear OK"));
		m_nLastRegTempLen = 0;
		m_Tid = 1;
	}
}

void ClibzkfpDemoDlg::OnBnClickedBtnVerify()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (NULL != m_hDevice)
	{
		if (m_bRegister)
		{
			m_bRegister = FALSE;
			SetDlgItemText(IDC_EDIT_RESULT, _T("Start verify last register template"));
		}
		m_bIdentify = FALSE;
	}
}

void ClibzkfpDemoDlg::OnBnClickedBtnIdentify()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (NULL != m_hDevice)
	{
		if (m_bRegister)
		{
			m_bRegister = FALSE;
			SetDlgItemText(IDC_EDIT_RESULT, _T("Start verify last register template"));
		}
		m_bIdentify = TRUE;
	}
}

void ClibzkfpDemoDlg::OnClose()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CDialog::OnClose();
}

void ClibzkfpDemoDlg::OnDestroy()
{
	CDialog::OnDestroy();

	// TODO: �ڴ˴������Ϣ����������
	OnBnClickedBtnDisconn();
}

void ClibzkfpDemoDlg::OnBnClickedBtnRegByImg()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (NULL == m_hDBCache)
	{
		SetDlgItemText(IDC_EDIT_RESULT, _T("Please connect device first"));
		return;
	}
	CString strFilePathName;
	CFileDialog dlg(TRUE, //TRUEΪOPEN�Ի���FALSEΪSAVE AS�Ի���
		NULL, 
		NULL,
		OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		(LPCTSTR)_TEXT("BMP Files (*.bmp)|*.bmp|JPG Files (*.jpg)|*.jpg|All Files (*.*)|*.*||"),
		NULL);
	if(dlg.DoModal()==IDOK)
	{
		strFilePathName=dlg.GetPathName(); //�ļ�����������FilePathName��
		unsigned char szTemp[MAX_TEMPLATE_SIZE] = {0x0};
		unsigned int sizeTemp = MAX_TEMPLATE_SIZE;
		CString strLog;
		int ret = ZKFPM_ExtractFromImage(m_hDBCache, strFilePathName.GetBuffer(), 500, szTemp, &sizeTemp);
		if (ZKFP_ERR_OK == ret)
		{
			int _width = 0;
			int _height = 0;
			unsigned char* pBuf = ZKFPM_GetLastExtractImage(&_width, &_height);
			ShowImage(pBuf, _width, _height);
			ret = ZKFPM_AddRegTemplateToDBCache(m_hDBCache, m_Tid++, szTemp, sizeTemp);
			if (ZKFP_ERR_OK == ret)
			{
				memcpy(m_szLastRegTemplate, szTemp, sizeTemp);
				m_nLastRegTempLen = sizeTemp;
				SetDlgItemText(IDC_EDIT_RESULT, _T("Register succ"));
			}
			else
			{
				strLog.Format(_T("Register fail, because add to db fail, ret=%d"), ret);
				SetDlgItemText(IDC_EDIT_RESULT, strLog);
			}
		}
		else
		{
			strLog.Format(_T("Extract Fail, ret = %d"), ret);
			SetDlgItemText(IDC_EDIT_RESULT, strLog);
		}
	}
	else
	{
		return;
	}
}

void ClibzkfpDemoDlg::OnBnClickedBtnIdentifyByImg()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (NULL == m_hDBCache)
	{
		SetDlgItemText(IDC_EDIT_RESULT, _T("Please connect device first"));
		return;
	}
	CString strFilePathName;
	CFileDialog dlg(TRUE, //TRUEΪOPEN�Ի���FALSEΪSAVE AS�Ի���
		NULL, 
		NULL,
		OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		(LPCTSTR)_TEXT("BMP Files (*.bmp)|*.bmp|JPG Files (*.jpg)|*.jpg|All Files (*.*)|*.*||"),
		NULL);
	if(dlg.DoModal()==IDOK)
	{
		strFilePathName=dlg.GetPathName(); //�ļ�����������FilePathName��
		unsigned char szTemp[MAX_TEMPLATE_SIZE] = {0x0};
		unsigned int sizeTemp = MAX_TEMPLATE_SIZE;
		CString strLog;
		int ret = ZKFPM_ExtractFromImage(m_hDBCache, strFilePathName.GetBuffer(), 500, szTemp, &sizeTemp);
		if (ZKFP_ERR_OK == ret)
		{
			int _width = 0;
			int _height = 0;
			unsigned char* pBuf = ZKFPM_GetLastExtractImage(&_width, &_height);
			ShowImage(pBuf, _width, _height);
			if (m_bIdentify)
			{
				int ret = ZKFP_ERR_OK;
				unsigned int tid = 0;
				unsigned int score = 0;
				ret = ZKFPM_Identify(m_hDBCache, szTemp, sizeTemp, &tid, &score);
				if (ZKFP_ERR_OK != ret)
				{
					strLog.Format(_T("Identify fail, ret = %d"), ret);
					SetDlgItemText(IDC_EDIT_RESULT, strLog);
				}
				else
				{
					strLog.Format(_T("Identify succ, tid=%d, score=%d"), tid, score);
					SetDlgItemText(IDC_EDIT_RESULT, strLog);
				}
			}
			else
			{
				int ret = ZKFPM_MatchFinger(m_hDBCache, m_szLastRegTemplate, m_nLastRegTempLen, szTemp, sizeTemp);
				if (ZKFP_ERR_OK > ret)
				{
					strLog.Format(_T("Match finger fail, ret = %d"), ret);
					SetDlgItemText(IDC_EDIT_RESULT, strLog);
				}
				else
				{
					strLog.Format(_T("Match succ, score=%d"), ret);
					SetDlgItemText(IDC_EDIT_RESULT, strLog);
				}
			}
		}
		else
		{
			strLog.Format(_T("Extract Fail, ret = %d"), ret);
			SetDlgItemText(IDC_EDIT_RESULT, strLog);
		}
	}
	else
	{
		return;
	}
}
