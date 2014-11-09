// BinaryTreeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BinaryTree.h"
#include "BinaryTreeDlg.h"
#include <mmsystem.h>
#pragma comment( lib, "Winmm.lib" )

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBinaryTreeDlg dialog

CBinaryTreeDlg::CBinaryTreeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBinaryTreeDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBinaryTreeDlg)
	input = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	i=0;
	bitree=NULL;
	str="";
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBinaryTreeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBinaryTreeDlg)
	DDX_Control(pDX, IDC_output, output);
	DDX_Control(pDX, IDC_display, display);
	DDX_Text(pDX, IDC_Input, input);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CBinaryTreeDlg, CDialog)
	//{{AFX_MSG_MAP(CBinaryTreeDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnCreateTree)
	ON_EN_CHANGE(IDC_EDIT1, OnChangeInput)
	ON_BN_CLICKED(IDC_BUTTON5, Ondisptree)
	ON_BN_CLICKED(IDC_BUTTON8, OnExit)
	ON_BN_CLICKED(IDC_BUTTON7, Ondepth)
	ON_BN_CLICKED(IDC_BUTTON6, Onleaf)
	ON_BN_CLICKED(IDC_BUTTON2, Onpreorder)
	ON_BN_CLICKED(IDC_BUTTON3, Oninorder)
	ON_BN_CLICKED(IDC_BUTTON4, Onpostorder)
	ON_COMMAND(ID_MENUVERSION, Onversion)
	ON_COMMAND(ID_MENUCREATE, OnCreateTree)
	ON_COMMAND(ID_MENUDEPTH, Ondepth)
	ON_COMMAND(ID_MENULEAF, Onleaf)
	ON_COMMAND(ID_MENUIN, Oninorder)
	ON_COMMAND(ID_MENUPRE, Onpreorder)
	ON_COMMAND(ID_MENUPOST, Onpostorder)
	ON_COMMAND(ID_MENUEXIT, OnExit)
	ON_COMMAND(ID_MENUHELP, Onhelp)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBinaryTreeDlg message handlers

BOOL CBinaryTreeDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	playMusic();
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CBinaryTreeDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CBinaryTreeDlg::OnPaint() 
{
	CPaintDC dc(this);
	if (IsIconic())
	{
		 // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CRect rc;
		GetClientRect(&rc);
		//dc.FillSolidRect(&rc,RGB(51,102,205));
		
		CDialog::OnPaint();
	}
}
void CBinaryTreeDlg::drawLine(CPoint start,CPoint over)  //画直线
{
		CDC *pdc=GetDC();
		pdc->MoveTo(start.x+15,start.y+15);
		pdc->LineTo(over.x+15,over.y+15);
		//pdc->
		ReleaseDC(pdc);
}
void CBinaryTreeDlg::drawObject(COLORREF nodecolor,char text,COLORREF textcolor,CPoint LF)//画节点
{
	CString cs=text;
	CDC *pdc=GetDC();
	CBrush brush(nodecolor);//根据自己需要填充颜色
	CBrush *oldbrush;
	oldbrush = pdc->SelectObject(&brush);//选新的画刷
	pdc->Ellipse(LF.x,LF.y,LF.x+30,LF.y+30);
	pdc->SetTextColor(textcolor);
	pdc->SetBkColor(nodecolor);
	CFont fnBig;//创建大字体
	fnBig.CreatePointFont(150,"Times New Roman",pdc);
	CFont *po=pdc->SelectObject(&fnBig);
	pdc->TextOut(LF.x+5,LF.y+5,cs);
	pdc->SelectObject(oldbrush);//将原来的画刷选回去*/ 
	ReleaseDC(pdc);
}
void CBinaryTreeDlg::drawTree(BiTree&p)   //创建树
{
	if (p!=NULL)
	{
	//	drawLine();
		drawObject(RGB(255,0,255),p->data,RGB(255,255,0),p->LT);
		if (p->lchild!=NULL)
		{
			Sleep(1000);
			drawLine(p->LT,p->lchild->LT);
			drawObject(RGB(255,0,255),p->data,RGB(255,255,0),p->LT);
		} 
		else if(p->rchild!=NULL)
		{
			Sleep(1000);
			drawLine(p->LT,p->rchild->LT);
			drawObject(RGB(255,0,255),p->data,RGB(255,255,0),p->LT);
		}
		drawTree(p->lchild);
		if (p->lchild!=NULL&&p->rchild!=NULL)
		{
			Sleep(1000);
			drawLine(p->LT,p->rchild->LT);
			drawObject(RGB(255,0,255),p->data,RGB(255,255,0),p->LT);
		}
		drawTree(p->rchild);
	}
	return;
}
void CBinaryTreeDlg::preorder(BiTree&p)   //先序遍历
{
	if (p!=NULL)
	{
		drawObject(RGB(255,0,0),p->data,RGB(0,255,0),p->LT);
		str+=p->data;
		str+=" ";
		Sleep(1200);
		preorder(p->lchild);
		preorder(p->rchild);
	}
	return;
}
void CBinaryTreeDlg::inorder(BiTree&p)     //中序遍历
{
	if (p!=NULL)
	{
		inorder(p->lchild);
		drawObject(RGB(0,255,0),p->data,RGB(0,0,255),p->LT);
		str+=p->data;
		str+=" ";
		Sleep(1200);
		inorder(p->rchild);
	}
	return;
}
void CBinaryTreeDlg::postorder(BiTree&p)      //后序遍历
{
	if (p!=NULL)
	{
		postorder(p->lchild);
		postorder(p->rchild);
		drawObject(RGB(0,0,255),p->data,RGB(255,0,0),p->LT);
		str+=p->data;
		str+=" ";
		Sleep(1200);
	}
	return;
}
void CBinaryTreeDlg::setCH()      //接收字符串并处理
{
	UpdateData();
	//MessageBox();
//	CString result_last;
	//result_last.Format(_T("结果是：%d"),input.GetLength());
	//MessageBox(result_last);
	ch=new char(input.GetLength()+1);
	for (int i=0;i<input.GetLength();i++)
	{
		ch[i]=input.GetAt(i);
	}
	ch[input.GetLength()]='\0';
	//MessageBox(ch);
}

int CBinaryTreeDlg::judgeTree()    //判断输入的是不是颗树
{
	int count=0;
	for (int i=0;i<input.GetLength();i++)
	{
		if (ch[i]!='#')
		{
			count++;
		}
	}
	if ((2*count+1)!=input.GetLength())
	{
		//AfxMessageBox("您不是按要求输入的二叉树，请按要求输入");
		return 0;
	}
	return 1;
}
void CBinaryTreeDlg::CreateBiTree(BiTree&T,int nodeType,CPoint location)    //创建二叉树，并对节点赋予坐标
{
	for (;i<input.GetLength();)
	{
		if (ch[i]=='#')
		{
			T=NULL;
		    i++;
			return;
		} 
		else
		{
			if (!(T=(BiTNode*)malloc(sizeof(BiTNode))))
			{
				exit(0);
			}
			T->data=ch[i++];   //生成根结点
			if (2==nodeType)
			{
				T->LT=location;
			} 
			else if (1==nodeType)
			{
				T->LT.x=location.x-50;
				T->LT.y=location.y+50;
			} 
			else if(0==nodeType)
			{
				T->LT.x=location.x+40;
				T->LT.y=location.y+50;
			}
			else
			{
					AfxMessageBox("参数错误！");
			}
			CreateBiTree(T->lchild,1,T->LT);
			CreateBiTree(T->rchild,0,T->LT);
			return;
		}
	}

}
void CBinaryTreeDlg::disptree(BiTree&p)        //树的嵌套表示形式
{
	if (p!=NULL)
	{
		str+=p->data;
		if (p->lchild!=NULL||p->rchild!=NULL)
		{
			str+='(';
			disptree(p->lchild);
			if (p->rchild!=NULL)
			{
				str+=',';
			}
			disptree(p->rchild);
			str+=')';
		}
	}
}

int CBinaryTreeDlg::depth(BiTree&p)  //求树的深度
{
	int dep1,dep2;
	if (p==NULL)
	{
		return 0;
	} 
	else
	{
		dep1=depth(p->lchild);
		dep2=depth(p->rchild);
		if (dep1>dep2)
		{
			return(dep1+1);
		} 
		else
		{
			return(dep2+1);
		}
	}
}
int CBinaryTreeDlg::leaf(BiTree&p)       //叶子节点数目
{
	if (!p)
	{
		return 0;
	} 
	else if(!p->lchild&&!p->rchild)
	{
		return 1;
		//TRACE(12);
	}
	else return(leaf(p->lchild)+leaf(p->rchild));
}
// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CBinaryTreeDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CBinaryTreeDlg::OnCreateTree()          //创建树的响应事件
{
	// TODO: Add your control notification handler code here
	i=0;
	bitree=NULL;
	str="";
	CPoint c1(0,0),c2(600,600);
	CRect rc(c1,c2);
	InvalidateRect(rc,1);
	UpdateWindow();
	setCH();
	if (0==judgeTree())
	{
		AfxMessageBox("您貌似不是按要求输入的二叉树，请按要求输入");
	}
	else
	{
		CPoint cpoint,cpoint1(50,150),cpoint2(115,115);
		cpoint.x=300;
		cpoint.y=100;
		//	drawLine(cpoint,cpoint1);
		//	drawObject(RGB(255,0,255),"A",RGB(255,255,0),cpoint);*/
		try
		{
			CreateBiTree(bitree,2,cpoint);
			drawTree(bitree);
		}
		catch (CMemoryException* e)
		{
			AfxMessageBox("请按要求输入二叉树");
		}
		//MessageBox(ch);
	}
}
void CBinaryTreeDlg::playMusic()
{
	PlaySound((LPCTSTR)IDR_WAVE1, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
}
void CBinaryTreeDlg::OnChangeInput() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
}

void CBinaryTreeDlg::Ondisptree()        //求嵌套表示的响应事件
{
	// TODO: Add your control notification handler code here
//	setCH();
//	CreateBiTree(bitree);
	disptree(bitree);
	display.AddString("二叉树嵌套表示：\n"+str);
	str="";
}

void CBinaryTreeDlg::OnExit()   //退出程序的响应事件
{
	// TODO: Add your control notification handler code here
	CDialog::OnCancel();
}

void CBinaryTreeDlg::Ondepth()   //求树的深度响应事件
{
	// TODO: Add your control notification handler code here
//	setCH();
//	CreateBiTree(bitree);
	CString str1="";
	str1.Format("%d",depth(bitree));
	output.AddString("二叉树的深度："+str1);
}

void CBinaryTreeDlg::Onleaf()       //求树的叶子节点数响应事件
{
	// TODO: Add your control notification handler code here
	//MessageBox("Hello");
	setCH();
//	MessageBox(ch);
	//	CString result_last;
	//	result_last.Format(_T("结果是：%d"),i);
//	MessageBox(result_last);
//	CreateBiTree(bitree);
//	MessageBox("nihao");
	CString str1="";
	str1.Format("%d",leaf(bitree));
	output.AddString("叶子节点数："+str1);
}

void CBinaryTreeDlg::Oninorder()     //中序遍历响应事件
{
	// TODO: Add your control notification handler code here
	//display.UpdateData();
	//display.UpdateWindow();
	inorder(bitree);
	display.AddString("中序遍历顺序：\n"+str);
	str="";
}

void CBinaryTreeDlg::Onpreorder()   //先序遍历响应事件
{
	// TODO: Add your control notification handler code here
	preorder(bitree);
	display.AddString("先序遍历顺序：\n"+str);
	str="";
}


void CBinaryTreeDlg::Onpostorder()   //后序遍历响应事件
{
	// TODO: Add your control notification handler code here
	postorder(bitree);
	display.AddString("后序遍历顺序：\n"+str);
	str="";
}

void CBinaryTreeDlg::Onversion()     //弹出版本对话框事件
{
	// TODO: Add your command handler code here
	CDialog* dlg = new CDialog;
	dlg->Create(MAKEINTRESOURCE(IDD_ABOUTBOX));
	dlg->ShowWindow(1);

}

void CBinaryTreeDlg::Onhelp()      //弹出帮助对话框事件
{
	// TODO: Add your command handler code here
	CDialog* dlg = new CDialog;
	dlg->Create(MAKEINTRESOURCE(IDD_DIALOG1));
	dlg->ShowWindow(1);

}
