#pragma once
#include<iostream>
#include<Windows.h>
#include<tchar.h>

using namespace std;

struct Nums {
    DWORD a;
    DWORD b;
    DWORD c;
    FLOAT ans;
};

DWORD WINAPI  FindMax(LPVOID lpparam);

DWORD WINAPI  FindMin(LPVOID lpparam);

DWORD WINAPI  Mediana(LPVOID lpparam);

void PrintMax();
void PrintMin();
void PrintMed();