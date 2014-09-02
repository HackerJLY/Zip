// prjZip.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "prjZip.h"

#include "..\ZipUnzip\Zipper.h"
#include "..\ZipUnzip\Unzipper.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO: ����� DLL ����� MFC DLL �Ƕ�̬���ӵģ�
//		��Ӵ� DLL �������κε���
//		MFC �ĺ������뽫 AFX_MANAGE_STATE ����ӵ�
//		�ú�������ǰ�档
//
//		����:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// �˴�Ϊ��ͨ������
//		}
//
//		�˺������κ� MFC ����
//		������ÿ��������ʮ����Ҫ������ζ��
//		��������Ϊ�����еĵ�һ�����
//		���֣������������ж������������
//		������Ϊ���ǵĹ��캯���������� MFC
//		DLL ���á�
//
//		�й�������ϸ��Ϣ��
//		����� MFC ����˵�� 33 �� 58��
//

// CprjZipApp

BEGIN_MESSAGE_MAP(CprjZipApp, CWinApp)
END_MESSAGE_MAP()


// CprjZipApp ����

CprjZipApp::CprjZipApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CprjZipApp ����

CprjZipApp theApp;


// CprjZipApp ��ʼ��

BOOL CprjZipApp::InitInstance()
{
	CWinApp::InitInstance();

	if (!AfxSocketInit())
	{
		AfxMessageBox(IDP_SOCKETS_INIT_FAILED);
		return FALSE;
	}

	return TRUE;
}


BOOL ZipFileEx(LPCTSTR szFilePath) // saves as same name with .zip
{
	bool bRetrun = false;
	
	//=======================================================================================

	bRetrun = CZipper::ZipFile(szFilePath);
	if(!bRetrun)
	{
		return FALSE;
	}

	return TRUE;
}

BOOL ZipFolderEx(LPCTSTR szFilePath, bool bIgnoreFilePath) // saves as same name with .zip
{
	bool bRetrun = false;
	
	//=======================================================================================

	bRetrun = CZipper::ZipFolder(szFilePath, bIgnoreFilePath);
	if(!bRetrun)
	{
		return FALSE;
	}

	return TRUE;
}

// simple interface
BOOL UnzipEx(LPCTSTR szFileName, LPCTSTR szFolder, bool bIgnoreFilePath)
{
	bool bRetrun = false;
	
	//=======================================================================================

	bRetrun = CUnzipper::Unzip(szFileName, szFolder, bIgnoreFilePath);
	if(!bRetrun)
	{
		return FALSE;
	}

	return TRUE;
}