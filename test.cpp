#include "SelfFinancialTool.h"
using namespace std;
int main()
  {
    vector<long double> CF1={200,225,0};
    vector<long double> CF2={0,5,480};
    long double IRR=WANT_GET;
    MoneyWeightedRateOfReturn(CF1,CF2,IRR);
    Print(IRR);
  }
