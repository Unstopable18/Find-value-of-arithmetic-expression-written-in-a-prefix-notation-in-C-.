#include<iostream>
#include<cmath>
#include<stack>
using namespace std;

double prifixEval(string prefixExp) 
{
   
    stack<double> operendStack;
    int size = prefixExp.size() - 1;
    for (int i = size; i >= 0; i--) 
    {

        if (isdigit(prefixExp[i]))
            operendStack.push(prefixExp[i] - '0');
        else 
        {
            double o1 = operendStack.top();
            operendStack.pop();
            double o2 = operendStack.top();
            operendStack.pop();
            if( prefixExp[i] == '+')
                operendStack.push(o1 + o2);
            else if( prefixExp[i] == '-')
                operendStack.push(o1 - o2);
            else if( prefixExp[i] == '*')
                operendStack.push(o1 * o2);
            else if( prefixExp[i] == '/')
                operendStack.push(o1 / o2);
            else
            {
                cout<<"Invalid Expression";
                return -1;
            }
        }
    }
    return operendStack.top();
}

int main()
{
   string prefixExp = "*+552";
   cout<<"\n****************************************";
   cout<<"\n    ***Pri Fix Evalution***";
   cout<<"\n****************************************";
   cout<<"\nThe Arihtmetic Expression Given is:\n"<<prefixExp;
   cout<<"\n****************************************";
   cout<<"\nSolution:- "<<prifixEval(prefixExp);
   cout<<"\n****************************************";
   return 0;
}