// prjZip.h : prjZip DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CprjZipApp
// �йش���ʵ�ֵ���Ϣ������� prjZip.cpp
//

class CprjZipApp : public CWinApp
{
public:
	CprjZipApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
