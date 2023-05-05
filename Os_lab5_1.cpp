#include <Windows.h>
#include <iostream>

int main() {
   
    DWORD pid = 20532; 

    LPVOID lpAddress = (LPVOID)0x5ffe88;

    HANDLE hProcess = OpenProcess(PROCESS_VM_READ, FALSE, pid); 

    if (hProcess == NULL) {
        std::cerr << "Failed to open process with pid " << pid << std::endl;
        return 1;
    }

    int data = 0;
    SIZE_T bytesRead = 0;

    if (ReadProcessMemory(hProcess, lpAddress, &data, sizeof(data), &bytesRead) == 0) {
        std::cerr << "Failed to read process memory" << std::endl;
        CloseHandle(hProcess);
        return 1;
    }

    std::cout << "Read " << bytesRead << " bytes: " << data << std::endl;

    CloseHandle(hProcess);

    return 0;
}
