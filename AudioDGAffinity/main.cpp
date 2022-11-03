#include <iostream>
#include <Windows.h>
#include <tlhelp32.h>

HANDLE GetProcessByName(PCSTR name)
{
    DWORD pid = 0;

    // Create toolhelp snapshot.
    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    PROCESSENTRY32 process;
    ZeroMemory(&process, sizeof(process));
    process.dwSize = sizeof(process);

    // Walkthrough all processes.
    if (Process32First(snapshot, &process))
    {
        do
        {
            // Compare process.szExeFile based on format of name, i.e., trim file path
            // trim .exe if necessary, etc.

            if (std::string(process.szExeFile) == std::string(name))
            {
                pid = process.th32ProcessID;
                break;
            }
        } while (Process32Next(snapshot, &process));
    }

    CloseHandle(snapshot);

    if (pid != 0)
    {
        return OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
    }

    std::cout << "we failed" << std::endl;

    return nullptr;
}

int main() {
    HANDLE hProcess = GetProcessByName("audiodg.exe");

    int res = -1;
    unsigned long affinity_mask = 2;

    std::cout << hProcess << std::endl;

    if (hProcess) {
        res = SetProcessAffinityMask(hProcess, affinity_mask);
        std::cout << "Set cpu affinity fail with" << res << std::endl;
        if (!res) {
            res = GetLastError();
            std::cout << "Set cpu affinity fail with" << res << std::endl;
            // default to CPU 1
            res = SetProcessAffinityMask(GetCurrentProcess(), 1);
        }
        CloseHandle(hProcess);
    }
    std::cin.get();

    return 0;
}
