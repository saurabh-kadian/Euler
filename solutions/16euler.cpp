#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main()
{
    int number[500],carry[500];
    for(int i=0;i<500;i++)
    {
        number[i] = -1;
        carry[i] = 0;
    }
    number[499] = 2;
    for(int i=2;i<=1000;++i)
    {
        int index=499;
        while(number[index]!=(-1))
        {
            int temp = number[index];
            temp *= 2;
            if(temp >= 10)
            {
                number[index] = temp%10;
                carry[index-1] = 1;
            }
            else
            {
                number[index] = temp;
            }
            index--;
        }
        index = 499;
        while(number[index]!=(-1))
        {
            number[index]+=carry[index];
            index--;
        }
        if(carry[index]==1)
            number[index]=1;
        for(;index<500;++index)
            carry[index]=0;
    }
    int index = 499;
    long int sum = 0;
    while(number[index]!=(-1))
    {
        sum+=number[index];
        index--;
    }
    cout << sum << endl;
    system("pause");
    return 0;
}
