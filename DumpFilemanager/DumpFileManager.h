#pragma once
#include <afx.h>
#include <string>

enum DumpFileType 
{
	DumpFileType_Full = 0,	//full memory
	DumpFileType_Normal,	//normal memory
	DumpFileType_None,		//do not save
};

class DumpFileManager
{

public:
	DumpFileManager();
	~DumpFileManager();

	void SetDumpFileType(size_t type) { dumpFileType_ = type; }

	void RunCrashHandler();

	void DisableSetUnhandledExceptionFilter();
	
	static long WINAPI UnhandledExceptionFilterEx(struct _EXCEPTION_POINTERS* exception);
	
	void PrintDumplog(const char* patch, const char* msg);

	void CheckDumpFileNumber(CString filePath);

	bool CreateDumpFile(EXCEPTION_POINTERS* exception, LPCTSTR fileName);
private:

	int					dumpFileType_;		//ת���ļ�����
	CString				dumpFileName_;		//ת���ļ�����,����Ϊ������ʱ���
	CString				dumpFilePath_;		//ת���ļ�·��
};

extern void StartDetectCrash(size_t type = DumpFileType_Full);
extern void StopDetectCrash();

extern std::string CString2String(CString target);
extern CString String2CString(const char* str);