#if !defined(AFX_TEST_ISAPI_H__81E9F03D_3A14_11EB_B2F4_000C29FD3042__INCLUDED_)
#define AFX_TEST_ISAPI_H__81E9F03D_3A14_11EB_B2F4_000C29FD3042__INCLUDED_

// TEST_ISAPI.H - Header file for your Internet Server
//    Test_ISAPI Extension

#include "resource.h"

class CTest_ISAPIExtension : public CHttpServer
{
public:
	CTest_ISAPIExtension();
	~CTest_ISAPIExtension();

// Overrides
	// ClassWizard generated virtual function overrides
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//{{AFX_VIRTUAL(CTest_ISAPIExtension)
	public:
	virtual BOOL GetExtensionVersion(HSE_VERSION_INFO* pVer);
	//}}AFX_VIRTUAL
	virtual BOOL TerminateExtension(DWORD dwFlags);

	// TODO: Add handlers for your commands here.
	// For example:

	void Default(CHttpServerContext* pCtxt);

	DECLARE_PARSE_MAP()

	//{{AFX_MSG(CTest_ISAPIExtension)
	//}}AFX_MSG
};


//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST_ISAPI_H__81E9F03D_3A14_11EB_B2F4_000C29FD3042__INCLUDED)
