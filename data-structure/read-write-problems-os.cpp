//读者与写者问题
#include <stdio.h>
#include <process.h>
#include <windows.h>
//设置控制台输出颜色
BOOL SetConsoleColor(WORD wAttributes)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hConsole == INVALID_HANDLE_VALUE)
		return FALSE;
	return SetConsoleTextAttribute(hConsole, wAttributes);
}
const int READER_NUM = 5;  //读者个数
//关键段和事件
CRITICAL_SECTION g_cs, g_cs_writer_count;
HANDLE g_hEventWriter, g_hEventNoReader;
int g_nReaderCount;
//读者线程输出函数(变参函数的实现)
void ReaderPrintf(char *pszFormat, ...)
{
	va_list   pArgList;

	va_start(pArgList, pszFormat);
	EnterCriticalSection(&g_cs);
	vfprintf(stdout, pszFormat, pArgList);
	LeaveCriticalSection(&g_cs);
	va_end(pArgList);
}
//读者线程函数
unsigned int __stdcall ReaderThreadFun(PVOID pM)
{
	ReaderPrintf("     编号为%d的读者进入等待中...\n", GetCurrentThreadId());
	//等待写者完成
	WaitForSingleObject(g_hEventWriter, INFINITE);

	//读者个数增加
	EnterCriticalSection(&g_cs_writer_count);
	g_nReaderCount++;
	if (g_nReaderCount == 1)
		ResetEvent(g_hEventNoReader);
	LeaveCriticalSection(&g_cs_writer_count);

	//读取文件
	ReaderPrintf("编号为%d的读者开始读取文件...\n", GetCurrentThreadId());

	Sleep(rand() % 100);

	//结束阅读,读者个数减小,空位增加
	ReaderPrintf(" 编号为%d的读者结束读取文件\n", GetCurrentThreadId());

	//读者个数减少
	EnterCriticalSection(&g_cs_writer_count);
	g_nReaderCount--;
	if (g_nReaderCount == 0)
		SetEvent(g_hEventNoReader);
	LeaveCriticalSection(&g_cs_writer_count);

	return 0;
}
//写者线程输出函数
void WriterPrintf(char *pszStr)
{
	EnterCriticalSection(&g_cs);
	SetConsoleColor(FOREGROUND_GREEN);
	printf("     %s\n", pszStr);
	SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	LeaveCriticalSection(&g_cs);
}
//写者线程函数
unsigned int __stdcall WriterThreadFun(PVOID pM)
{
	WriterPrintf("写者线程进入等待中...");
	//等待读文件的读者为零
	WaitForSingleObject(g_hEventNoReader, INFINITE);
	//标记写者正在写文件
	ResetEvent(g_hEventWriter);

	//写文件
	WriterPrintf("  写者开始写文件.....");
	Sleep(rand() % 100);
	WriterPrintf("  写者结束写文件");

	//标记写者结束写文件
	SetEvent(g_hEventWriter);
	return 0;
}
int main()
{
	printf("  读者写者问题\n");
	//printf(" -- by MoreWindows( http://blog.csdn.net/MoreWindows ) --\n\n");

	//初始化事件和信号量
	InitializeCriticalSection(&g_cs);
	InitializeCriticalSection(&g_cs_writer_count);

	//手动置位,初始已触发
	g_hEventWriter = CreateEvent(NULL, TRUE, TRUE, NULL);
	g_hEventNoReader  = CreateEvent(NULL, FALSE, TRUE, NULL);
	g_nReaderCount = 0;

	int i;
	HANDLE hThread[READER_NUM + 1];
	//先启动二个读者线程
	for (i = 1; i <= 2; i++)
		hThread[i] = (HANDLE)_beginthreadex(NULL, 0, ReaderThreadFun, NULL, 0, NULL);
	//启动写者线程
	hThread[0] = (HANDLE)_beginthreadex(NULL, 0, WriterThreadFun, NULL, 0, NULL);
	Sleep(50);
	//最后启动其它读者结程
	for ( ; i <= READER_NUM; i++)
		hThread[i] = (HANDLE)_beginthreadex(NULL, 0, ReaderThreadFun, NULL, 0, NULL);
	WaitForMultipleObjects(READER_NUM + 1, hThread, TRUE, INFINITE);
	for (i = 0; i < READER_NUM + 1; i++)
		CloseHandle(hThread[i]);

	//销毁事件和信号量
	CloseHandle(g_hEventWriter);
	CloseHandle(g_hEventNoReader);
	DeleteCriticalSection(&g_cs);
	DeleteCriticalSection(&g_cs_writer_count);
	return 0;
}
