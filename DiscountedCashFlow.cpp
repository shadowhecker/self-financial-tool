#include "SelfFinancialTool.h"

using namespace std;
int NetPresentValueRule(long double &NPV,const vector<long double> &CF,int N,long double &r)
  {
    NPV=0;
    int t=0;
    for(t=0;t<=3;++t)
      NPV+=CF[t]/pow(1+r,t);
    return 1;
  }

int InternalRateofReturn(const vector<long double> &CF,int N,long double &IRR)
  {
    long double NPV=0;
    NetPresentValueRule(NPV,CF,N,IRR);
    if(NPV==0)
      return 1;
    do
      {
	IRR+=0.00001;
	NetPresentValueRule(NPV,CF,N,IRR);
      }while(NPV>0);
    return 1;
  }

int MoneyWeightedRateOfReturn(const vector<long double> &CF_OUTFLOW,const vector<long double> &CF_INFLOW,long double &r)
  {
    long double NPV_OUT=0;
    long double NPV_IN=0;
    NetPresentValueRule(NPV_OUT,CF_OUTFLOW,CF_OUTFLOW.size(),r);
    NetPresentValueRule(NPV_IN,CF_INFLOW,CF_INFLOW.size(),r);
    r=0;
    for(auto i=CF_OUTFLOW.begin();NPV_OUT<NPV_IN;++i)
      {
	r+=0.00001;
	NetPresentValueRule(NPV_OUT,CF_OUTFLOW,CF_OUTFLOW.size(),r);
	NetPresentValueRule(NPV_IN,CF_INFLOW,CF_INFLOW.size(),r);
      }
    return 1;
  }























