#ifndef SELF_FINANCIAL_TOOL_H
#define SELF_FINANCIAL_TOOL_H
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;

#define WANT_GET 0
#define CALC_FV 1
#define CALC_PV 2
#define CALC_R 3
#define CALC_N 4 //设置标志位求取哪个值
#define CALC_A 5
#define CALC_FCH 6
#define CALC_PCH 7
void Print(const long double &argument);
void Print(const long double &argument,int n);
bool Divation(const long double &a,const long double &b,int CALC_ARGU);
int FutureAndPresentValue(long double &FV,long double &PV,long double &r,long double &N,int CALC_ARGU);
int FutureAndPresentValue_M(long double &FV,long double &PV,long double &rs,long double &N,int m,int CALC_ARGU);
int FutureAndPresentValue_Continuous(long double &FV,long double &PV,long double &r,long double &N,int CALC_ARGU);
void EffectiveAnnualRate(long double &EAR,long double &PeriodicRate,int m);
int FutureValueOfCashFlow(long double &FV,long double &A,long double &r,long double &N,int CALC_ARGU);
int PresentValueOfCashFlow(long double &PV,long double &A,long double &r,long double &N,int CALC_ARGU);
int PresentValueInfiniteEqualCashFlow(long double &PV,long double &A,long double &r,int CALC_ARGU); 
int NetPresentValueRule(long double &NPV,const vector<long double> &CF,int N,long double &r);//NPV:net present value

int InternalRateofReturn(const vector<long double> &CF,long int N,long double &IRR);
#endif

int MoneyWeightedRateOfReturn(const vector<long double> &CF_OUTFLOW,const vector<long double> &CF_INFLOW,long double &r);
















