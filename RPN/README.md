# 逆波兰表达式

《数据结构》中关于栈的解释经常会涉及到逆波兰式，波兰式，中缀式表达式的求值问题。本文件是用于数据结构期末作业的一个逆波兰表达式库，具体方法有如下：

```cpp

class RPN {
public:
    RPN();
    void inputStr();		//输入数据【char类型字符串】
    void calAns();			//计算表达式值
    void doRPN();			//计算逆波兰表达式并保存到Ans
    void outputAns();		//输出逆波兰表达式和计算值
    bool isFinish();	//多组数据输入结束判断
    

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
```

