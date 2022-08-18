#include<iostream>
#include<tchar.h>
#if defined(UNICODE)
	#define _tout std::wcout
#else
	#define _tout std::cout
#endif

int main()
{
	_tout << _T("Hello");
	return 0;
}