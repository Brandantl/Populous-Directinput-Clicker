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
	printf("Start!\n\nPress the space bar! ...\n");

	char Letter = 'W'; 

	SHORT key = VkKeyScanA(VK_RETURN);
	UINT mappedKey = MapVirtualKey(LOBYTE(key), 0);

	while (true)
	{
		if (GetAsyncKeyState(VK_SPACE) < 0)
		{
			SendKey(mappedKey);
			SendKey(MapVirtualKey(VK_SPACE, 0));
		}

		Sleep(10);
	}
}