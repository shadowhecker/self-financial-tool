
objects=test.o TimeValueOfMoney.o
edit:$(objects)
	g++ -g -o  edit $(objects)

test.o:test.cpp SelfFinancialTool.h
	g++ -c test.cpp
TimeValueOfMoney.o:TimeValueOfMoney.cpp SelfFinancialTool.h
	g++ -c TimeValueOfMoney.cpp
clean: rm edit $(objects)
check-syntax:
	g++ -o nul -S ${CHK_SOURCES} 
