#include "pch.h"
#include"../thread_1/thread_1.cpp"
TEST(FunctionTest, CaseMax) {
    DWORD a, b, c;
    FLOAT ans = 0;
    a = 2, b = 3, c = 5;
    DWORD max;
    Nums numbs = { a,b,c,ans };
    FindMax(&numbs);
    max = numbs.ans;
    EXPECT_EQ(max, c);
 
}
TEST(FunctionTest, CaseMin) {
    DWORD a, b, c;
    FLOAT ans = 0;
    a = 2, b = 3, c = 5;
    DWORD min;
    Nums numbs = { a,b,c,ans };

    FindMin(&numbs);
    min = numbs.ans;
    EXPECT_EQ(min, a);

}
TEST(FunctionTest, CaseMid) {
    DWORD a, b, c;
    FLOAT ans = 0;
    a = 2, b = 3, c = 5;
    FLOAT mid=(2+3+5)/3;
    Nums numbs = {a,b,c,ans };
    Mediana(&numbs);
    mid = numbs.ans;
    EXPECT_EQ(numbs.ans, mid);

}