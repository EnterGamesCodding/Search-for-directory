#include <Windows.h>
#include <iostream>
#include <string>

using namespace std;

void searchFiles(string path, string name)
{
    string searchPath = path + "\\" + name + ".*";
    WIN32_FIND_DATAA findData;
    HANDLE hFind = FindFirstFileA(searchPath.c_str(), &findData);

    if (hFind != INVALID_HANDLE_VALUE)
    {
        do
        {
            if (!(findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
            {
                cout << findData.cFileName << endl;
            }
        } while (FindNextFileA(hFind, &findData));
        FindClose(hFind);
    }
}

int main()
{

    string path = "C:\\Users\\User\\Document";
    string name = "example";
    searchFiles(path, name);
    return 0;
}
