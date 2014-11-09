// BinaryTreeDlg.h : header file
//

#if !defined(AFX_BINARYTREEDLG_H__6916145A_805A_4FB6_A8C6_CCF9744FC220__INCLUDED_)
#define AFX_BINARYTREEDLG_H__6916145A_805A_4FB6_A8C6_CCF9744FC220__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CBinaryTreeDlg dialog

class CBinaryTreeDlg : public CDialog
{
protected:
	typedef struct BiTNode
	{
		char data;
		struct BiTNode *lchild,*rchild;       //左右孩子指针
		CPoint LT;                         //所要画的节点的左上角的坐标
}BiTNode,*BiTree;
// Construction
public:
	CBinaryTreeDlg(CWnd* pParent = NULL);	// standard constructor
	void setCH();//把输入的字符串Cstring类型转化成char*
	void CreateBiTree(BiTree&T,int nodeType,CPoint location);//创建二叉树
	void disptree(BiTree&p);//嵌套括号表示二叉树
	int depth(BiTree&p);//求二叉树的深度
	int leaf(BiTree&p);//求二叉树的叶子节点数
	void drawObject(COLORREF nodecolor,char text,COLORREF textcolor,CPoint LF);//画节点的颜色、位置、节点表示文本、文本颜色
	void drawLine(CPoint start,CPoint over);//根据其实和终止坐标画直线  
	void drawTree(BiTree&T);//创建树后输出整个树
	void preorder(BiTree&p);//先序遍历
	void inorder(BiTree&p);//中序遍历
	void postorder(BiTree&p);//后续遍历
	void playMusic() ;       //播放音乐
	int judgeTree();//判断输入的是不是一棵树
// Dialog Data
	//{{AFX_DATA(CBinaryTreeDlg)
	enum { IDD = IDD_BINARYTREE_DIALOG };
	CListBox	output;
	CListBox	display;
	CString	input;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBinaryTreeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation

protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CBinaryTreeDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnCreateTree();
	afx_msg void OnChangeInput();
	afx_msg void Ondisptree();
	afx_msg void OnExit();
	afx_msg void Ondepth();
	afx_msg void OnButton6();
	afx_msg void Onleaf();
	afx_msg void Onpreorder();
	afx_msg void Oninorder();
	afx_msg void Onpostorder();
	afx_msg void Onversion();
	afx_msg void Onhelp();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	char *ch;
	int i; 
	BiTree bitree;
	CString str;
	//CreateBiTree(bitree);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BINARYTREEDLG_H__6916145A_805A_4FB6_A8C6_CCF9744FC220__INCLUDED_)
