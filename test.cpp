#include "SelfFinancialTool.h"
using namespace std;
int main()
  {
    long double PV=2126150.77;
    long double A=20000;
    long double r=0;
    long double N=30;
    FutureValueOfCashFlow(PV,A,r,N,CALC_R);
    Print(r,6);
  }
