// MakeList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "List.h"

int _tmain(int argc, _TCHAR* argv[])
{
	List myList;

	int myVal1 = 1;
	int myVal2 = 2;
	int myVal3 = 3;

	printf_s("List count is : %d \n", myList.Count());

	myList.Push_Back((void*)&myVal1);
	myList.Push_Back((void*)&myVal2);
	myList.Push_Back((void*)&myVal3);
	
	printf_s("Popped : %d \n", *(int*)myList.Pop_Back());
	printf_s("List count is : %d \n", myList.Count());
		

	void* iter = myList.GetBeginIterator();

	myList.InsertAfter(iter, (void*)&myVal1);
	myList.Push_Back((void*)&myVal3);

	printf_s("List count is : %d \n", myList.Count());

	for (; iter != nullptr; myList.IterateForward(&iter))
	{
		int* myItem = (int*)(myList.GetItem(iter));
		printf_s("Value is : %d \n", *myItem);
	}


	getchar();
	return 0;
}

