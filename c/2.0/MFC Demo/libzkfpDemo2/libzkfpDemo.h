
// libzkfpDemo.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// ClibzkfpDemoApp:
// �йش����ʵ�֣������ libzkfpDemo.cpp
//

class ClibzkfpDemoApp : public CWinAppEx
{
public:
	ClibzkfpDemoApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern ClibzkfpDemoApp theApp;