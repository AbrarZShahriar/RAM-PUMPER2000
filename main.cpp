#include <stdint.h>
#define Kilobytes(Value) ((Value)*1024LL)
#define Megabytes(Value) (Kilobytes(Value) * 1024LL)
#define Gigabytes(Value) (Megabytes(Value) * 1024LL)
#define Terabytes(Value) (Gigabytes(Value) * 1024LL)

typedef int8_t int8;
typedef int16_t int16;
typedef int32_t int32;
typedef int64_t int64;
typedef int32 bool32;

typedef uint8_t uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;
typedef uint64_t uint64;

typedef float real32;
typedef double real64;

#include <malloc.h>
#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <ctype.h>

int
main(int argc, const char **argv)
{
	uint64 TransientStorageSize;
	void *TransientStorage; // NOTE(casey): REQUIRED to be cleared to zero at
		// startup
	int input = 0;
	TransientStorageSize = Gigabytes(2);
	std::cout << "Enter occupy ammount in GB" << std::endl;
	std::cin >> input;
	TransientStorageSize = Gigabytes(input);

	TransientStorage =
		VirtualAlloc(0, TransientStorageSize, MEM_RESERVE | MEM_COMMIT,
			     PAGE_READWRITE);
	size_t i;

	if (TransientStorage) {
		char *char_ptr = static_cast<char *>(TransientStorage);
		for (i = 0; i < TransientStorageSize; i++) { //write to memory
			char_ptr[i] = 'a';
		}

		// for (i = 0; i < TransientStorageSize;
		//      i++) { //print memory contents
		// 	std::cout << char_ptr[i];
		// }

	} else {
		std::cout << "[ERROR]:Could not allocate " << TransientStorage
			  << " bytes of memory" << std::endl;
	}

	std::cout << "DONE!" << std::endl;

	printf("Press Any Key to Free Mem and Exit\n");
	_getch();
	VirtualFree(TransientStorage, 0,
		    MEM_RELEASE); //releasing memory

	return 0;
}