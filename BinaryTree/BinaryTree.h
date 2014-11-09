// BinaryTree.h : main header file for the BINARYTREE application
//

#if !defined(AFX_BINARYTREE_H__7B04BE1D_F2D8_4B94_8261_BF5F8BC34337__INCLUDED_)
#define AFX_BINARYTREE_H__7B04BE1D_F2D8_4B94_8261_BF5F8BC34337__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CBinaryTreeApp:
// See BinaryTree.cpp for the implementation of this class
//

class CBinaryTreeApp : public CWinApp
{
public:
	CBinaryTreeApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBinaryTreeApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CBinaryTreeApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BINARYTREE_H__7B04BE1D_F2D8_4B94_8261_BF5F8BC34337__INCLUDED_)
