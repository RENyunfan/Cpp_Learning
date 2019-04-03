#pragma once
#include <cstring>
#include <iostream>
#include <stack>
using namespace std;

class RPN {
public:
    RPN();
    void inputStr();		//输入表达式
    void calAns();			//计算表达式值
    void doRPN();			//计算逆波兰表达式
    void outputAns();		//输出逆波兰表达式和表达式值
    bool isFinish();
private:
    char Ans[100];
    char Rawdata[100];
    int countt;
    bool RPNed;
    double calcAns;
    stack<char> OPT;
    stack<double> Cal;
    bool doneRPN();
    bool isOper(char);
    bool isPrio(char,char);
    double calculate();
};
