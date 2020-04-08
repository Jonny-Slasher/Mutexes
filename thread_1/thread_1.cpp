#include<iostream>
#include<Windows.h>
#include<tchar.h>
#include "threads_1_Header.h"

using namespace std;

DWORD WINAPI  FindMax(LPVOID lpparam) {
   
    Nums* nm = (Nums*)lpparam;
    if (lpparam == NULL) {
        return 1;
    }
    else {
        HANDLE mtx = OpenMutex(MUTEX_ALL_ACCESS, FALSE, _T("Mewtex"));
        WaitForSingleObject(mtx, INFINITE);
        DWORD a = nm->a;
        DWORD b = nm->b;
        DWORD c = nm->c;
        DWORD max = a > b ? (a > c ? a : c) : (b > c ? b : c);
        nm->ans = max;
      /*  wcout << "MAX: " << max << endl;
        wcout << "Num of the thread : " << GetCurrentThreadId() << endl;
        for (int i = 0; i < 3; i++) {
            cout << i << endl;
        }*/

        ReleaseMutex(mtx);
        CloseHandle(mtx);
        return 0;
    }
    }

DWORD WINAPI  FindMin(LPVOID lpparam) {
    
    Nums* nm = (Nums*)lpparam;
    if (lpparam == NULL) {
        return 1;
    }
    else {
        HANDLE mtx = OpenMutex(MUTEX_ALL_ACCESS, FALSE, _T("Mewtex"));
        WaitForSingleObject(mtx, INFINITE);
        DWORD a = nm->a;
        DWORD b = nm->b;
        DWORD c = nm->c;
        DWORD min = a < b ? (a < c ? a : c) : (b < c ? b : c);
        nm->ans = min;
        /*wcout << "MIN: " << min << endl;
        wcout << "Num of the thread : " << GetCurrentThreadId() << endl;*/
        ReleaseMutex(mtx);
        CloseHandle(mtx);
        return 0;
    }
}

DWORD WINAPI  Mediana(LPVOID lpparam) {
   
    Nums* nm = (Nums*)lpparam;
    if (lpparam == NULL) {
        return 1;
    }
    else {
        HANDLE mtx = OpenMutex(MUTEX_ALL_ACCESS, FALSE, _T("Mewtex"));
        WaitForSingleObject(mtx, INFINITE);
        DWORD a = nm->a;
        DWORD b = nm->b;
        DWORD c = nm->c;
        FLOAT middle = a + b + c;
        middle = (middle / 3);
        nm->ans = middle;
      /*  wcout << "MIDDLE: " << middle << endl;
        wcout << "Num of the thread : " << GetCurrentThreadId() << endl;*/
     /*   for (int i = 0; i < 3; i++) {
            cout << i << endl;
        }*/
        ReleaseMutex(mtx);
        CloseHandle(mtx);
        return 0;
    }
}

void PrintMax() {
    wcout << "Max is - ";
}

void PrintMin() {
    wcout << "Min is - ";
}
void PrintMed() {
    wcout << "Mediana is - ";
}