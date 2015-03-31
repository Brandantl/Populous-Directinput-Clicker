#include <windows.h>
#include <stdio.h>

void main()
{
	while (true)
	{
		INPUT input = { 0 };
		input.type = INPUT_MOUSE;
		input.mi.dx = 0;
		input.mi.dy = 0;
		input.mi.dwFlags = (MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_LEFTDOWN);
		input.mi.mouseData = 0;
		input.mi.dwExtraInfo = NULL;
		input.mi.time = 0;
		SendInput(1, &input, sizeof(INPUT));

		Sleep(3000);

		INPUT input2 = { 0 };
		input2.type = INPUT_MOUSE;
		input2.mi.dx = 0;
		input2.mi.dy = 0;
		input2.mi.dwFlags = (MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_LEFTUP);
		input2.mi.mouseData = 0;
		input2.mi.dwExtraInfo = NULL;
		input2.mi.time = 0;
		SendInput(1, &input2, sizeof(INPUT));
		Sleep(1000);
	}
}