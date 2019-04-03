#include "Kevin.h"

RPN::RPN()
{
    countt = 0;
    calcAns = 0;
    RPNed = false;
}

bool RPN::doneRPN()
{
    if(RPNed) return true;
    else return false;
}

void RPN::calAns()
{
    if(!doneRPN())
    {
        cout<<"Please use method doRPN first!"<<endl;
    }
    else
    {
        calcAns = calculate();

    }
}

double RPN::calculate()
{

    double ans = 0;
    double a,b;
    for(int i=0; i<countt; i++)
    {
        if(!isOper(Ans[i]))
        {
            double nowl = Ans[i] -'0';
            Cal.push(nowl);
        }
        else
        {
            switch(Ans[i])
            {
                case '+':
                    a = Cal.top();
                    Cal.pop();
                    b = Cal.top();
                    Cal.pop();
                    ans = (double)a+b;
                    Cal.push(ans);
                    break;

                case '-':
                    a = Cal.top();
                    Cal.pop();
                    b = Cal.top();
                    Cal.pop();;
                    ans = (double)b-a;
                    Cal.push(ans);
                    break;

                case '/':
                    a = Cal.top();
                    Cal.pop();
                    b = Cal.top();
                    Cal.pop();;
                    ans = (double)b / a;
                    Cal.push(ans);
                    break;

                case '*':
                    a = Cal.top();
                    Cal.pop();
                    b = Cal.top();
                    Cal.pop();
                    ans = (double)a*b;
                    Cal.push(ans);
                    break;
                default:
                    ;
            }
        }
    }
    double x = Cal.top();
    return x;
}

bool RPN::isOper(char a)
{
    if ((a == '+') || (a == '-') || (a == '*') || (a == '/')
        || (a == '(') || (a == ')') || (a == '='))
        return true;
    else return false;
}

void RPN::inputStr()
{
    cin >> Rawdata;
}

void RPN::doRPN()
{
    countt = 0;
    for (unsigned int j = 0; j < strlen(Rawdata); j++)  //单组数据处理
    {
        if (Rawdata[j] == '=')
        {
            while (!OPT.empty())
            {
                char etop = OPT.top();
                Ans[countt++] = etop;
                OPT.pop();
            }
            break;
        }
        if (isOper(Rawdata[j]))
        {
            switch (Rawdata[j])
            {
                case '(':
                {
                    OPT.push(Rawdata[j]);
                    break;
                }
                case ')':
                {
                    while (1)
                    {
                        char wtop = OPT.top();
                        if (wtop == '(')
                        {
                            OPT.pop();
                            break;
                        }
                        else
                        {
                            Ans[countt++] = wtop;
                            OPT.pop();
                            wtop = OPT.top();
                        }
                    }

                    break;

                }

                default:
                {
                    while (1)
                    {
                        char itop;
                        if (OPT.empty())
                        {
                            OPT.push(Rawdata[j]);
                            break;
                        }
                        itop = OPT.top();
                        if (isPrio(itop, Rawdata[j]))
                        {
                            Ans[countt++] = itop;
                            OPT.pop();
                            if(!OPT.empty())
                                itop = OPT.top();
                        }
                        else
                        {
                            OPT.push(Rawdata[j]);
                            break;
                        }
                    }


                }

            }
        }

        else
        {
            Ans[countt++] = Rawdata[j];
        }
    }
    RPNed = true;
}


void RPN::outputAns()
{
    cout<<Ans<<endl;
    cout<<calcAns<<endl;
}

bool RPN::isFinish()
{
    if (Rawdata[0] == '=')return true;
    else return false;
}

bool RPN::isPrio(char top,char now )
{
    //相同优先级
    if (((top == '+')||(top == '-')) && ((now == '+') || (now == '-'))) return true;
    if (((top == '*')||(top == '/')) && ((now == '*') || (now == '/'))) return true;
    //括号优先级
    if (now == ')') return true;
    //较高优先级
    if (((top== '*') || (top == '/')) && ((now == '+') || (now == '-'))) return true;
    return false;

};