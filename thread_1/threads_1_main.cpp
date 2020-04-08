
#include"threads_1_Header.h"
#include<iostream>
using namespace std;

int main() {

    HANDLE th[3];
    HANDLE mtx;
    mtx = CreateMutex(NULL, FALSE, _T("Mewtex"));
    DWORD TreadID;
    DWORD a, b, c;
    FLOAT ans = 0;

    wcout << "Enter 3 numbers\n";
    wcout << "1 -" << endl;
    wcin >> a;
    wcout << "2 -" << endl;
    wcin >> b;
    wcout << "3 -" << endl;
    wcin >> c;

    Nums nooms = { a,b,c,ans };

    DWORD(WINAPI * Functions[3])(LPVOID) = { FindMax, FindMin, Mediana };
   
    void (*Print[3])() = { PrintMax, PrintMin, PrintMed };
    if (mtx == NULL) {
        return 1;
    }

    for (int i = 0; i < 3; i++) {

        th[i] = CreateThread(NULL, 0, Functions[i], &nooms, 0, &TreadID);
        Print[i]();
        wcout << nooms.ans;
        wcout<<endl;
        Sleep(1000);

    }

    WaitForMultipleObjects(3, th, TRUE, INFINITE);
    for (int i = 0; i < 3; i++) {
        CloseHandle(th[i]);
    }
    CloseHandle(mtx);
    return 0;
}