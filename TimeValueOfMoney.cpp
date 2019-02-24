#include "SelfFinancialTool.h"

using namespace std;


//打印数值
void Print(const long double &argument)
  {
    cout<<argument<<endl;
  }
void Print(const long double &argument,int n)//代表保留几位小数
  {
    cout<<setiosflags(ios::fixed)<<setprecision(n)<<argument<<endl;
  }
bool Divation(const long double &a,const long double &b,int CALC_ARGU)
  {
    if(CALC_ARGU==CALC_FCH)
      {
	if(b>=a||((a-b)>=0&&(a-b)<=1))
          return 1;
        else
          return 0;
      }
    if(CALC_ARGU==CALC_PCH)
    {
      if(b<=a||((a-b)<=0&&(a-b)>=-1))
        return 1;
      else
        return 0;
    }
  }


//例如求FV 则在传参的时候i置位CALC_FV
int FutureAndPresentValue(long double &FV,long double &PV,long double &r,long double &N,int CALC_ARGU)
  {
    if(CALC_ARGU!=CALC_FV&&CALC_ARGU!=CALC_PV&&CALC_ARGU!=CALC_R&&CALC_ARGU!=CALC_N)
      return 0;
    if(CALC_ARGU==CALC_FV)
      {
	FV=PV*powl(1+r,N);
	return 1;
      }
    else if(CALC_ARGU==CALC_PV)
      {
	PV=FV*(1/powl(1+r, N));
	return 1;
      }
    else if(CALC_ARGU==CALC_N)
      {
	N=logl(FV/PV)/logl(1+r);
	return 1;
      }
    else
      {
	r=powl(FV/PV,1/N)-1;
	return 1;
      }
    return 0;
    cout<<"非正常退出"<<endl;
  }
  
int FutureAndPresentValue_M(long double &FV,long double &PV,long double &rs,long double &N,int m,int CALC_ARGU)
  {
    if(CALC_ARGU!=CALC_FV&&CALC_ARGU!=CALC_PV&&CALC_ARGU!=CALC_R&&CALC_ARGU!=CALC_N)
      return 0;
    long double r=rs/m;
    long double N_REAL=N*m;
    if(CALC_ARGU==CALC_FV)
	FV=PV*powl(1+r,N_REAL);
    else if(CALC_ARGU==CALC_PV)
	PV=FV*(1/powl(1+r, N_REAL));
    else if(CALC_ARGU==CALC_N)
	N=logl(FV/PV)/logl(1+r)/m;
    else
      rs=(powl(FV/PV,1/N_REAL)-1)*m;
  }
int FutureAndPresentValue_Continuous(long double &FV,long double &PV,long double &r,long double &N,int CALC_ARGU)
  {
    if(CALC_ARGU!=CALC_FV&&CALC_ARGU!=CALC_PV&&CALC_ARGU!=CALC_R&&CALC_ARGU!=CALC_N)
      return 0;
    if(CALC_ARGU==CALC_FV)
      FV=PV*expl(r*N);
    else if(CALC_ARGU==CALC_PV)
      PV=FV/expl(r*N);
    else if(CALC_ARGU==CALC_R)
      r=logl(FV/PV)/N;
    else
      N=logl(FV/PV)/r;
  }
void EffectiveAnnualRate(long double &EAR,long double &PeriodicRate,int m)
  {
    EAR=powl(1+PeriodicRate,m)-1;
  }
int FutureValueOfCashFlow(long double &FV,long double &A,long double &r,long double &N,int CALC_ARGU)
  {
    if(CALC_ARGU!=CALC_FV&&CALC_ARGU!=CALC_A&&CALC_ARGU!=CALC_R&&CALC_ARGU!=CALC_N)
      return 0;
    if(CALC_ARGU==CALC_FV)
      {
	FV=A*((pow(1+r,N)-1)/r);
	return 1;
      }
    else if(CALC_ARGU==CALC_A)
      {
	A=FV/((pow(1+r,N)-1)/r);
	return 1;
      }
    else if(CALC_ARGU==CALC_R)
      {
	long double i;
	for(i=0.01;Divation(FV,A*(powl(1+i,N)-1)/i,CALC_FCH)!=1;i=i+0.00001)
	{
	  if(i==1)
	    {
	      cout<<"无法计算"<<endl;
	      return 0;
	    }
	}
	r=i;
	return 1;
      }
    else
      {
	N=logl((FV/A)*r+1)/logl(1+r);
	return 1;
      }
    cout<<"非正常退出"<<endl;
    return 0;
  }
int PresentValueOfCashFlow(long double &PV,long double &A,long double &r,long double &N,int CALC_ARGU)
  {
    if(CALC_ARGU!=CALC_PV&&CALC_ARGU!=CALC_A&&CALC_ARGU!=CALC_R&&CALC_ARGU!=CALC_N)
      return 0;
    if(CALC_ARGU==CALC_PV)
      {
	PV=A*((1-1/pow(1+r,N))/r);
	return 1;
      }
    else if(CALC_ARGU==CALC_A)
      {
	A=PV/((1-1/pow(1+r,N))/r);
	return 1;
      }
    else if(CALC_ARGU==CALC_R)
      {
	long double i;
	for(i=0.01;Divation(PV,A*(1-powl(1+i,-N))/i,CALC_PCH)!=1;i=i+0.0001)
	{
	  if(i==1)
	    {
	      cout<<"无法计算"<<endl;
	      return 0;
	    }
	}
	r=i;
	return 1;
      }
    else
      {
	N=logl(1/(1-PV*r/A))/logl(1+r);
	return 1;
      }
    cout<<"非正常退出"<<endl;
    return 0;
  }

int PresentValueInfiniteEqualCashFlow(long double &PV,long double &A,long double &r,int CALC_ARGU)
  {
    if(CALC_ARGU!=CALC_PV&&CALC_ARGU!=CALC_A&&CALC_ARGU!=CALC_R)
      return 0;
    if(CALC_ARGU==CALC_PV)
      {
	PV=A/r;
	return 1;
      }
    else if(CALC_ARGU==CALC_A)
      {
	A=PV*r;
	return 1;
      }
    else
      {
	r=A/PV;
	return 1;
      }
    cout<<"非正常推出"<<endl;
    return 0;
  }



















