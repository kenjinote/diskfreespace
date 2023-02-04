#pragma comment(linker, "/opt:nowin98")
#include <windows.h>
int WINAPI WinMain(HINSTANCE hinst,HINSTANCE hPreInst,
                   LPSTR pCmdLine,int nCmdShow)
{
	CHAR str[1000];
	ULARGE_INTEGER FreeBytes;
	ULARGE_INTEGER TotalBytes;
	ULARGE_INTEGER TotalFree;
	GetDiskFreeSpaceEx(NULL,
		&FreeBytes,
		&TotalBytes,
		&TotalFree);
	wsprintf(str,
		"空き領域:%I64d bytes\n"
		"全領域:%I64d bytes\n"
		"全空き領域:%I64d bytes",
		FreeBytes.QuadPart,
		TotalBytes.QuadPart,
		TotalFree.QuadPart);
	MessageBox(NULL,str,"ドライブ空き容量",0);
	return 0;
}


