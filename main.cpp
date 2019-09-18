#include <iostream> 
#include <string> 
#include <cmath> 
#include <stack>
#include <stdio.h>
#include<time.h>
#include<stdlib.h>
#include"biaodashi.h"
using namespace std; 
const double PRECISION = 1E-6; 
const int COUNT_OF_NUMBER  = 4; 
const int NUMBER_TO_CAL = 24; 

double number[COUNT_OF_NUMBER]; 
string expression[COUNT_OF_NUMBER]; 

bool Search(int n) 
{ 
    if (n == 1) { 
        if ( fabs(number[0] - NUMBER_TO_CAL) < PRECISION ) { 
            cout << expression[0] << endl; 
            return true; 
        } else { 
            return false; 
        } 
    } 

    for (int i = 0; i < n; i++) { 
        for (int j = i + 1; j < n; j++) { 
            double a, b; 
            string expa, expb; 

            a = number[i]; 
            b = number[j]; 
            number[j] = number[n - 1]; 

            expa = expression[i]; 
            expb = expression[j]; 
            expression[j] = expression[n - 1]; 

            expression[i] = '(' + expa + '+' + expb + ')'; 
            number[i] = a + b; 
            if ( Search(n - 1) ) return true; 
            
            expression[i] = '(' + expa + '-' + expb + ')'; 
            number[i] = a - b; 
            if ( Search(n - 1) ) return true; 
            
            expression[i] = '(' + expb + '-' + expa + ')'; 
            number[i] = b - a; 
            if ( Search(n - 1) ) return true; 
                        

            expression[i] = '(' + expa + '*' + expb + ')'; 
            number[i] = a * b; 
            if ( Search(n - 1) ) return true; 

            if (b != 0) { 
                expression[i] = '(' + expa + '/' + expb + ')'; 
                number[i] = a / b; 
                if ( Search(n - 1) ) return true; 
            } 
            if (a != 0) { 
                expression[i] = '(' + expb + '/' + expa + ')'; 
                number[i] = b / a; 
                if ( Search(n - 1) ) return true; 
            } 

            number[i] = a; 
            number[j] = b; 
            expression[i] = expa; 
            expression[j] = expb; 
        } 
    } 
    return false; 
} 

int main() 
{ 
	int select=1;
	while(select!=0)
	{
	
		cout<<"****************************************************"<<endl;
		cout<<"                    24����Ϸ"<<endl;
		cout<<"****************************************************"<<endl;
		char buffer[20];
	    char s[105];
	    int  x; 
	    srand((unsigned)time(NULL)); 
		for(int i=0;i< COUNT_OF_NUMBER; i++)
	    {
			number[i] = rand()%13+1;
			itoa((int)number[i] , buffer, 10); 
			expression[i] = buffer; 	   
		}
		cout<<COUNT_OF_NUMBER<<"������Ϊ��";
		for (int i = 0; i < COUNT_OF_NUMBER; i++) { 
			cout<<number[i]<<" ";
		} 
		cout<<endl;
		/*for(int i=1;i<COUNT_OF_NUMBER; i++)
			for(int j=0;j<i;j++)
				if(number[i]-number[j]<0.001){
					cout<<"�����ظ�"<<endl;
				}	*/	

		cout<<"1.������ʽ   "<<endl;
		cout<<"2.�鿴��ȷ���ʽ "<<endl;
		cout<<"��ѡ��";
			int s1;
			cin>>s1;
			switch(s1)
			{
			case 1:
				cout<<"�����룺";
				scanf("%s",s);
				//cout<<"�����" << EvaluateExpression(s) << endl;
				if(EvaluateExpression(s)==24)
					cout<<"���ʽ��ȷ"<<endl;
				else	
				{
					cout<<"���ʽ����,���Ϊ"<<EvaluateExpression(s)<<endl;	
					if ( !Search(COUNT_OF_NUMBER) ) { 
					cout << "�����޽�." << endl; 
				} 
				}
				system("pause");
				break;
			case 2:
				if ( !Search(COUNT_OF_NUMBER) ) { 
					cout << "�����޽�." << endl; 
				} 
				system("pause");
				break;
			default:
				cout<<"�������"<<endl;
				system("pause");
				break;

			}	

   }
	return 0;
	
	}
