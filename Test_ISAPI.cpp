// TEST_ISAPI.CPP - Implementation file for your Internet Server
//    Test_ISAPI Extension

#include "stdafx.h"
#include "Test_ISAPI.h"

///////////////////////////////////////////////////////////////////////
// The one and only CWinApp object
// NOTE: You may remove this object if you alter your project to no
// longer use MFC in a DLL.

CWinApp theApp;

///////////////////////////////////////////////////////////////////////
// command-parsing map

BEGIN_PARSE_MAP(CTest_ISAPIExtension, CHttpServer)
	// TODO: insert your ON_PARSE_COMMAND() and 
	// ON_PARSE_COMMAND_PARAMS() here to hook up your commands.
	// For example:

	ON_PARSE_COMMAND(Default, CTest_ISAPIExtension, ITS_EMPTY)
	DEFAULT_PARSE_COMMAND(Default, CTest_ISAPIExtension)
END_PARSE_MAP(CTest_ISAPIExtension)


///////////////////////////////////////////////////////////////////////
// The one and only CTest_ISAPIExtension object

CTest_ISAPIExtension theExtension;


///////////////////////////////////////////////////////////////////////
// CTest_ISAPIExtension implementation

CTest_ISAPIExtension::CTest_ISAPIExtension()
{
}

CTest_ISAPIExtension::~CTest_ISAPIExtension()
{
}

BOOL CTest_ISAPIExtension::GetExtensionVersion(HSE_VERSION_INFO* pVer)
{
	// Call default implementation for initialization
	CHttpServer::GetExtensionVersion(pVer);

	// Load description string
	TCHAR sz[HSE_MAX_EXT_DLL_NAME_LEN+1];
	ISAPIVERIFY(::LoadString(AfxGetResourceHandle(),
			IDS_SERVER, sz, HSE_MAX_EXT_DLL_NAME_LEN));
	_tcscpy(pVer->lpszExtensionDesc, sz);
	return TRUE;
}

BOOL CTest_ISAPIExtension::TerminateExtension(DWORD dwFlags)
{
	// extension is being terminated
	//TODO: Clean up any per-instance resources
	return TRUE;
}

///////////////////////////////////////////////////////////////////////
// CTest_ISAPIExtension command handlers

void CTest_ISAPIExtension::Default(CHttpServerContext* pCtxt)
{
	StartContent(pCtxt);
	WriteTitle(pCtxt);

	*pCtxt << _T("This default message was produced by the Internet");
	*pCtxt << _T(" Server DLL Wizard. Edit your CTest_ISAPIExtension::Default()");
	*pCtxt << _T(" implementation to change it.\r\n");

	EndContent(pCtxt);
}

// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CTest_ISAPIExtension, CHttpServer)
	//{{AFX_MSG_MAP(CTest_ISAPIExtension)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0



///////////////////////////////////////////////////////////////////////
// If your extension will not use MFC, you'll need this code to make
// sure the extension objects can find the resource handle for the
// module.  If you convert your extension to not be dependent on MFC,
// remove the comments arounn the following AfxGetResourceHandle()
// and DllMain() functions, as well as the g_hInstance global.

/****

static HINSTANCE g_hInstance;

HINSTANCE AFXISAPI AfxGetResourceHandle()
{
	return g_hInstance;
}

BOOL WINAPI DllMain(HINSTANCE hInst, ULONG ulReason,
					LPVOID lpReserved)
{
	if (ulReason == DLL_PROCESS_ATTACH)
	{
		g_hInstance = hInst;
	}

	return TRUE;
}

****/
