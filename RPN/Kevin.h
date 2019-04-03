#pragma once
#include <cstring>
#include <iostream>
#include <stack>
using namespace std;

class RPN {
public:
    RPN();
    void inputStr();		//������ʽ
    void calAns();			//������ʽֵ
    void doRPN();			//�����沨�����ʽ
    void outputAns();		//����沨�����ʽ�ͱ��ʽֵ
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
