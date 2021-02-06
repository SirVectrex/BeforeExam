#include "Printer.h"

#ifndef _CRT_SECURE_NO_WARNINGS
	#define _CRT_SECURE_NO_WARNINGS
#endif // _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#ifdef __linux__ 
#include<unistd.h>
#elif __APPLE__ 
#include<unistd.h>
#elif _WIN32
#include<Windows.h>
#else
#error "Os not supported"
#endif

#define SPACE_IGNORE 0
#define SPACE_PRINT 1

#define NEWLINE_IGNORE 0
#define NEWLINE_AFTER_JUNK 1
#define NEWLINE_REGULAR 2
#define NEWLINE_AS_SPACE 4

#define CHAR_CHAR 1
#define CHAR_WCHAR 2

FILE *pFile;

int skipPage();
int printPage();
int printJunk();

int startPrinter(const char* filePath)
{
	unsigned start_page = register3 & 0xFF;
	unsigned end_page = (register3 & 0xFF00) >> 8;

	// Open File
	pFile = fopen(filePath, "r");

	// Handle File error
	if (pFile == NULL)
	{
		perror("Error opening file");
	}
	// Print File
	else
	{
		unsigned page = 0;

		// Burn pages
		for (page = 0; page < start_page; page++)
		{
			skipPage();
		}
		// Print pages
		for (; page < end_page; page++)
		{
			printPage();
		}
		// Close File
		fclose(pFile);
	}



	return 1;
}

int skipPage()
{
	unsigned page_size = (register2 & 0xF800) >> 11;

	// Burn lines
	for (unsigned i = 0; (i < page_size); i++)
	{
		char buffer[100];
		fgets(buffer, 100, pFile);
	}

	return 0;
}

int printPage()
{
	unsigned page_size = (register2 & 0xFC00) >> 10;

	// Print pages line wise
	for (unsigned i = 0; (i < page_size); i++)
	{
		// print line in junks
		while (0 == printJunk());
	}

	return 0;
}

int printJunk()
{
	unsigned lf_hndling = (register1 & 0x1C) >> 2;
	unsigned sp_hndling = register1 & 1;
	unsigned t_out = ((register1 & 0xFFE0) >> 5) + 1;

	unsigned char_size = register2 & 3;
	unsigned junk_size = (register2 & 0xF0) >> 4;

	int lf = 0;
	int c = '\x20';

	for (unsigned j = 0; (j < junk_size) && (lf != 1); j++)
	{
		// read char
		if (CHAR_CHAR == char_size)
		{
			c = fgetc(pFile);
		}
		else if (CHAR_WCHAR == char_size)
		{
			c = fgetc(pFile);
			c = fgetc(pFile);
		}
		else
		{
			break;
		}

		// if EOF break and return LF for correct handling
		if (EOF == c)
		{
			lf = 1;
			break;
		}

		// If newline do correct handling
		if ('\n' == c)
		{
			if ((NEWLINE_REGULAR & lf_hndling))
			{
				lf = 1;

				if (NEWLINE_AS_SPACE == lf_hndling)
				{
					c = ' ';
				}
			}
			else
			{
				continue;
			}
		}

		// If space do correct handling
		if ((' ' == c) && (SPACE_IGNORE == sp_hndling))
		{
			continue;
		}

		// print character
		printf("%c", (char)c);

	}

	// insert newline after junk if configured
	if ((NEWLINE_AFTER_JUNK & lf_hndling))
	{
		c = '\n';

		if (NEWLINE_AS_SPACE == lf_hndling)
		{
			c = ' ';
		}

		printf("%c", (char)c);
	}

	// sleep
#if defined(__linux__ ) || defined(__APPLE__)
	struct timespec ts;
	ts.tv_sec = (10'000 / t_out) / 1'000;
	ts.tv.nsec = ((10'000 / t_out) % 1'000) * 1'000'000
	nanosleep(&ts, NULL)
#elif _WIN32
	Sleep(10000 / t_out);
#else
#error "Os not supported"
#endif

	return lf;
}