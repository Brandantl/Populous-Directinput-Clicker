#include <windows.h>
#include <stdio.h>

void SendKey(UINT mappedKey)
{
	INPUT Input[2] = { 0 };

	Input[0].type = INPUT_KEYBOARD;
	Input[0].ki.wScan = mappedKey;
	Input[0].ki.dwFlags = KEYEVENTF_SCANCODE;

	Input[1].type = INPUT_KEYBOARD;
	Input[1].ki.wScan = mappedKey;
	Input[1].ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;

	SendInput(2, Input, sizeof(INPUT));
}

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

		Sleep(30);

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