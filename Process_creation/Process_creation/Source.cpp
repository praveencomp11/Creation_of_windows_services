/*
Author: Praveen Hore
This is just the simple example of the mutex wherein two thread are called
We will use this logic for next project.

*/

#include<iostream>
#include<tchar.h>
#include<mutex>
#include<thread>
#if defined(UNICODE)
	#define _tout std::wcout
#else
	#define _tout std::cout
#endif

int k;
std::mutex my_mutex;

static int add()
{
	
	std::lock_guard<std::mutex> lock(my_mutex);
	for (int i = 0; i < 10; i++)
	{		k = k + 1;
	         
	        _tout << std::this_thread::get_id() << " =" << k << std::endl;
	}
	return 0;
}

int main()
{
	_tout << _T("Hello")<<std::endl;
	std::thread thread1(add);
	std::thread thread2(add);
	std::mutex my_mutex;
	thread1.join();
	thread2.join();
	return 0;
}