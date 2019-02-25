
objects=test.o TimeValueOfMoney.o DiscountedCashFlow.o
edit:$(objects)
	g++ -g -o  edit $(objects)

test.o:test.cpp SelfFinancialTool.h
	g++ -std=c++11 -c test.cpp
TimeValueOfMoney.o:TimeValueOfMoney.cpp SelfFinancialTool.h
	g++ -std=c++11 -c TimeValueOfMoney.cpp
DiscountedCashFlow.o:DiscountedCashFlow.cpp SelfFinancialTool.h
	g++ -std=c++11 -c DiscountedCashFlow.cpp
clean: rm edit $(objects)
check-syntax:
	g++ -o nul -S ${CHK_SOURCES} 
