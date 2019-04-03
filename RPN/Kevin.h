#pragma once
#include <cstring>
#include <iostream>
#include <stack>
using namespace std;

class RPN {
public:
    RPN();
    void inputStr();
    void calAns();
    void doRPN();
    void outputAns();
    bool doneRPN();
    bool isFinish();
    bool isOper(char);
    bool isPrio(char,char);
    double calculate();

private:
    char Ans[100];
    char Rawdata[100];
    int countt;
    bool RPNed;
    double calcAns;
    stack<char> OPT;
    stack<double> Cal;
};