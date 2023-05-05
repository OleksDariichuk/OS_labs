#include <windows.h>
#include <iostream>

HHOOK hookHandle;

LRESULT CALLBACK KeyboardHook(int nCode, WPARAM wParam, LPARAM lParam)
{
    if (nCode == HC_ACTION && (wParam == WM_KEYDOWN || wParam == WM_SYSKEYDOWN))
    {
        KBDLLHOOKSTRUCT* p = (KBDLLHOOKSTRUCT*)lParam;
        std::cout << "Key pressed: " << p->vkCode << std::endl;
    }
    return CallNextHookEx(hookHandle, nCode, wParam, lParam);
}

int main()
{
    hookHandle = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardHook, NULL, 0);
    if (hookHandle == NULL)
    {
        std::cerr << "Failed to set keyboard hook" << std::endl;
        return 1;
    }

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    UnhookWindowsHookEx(hookHandle);
    return 0;
}
