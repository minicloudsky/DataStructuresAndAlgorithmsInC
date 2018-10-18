#include<stdio.h>
#include<iostream>
using namespace std;
BOOL CAboutDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO: Add extra initialization here

	SetDlgItemText(IDC_EDIT1,"����:�����������ʷ������¼,���Ŵ��㷨�������ڿ��ܳ��ֵĺ�ɫ��������ɫ�����.���˲�����ʹ�ñ������������������.");

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
//{{AFX_MSG_MAP(CAboutDlg)
//}}AFX_MSG_MAP

END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShuangSeQiuDlg dialog

CShuangSeQiuDlg::CShuangSeQiuDlg(CWnd* pParent /*=NULL*/)
: CDialog(CShuangSeQiuDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CShuangSeQiuDlg)
	// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CShuangSeQiuDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CShuangSeQiuDlg)
	DDX_Control(pDX, IDC_CODELIST, m_list);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CShuangSeQiuDlg, CDialog)
//{{AFX_MSG_MAP(CShuangSeQiuDlg)
ON_WM_SYSCOMMAND()
ON_WM_PAINT()
ON_WM_QUERYDRAGICON()
ON_BN_CLICKED(IDC_BTN_YUCE, OnBtnYuce)
ON_BN_CLICKED(IDC_BTN_ADD, OnBtnAdd)
ON_BN_CLICKED(IDC_BTN_VIEWHISTORY, OnBtnViewhistory)
ON_BN_CLICKED(IDC_BTN_SAVE, OnBtnSave)
ON_BN_CLICKED(IDC_BTN_HISTORYSTAT, OnBtnHistorystat)
ON_NOTIFY(NM_CLICK, IDC_CODELIST, OnClickCodelist)
ON_BN_CLICKED(IDC_BTN_HISTORY, OnBtnHistory)
ON_BN_CLICKED(IDC_BTN_DELETE, OnBtnDelete)
//}}AFX_MSG_MAP
ON_NOTIFY (NM_CUSTOMDRAW, IDC_CODELIST, OnCustomdrawMyList)

ON_MESSAGE(WM_VALIDATE, OnEndLabelEditVariableCriteria) //��ӵ��Զ������Ϣ
ON_MESSAGE(WM_SET_ITEMS, PopulateComboList)

END_MESSAGE_MAP()
BOOL CShuangSeQiuDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	//skinppLoadSkin("AquaOS.ssk");
	skinppLoadSkin("MAC.ssk");


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



	m_list.EnableVScroll();
	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	m_list.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);



	m_list.InsertColumn(0,_T("ID"),LVCFMT_LEFT,30);
	m_list.InsertColumn(1,_T("��1"),LVCFMT_LEFT,40);
	m_list.InsertColumn(2,_T("��2"),LVCFMT_LEFT,40);
	m_list.InsertColumn(3,_T("��3"),LVCFMT_LEFT,40);
	m_list.InsertColumn(4,_T("��4"),LVCFMT_LEFT,40);
	m_list.InsertColumn(5,_T("��5"),LVCFMT_LEFT,40);
	m_list.InsertColumn(6,_T("��6"),LVCFMT_LEFT,40);

	m_list.InsertColumn(7,_T("��"),LVCFMT_LEFT,40);


	line = 0;
	yuce = 0;

	//��ʼ������
	initVar();

	//����ʷ����
	ReadHistroy();

	CString strValidChars;//
	m_list.SetReadOnlyColumns(0);//read only

	strValidChars = "0123456789";
	m_list.SetColumnValidEditCtrlCharacters(strValidChars,1);//digital only edit
	m_list.SetColumnValidEditCtrlCharacters(strValidChars,2);//digital only edit
	m_list.SetColumnValidEditCtrlCharacters(strValidChars,3);//digital only edit
	m_list.SetColumnValidEditCtrlCharacters(strValidChars,4);//digital only edit
	m_list.SetColumnValidEditCtrlCharacters(strValidChars,5);//digital only edit
	m_list.SetColumnValidEditCtrlCharacters(strValidChars,6);//digital only edit
	m_list.SetColumnValidEditCtrlCharacters(strValidChars,7);//digital only edit

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CShuangSeQiuDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CShuangSeQiuDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

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
		CDialog::OnPaint();
	}
}



// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CShuangSeQiuDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}


//��ʼ������
void CShuangSeQiuDlg::initVar()
{

	for(int i=0;i<6;i++){
		red[i] ="";
	}

	blue="";		//�Ѿ�����

	for(int r=0;r<34;r++){
		StatRed[r] =0;		//�����ۼ�
		StatRedRate[r] = 0.0;		//�����ۼ���

		sn[r] = r;
	}

	for(int b=0;b<17;b++){
		StatBlue[b] =0;				//�����ۼ�
		StatBlueRate[b] = 0.0;		//�����ۼ���
	}

	int dd = 0;
	deleteflag = false;
	totalsn = 0;
	popnum = 20;
	//ΪԤ��������һЩ��ʼ��
	for(int item=0;item<popnum;item++)
	{
		for(int r=0;r<6;r++)
			ItemCountRed[item][r]=0;
		ItemCountBlue[item]=0;
		ItemCountRedRate[item] =0;
	}
	MAXRATE = 20;	//rate ����ǰmax��ֵ
	thebest =0;
	yecefail = true;
}

//����ʷ����
void CShuangSeQiuDlg::ReadHistroy()
{
	CHistoryReorcd chr;
	CString path = chr.GetCurPath();
	CString filename = path+ "\\history.txt";
	line = chr.GetFileLine(filename);
	//����ÿһ�е�����,���ݲ�ͬ������,��ֵ�ֵ���ͬ��������.
	for(int i=1;i<=line;i++){
		CString linestr= chr.GetLineActionFile(filename,i);
		int sub = linestr.Find(":",0);
		CString codestr = linestr.Mid(sub+1);
		CSpliter cSpliter;
		cSpliter.setdata(codestr);
		cSpliter.setsplitflag(",");
		CStringArray a;
		cSpliter.getsplitstrarray(a);
		int number_red=0;
		for(int r=0;r<6;r++){
			number_red = atoi(a.GetAt(r));
			StatRed[number_red] ++;
		}
		//��������ڵĺŸ���ȫ��������,�Թ�Ԥ��ʱ��Ƚ�.
		if(i == line-1){
			for(int p=0;p<6;p++)
			{
				int sn =p;
				passval[sn] = atoi(a.GetAt(p));
			}
		}else if (i == line){
			for(int p=0;p<6;p++)
			{
				int sn = 6+p;
				passval[sn] = atoi(a.GetAt(p));
			}
		}
		int number_blue = atoi(a.GetAt(6));
		StatBlue[number_blue] ++;
	}
	float RedTotolTime  = (float)6*line;		//�����ܳ��ִ���
	float BlueTotolTime = (float)line;			//�����ܳ��ִ���
	//�������
	for(int rr=1;rr<34;rr++){
		StatRedRate[rr] = (float)StatRed[rr] /	RedTotolTime;			//�����ۼ���
	}
	for(int br=1;br<17;br++){
		StatBlueRate[br] = (float)StatBlue[br] /BlueTotolTime;			//�����ۼ���
	}
}

void CShuangSeQiuDlg::OnBtnYuce()
{
	yecefail = true;
	while(yecefail)
	{
		//ͨ���㷨�õ���ֵ
		GAStudy();
		UpdateData(TRUE);
		int i =m_list.GetItemCount();
		CString str;
		str.Format("%d",totalsn+1);
		if (!yecefail)
		{
			SetDlgItemText(IDC_STATIC_INFO,"��Ϣ:���Ǹ���ѡ����!" );
			m_list.InsertItem(LVIF_TEXT|LVIF_STATE, i+1, str, LVIS_SELECTED|LVIS_FOCUSED, LVIS_SELECTED|LVIS_FOCUSED, 0, 0);
		}
		if (!yecefail)
		{
			int array[7];
			bool shaixuan[33]={false};
			for(int sub=0;sub<6;sub++)
			{
				array[sub+1]=sn[ItemCountRed[thebest][sub]];
				int idx=array[sub+1];
				while(shaixuan[idx-1])
				{
					idx=idx%33+1;
					array[sub+1]=idx;
				}
				shaixuan[idx-1]=true;
			}
			QuickSort(array,1,6);
			for(sub=1;sub<7;sub++)
			{
				CString s;
				s.Format("%d" ,array[sub]);
				m_list.SetItemText(i,sub,s);
			}
			int blue = rand()%16 + 1;
			CString bstr;
			bstr.Format("%d",blue);
			//��ɫ�����,û����ô��,�����һ����ɫ��,��...
			m_list.SetItemText(i,7,_T(bstr));
			totalsn++;
		}
		UpdateData(FALSE);
	}
}

//��ʼGAѧϰ
void CShuangSeQiuDlg::GAStudy()
{

	initpop();				//��ʼ����Ⱥ
	int train_count =0;
	int totalval =118;		//�ۼӺ�

    int bubiaole =0;
	int pre = 0;

	while( totalval < 75  || totalval > 125  ||  train_count< 10  )
	{
		totalval = 0;			//��ʼ��Ϊ0

		train_count++;			//��һ��

		ComputeFit();			//������Ӧ��

		SelectAndDeletePop();	//ѡ�����̭��Ⱥ

		CrossPop();				//�������

		Mutation();		        //�������

		thebest = GetResult();	//�õ�������ȺID

		int val[6] ={0};

		for(int i=0;i<6;i++){
			val[i] = sn[ItemCountRed[thebest][i]];
			totalval = totalval + val[i];
		}

		if (pre == totalval){
			bubiaole ++;
		}else{
			pre = totalval;
		}

		if (bubiaole>10){
			//AfxMessageBox("���ֲ��Ƽ�����������,�����Ԥ��!");
			SetDlgItemText(IDC_STATIC_INFO,"��Ϣ:���ֲ��Ƽ�����������,ϵͳ����Ԥ����......" );
			yecefail = true;
			break;
		}else{
			yecefail = false;
		}

		//�Ƚ��������ڲ��
		int samecount =0;
		for(i=0;i<6;i++){
			for(int sn=0;sn<12;sn++){
				if(	val[i] == passval[sn] ){
					samecount ++ ;
					if (samecount > 2 ){	//�������������,�������Ԥ��
						yecefail = true;
						SetDlgItemText(IDC_STATIC_INFO,"��Ϣ:�����������ƺ�����,ϵͳ����Ԥ����......" );
						break;
					}else{
						yecefail = false;
					}
				}
			}
		}

		int dd = 0;

	}

}

//��ʼ����Ⱥ
void CShuangSeQiuDlg::initpop()
{
	//����
	int tmp=0;

	for(int i=1;i<34;i++){
		for(int j=i+1;j<34;j++)
			if(	StatRedRate[sn[i]]  < StatRedRate[sn[j]] ) {
				tmp = sn[i];
				sn[i]= sn[j];
				sn[j] = tmp;
			}
	}


	//�����������
	/*
	CStdioFile file;
	file.Open("sort.txt",CFile::modeCreate|CFile::modeReadWrite);

	  int len = 34;
	  for(i=1;i<len ;i++){
	  CString rate,ratelist;
	  ratelist.Format("%.8f",StatRedRate[sn[i]]);
	  rate.Format("%d --",sn[i]);
	  rate = rate + ratelist;
	  file.WriteString(rate);
	  file.WriteString("\n");
	  }
	  file.Close();
	*/


	srand(time(0));/*��������,������α�������*/
	for(int pop=0;pop<popnum;pop++){
		for(int j=0;j<6;j++){
			bool same = true;

			int r =0;
			int min = 1;

			int diff=0;
			while(same){
				r = rand()%(MAXRATE) + min;
				for(int next=0 ;next<6; next++){
					if (r == ItemCountRed[pop][next] ){
						same =true;
						diff= 0;
						break;
					}else{
						diff ++;
					}
				}
				if (diff >= 5){
					same = false;
				}
			}
			ItemCountRed[pop][j] = r;
		}
	}

	CStdioFile file;
	file.Open("pop.txt",CFile::modeCreate|CFile::modeReadWrite);
	for(i=0;i<popnum ;i++){
		CString popn="";

		for(int j=0;j<6;j++){
			CString nextp="";
			nextp.Format("%d",sn[ItemCountRed[i][j]] );   //�൱��rate.Format("%d --",sn[i]);
			popn = popn + " " + nextp;

		}
		file.WriteString(popn);
		file.WriteString("\n");
	}
	file.Close();


}


//������Ӧ��
void CShuangSeQiuDlg::ComputeFit()
{
	for(int pop=0;pop<popnum;pop++){
		for(int j=0;j<6;j++){
			int cur = sn[ItemCountRed[pop][j]] ;
			ItemCountRedRate[pop] =ItemCountRedRate[pop] + StatRedRate[cur] ;
		}
	}


	CStdioFile file;
	file.Open("poprate.txt",CFile::modeCreate|CFile::modeReadWrite);
	for(int i=0;i<popnum ;i++){
		CString popn="";
		popn.Format("%.8f",ItemCountRedRate[i]);
		file.WriteString(popn);
		file.WriteString("\n");
	}
	file.Close();
}



//ѡ�����̭��Ⱥ
void CShuangSeQiuDlg::SelectAndDeletePop()
{
	float maxrate =0;
	float minrate =1000;


	for(int i=0;i<popnum ;i++){
		if (ItemCountRedRate[i] > maxrate){
			maxindex = i;
			maxrate = ItemCountRedRate[i] ;
		}
		if (ItemCountRedRate[i] < minrate){
			minindex = i;
			minrate = ItemCountRedRate[i] ;
		}
	}

	CStdioFile file;

	CFileStatus   fs;
	if(!CFile::GetStatus(_T("popselect.txt"),fs))
	{
		file.Open("popselect.txt",CFile::modeCreate|CFile::modeReadWrite);
	}else{
		file.Open("popselect.txt",CFile::modeReadWrite);
	}




	file.SeekToEnd();

	CString maxindexstr="";
	maxindexstr.Format("%d ���ŵ���ȺID",maxindex);
	file.WriteString(maxindexstr);
	file.WriteString("\n");

	CString minindexstr="";
	minindexstr.Format("%d ������ȺID",minindex);
	file.WriteString(minindexstr);
	file.WriteString("\n");

	file.Close();

}

//�������
void CShuangSeQiuDlg::CrossPop()
{
	srand(time(0));
	int min =0;
	int r = 0;		//���һ����Ⱥ��

	CStdioFile file;
	file.Open("CrossPop.txt",CFile::modeCreate|CFile::modeReadWrite);

	file.SeekToEnd();

	CString rr="";
	rr.Format("%d",minindex);
	CString crossstr="���� minindex=" + rr + "\n";

	for(int i=0;i<6;i++){
		CString s="";
		s.Format("%d" ,sn[ ItemCountRed[minindex][i] ]);
		crossstr = crossstr + s  + " ";
	}
	file.WriteString(crossstr);
	file.WriteString("\n");


	bool nextthreesame = true;

	//�������ĺ���λ�����ŵ�ǰ��λ��ͬ�Ϳ���
	while(nextthreesame){
		r = rand()%(popnum) + min;	//����Ⱥ20�����һ����Ⱥ��
		int cuti= 3;
		int cutb =0;
		for(cuti=3;cuti<6;cuti++){	//����ĺ���λ
			for(cutb=0;cutb<3;cutb++){//���ŵ�ǰ��λ�Ƚ�
				if(sn[ ItemCountRed[r][cuti] ] == sn[ ItemCountRed[maxindex][cutb] ]){
					nextthreesame = true;		//����ͬ��,��Ҫ�����������Ⱥ
					break;
				}
			}
		}
		if(cuti == 6 && cutb == 3){
			nextthreesame = false;
		}
	}


	//����õ���Ⱥ���������Ⱥ�����ӽ�,�滻������Ⱥ��ǰ��λֵ
	for(int cutb=0;cutb<3;cutb++){
		ItemCountRed[minindex][cutb] = ItemCountRed[maxindex][cutb] ;
	}

	for(int cuti=3;cuti<6;cuti++){
		ItemCountRed[minindex][cuti] = ItemCountRed[r][cuti] ;
	}


	rr.Format("%d",r);
	crossstr="��� r=" + rr + "\n";
	for(i=0;i<6;i++){
		CString s="";
		s.Format("%d" ,sn[ ItemCountRed[r][i] ]);
		crossstr = crossstr + s+ " ";
	}
	file.WriteString(crossstr);
	file.WriteString("\n");

	rr.Format("%d",maxindex);
	crossstr="��õ� maxindex=" + rr + "\n";
	for(i=0;i<6;i++){
		CString s="";
		s.Format("%d" ,sn[ ItemCountRed[maxindex][i] ]);
		crossstr = crossstr + s + " ";
	}
	file.WriteString(crossstr);
	file.WriteString("\n");

	rr.Format("%d",minindex);
	crossstr="�µ� minindex=" + rr + "\n";
	for(i=0;i<6;i++){
		CString s="";
		s.Format("%d" ,sn[ ItemCountRed[minindex][i] ]);
		crossstr = crossstr + s + " ";
	}
	file.WriteString(crossstr);
	file.WriteString("\n");

	file.Close();

}


//�������
void CShuangSeQiuDlg::Mutation()
{

	float r = (float)rand()/65535 ;
	int min =0;
	int	opindex = 0;

	if(r<0.4){
		opindex = rand()%(MAXRATE) + min;		//�����ź�������ѡһ����
		ItemCountRed[minindex][0] = opindex;
	}else if (r<0.8){
		opindex = rand()%(33) + min;			//��ȫ��������ѡһ����
		ItemCountRed[minindex][5] = opindex;
	}else{
		opindex = rand()%(33) + MAXRATE;		//��������ѡһ����
		ItemCountRed[minindex][5] = opindex;
	}



	CStdioFile file;
	file.Open("Mutation.txt",CFile::modeCreate|CFile::modeReadWrite);

	CString rr="";
	rr.Format("%.8f", r);
	CString crossstr="��� r = " + rr + "\n";
	file.WriteString(crossstr);
	file.WriteString("\n");
	if(r<0.5){
		rr.Format("%d", opindex);
		crossstr="����ѡ�� opindex = " + rr + "\n";
		file.WriteString(crossstr);
		file.WriteString("\n");
	}else{
		rr.Format("%d", opindex);
		crossstr="ȫ��ѡ�� opindex = " + rr + "\n";
		file.WriteString(crossstr);
		file.WriteString("\n");
	}


	crossstr="�����\n";
	for(int i=0;i<6;i++){
		CString s="";
		s.Format("%d" ,sn[ ItemCountRed[minindex][i] ]);
		crossstr = crossstr + s + " ";
	}
	file.WriteString(crossstr);
	file.WriteString("\n");
	file.Close();
}

//�õ����ŵ��Ŵ����
int CShuangSeQiuDlg::GetResult()
{
	int thebestpop =0;
	for(int pop=0;pop<popnum;pop++){
		ItemCountRedRate[pop] =0;
		for(int j=0;j<6;j++){
			int cur = sn[ItemCountRed[pop][j]] ;
			ItemCountRedRate[pop] =ItemCountRedRate[pop] + StatRedRate[cur] ;
		}
	}

	CStdioFile file;
	file.Open("poprateget.txt",CFile::modeCreate|CFile::modeReadWrite);
	for(int i=0;i<popnum ;i++){
		CString popn="";
		popn.Format("%.8f",ItemCountRedRate[i]);
		file.WriteString(popn);
		file.WriteString("\n");
	}

	float maxrate =0;
	for(i=0;i<popnum ;i++){
		if (ItemCountRedRate[i] > maxrate){
			maxindex = i;
			maxrate = ItemCountRedRate[i] ;
		}
	}

	CString thebest = "";
	thebest.Format("%d",maxindex);
	file.WriteString(thebest);
	file.WriteString("\n");

	CString crossstr="���ŵ���ȺΪ:\n";
	for(i=0;i<6;i++){
		CString s="";
		s.Format("%d" ,sn[ItemCountRed[maxindex][i]]);
		crossstr = crossstr + s + " ";
	}
	file.WriteString(crossstr);
	file.WriteString("\n");
	file.Close();
	thebestpop = maxindex;
	return thebestpop;
}


//������ʷ
void CShuangSeQiuDlg::OnBtnAdd()
{
	CAddHistoryDlg adddlg;
	if (adddlg.DoModal()){
		//���³�ʼ��;
		initVar();
		//���µ����¼;
		ReadHistroy();
	}
}


//�鿴��ʷ
void CShuangSeQiuDlg::OnBtnViewhistory()
{
	WinExec("Notepad.exe history.txt", SW_SHOW);
}

//�������
void CShuangSeQiuDlg::OnBtnSave()
{

	CStdioFile file;
	file.Open("save.txt",CFile::modeCreate|CFile::modeReadWrite);

	int len = m_list.GetItemCount();
	for(int i=0;i<len ;i++){
		CString codeline;
		for(int j=1;j<8;j++){
			CString code = m_list.GetItemText(i,j);
			codeline = codeline + code + "  ";
		}
		file.WriteString(codeline);
		file.WriteString("\n");
	}
	file.Close();

	WinExec("Notepad.exe save.txt", SW_SHOW);

}

//��ʷͳ��
void CShuangSeQiuDlg::OnBtnHistorystat()
{
	CStdioFile file;
	file.Open("historystat.txt",CFile::modeCreate|CFile::modeReadWrite);

	CString redt;
	redt.Format("%d",line);

	CString rss = "���������� " + redt+ "��.\n" ;


	file.WriteString(rss);

	for(int r =1;r<34;r++){
		CString rstr,rn;
		rstr.Format("%d",r);
		rn.Format("%d",StatRed[r]);
		CString rp = "��" + rstr + " ���� " + rn+ "��.";

		CString redrate;
		redrate.Format("%.8f",StatRedRate[r]);
		rp = rp + " ������Ϊ" + redrate + "\n";

		file.WriteString(rp);
	}

	file.WriteString("\n***********************\n");

	CString bluet;
	bluet.Format("%d",line);
	CString bss = "���򹲳��� " + bluet+ "��.\n" ;
	file.WriteString(bss);

	for(int b=1;b<17;b++){
		CString bstr,bn;
		bstr.Format("%d",b);
		bn.Format("%d",StatBlue[b]);
		CString bp = "��" + bstr + " ���� " + bn+ "��.";
		CString bluerate;
		bluerate.Format("%.8f",StatBlueRate[b]);
		bp = bp + " ������Ϊ" + bluerate + "\n";
		file.WriteString(bp);
	}


	file.Close();
	WinExec("Notepad.exe historystat.txt", SW_SHOW);

}
