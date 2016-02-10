#include <cstdio>
#include <iostream>
#include <limits>
#include <cstdlib>
#include <cstring>

using namespace std;
int main()
{
    int maxi = numeric_limits<long int>::max();
    for(long int x6 = 12000; x6<maxi ; x6=x6+6)
    {
        long int x=(x6/6),x3=(x6/2);
        char x_str[10],x3_str[10],x6_str[10];
        int x_c[10]={0},x3_c[10]={0},x6_c[10]={0};
        sprintf(x_str,"%ld",x);
        sprintf(x3_str,"%ld",x3);
        sprintf(x6_str,"%ld",x6);
        if(strlen(x_str)==strlen(x6_str))
        {
            cout << x << " " << x3 << " " << x6 << endl;
            int x_len = strlen(x_str);
            int x3_len = strlen(x3_str);
            int x6_len = strlen(x6_str);
            for(int i=0;i<x6;++i)
            {
                int temp = x%10;
                x_c[temp]++;
                x/=10;
                temp = x3%10;
                x3_c[temp]++;
                x3/=10;
                temp = x6%10;
                x6_c[temp]++;
                x6/=10;
            }
            bool answer = true;
            for(int i=0;i<9;++i)
            {
                if(x_c[i]!=x3_c[i] || x3_c[i]!=x6_c[i])
                    {answer = false;
                    break;}
            }
            if(answer==true)
               {cout << x;return 0;}
        }
        else
            continue;
    }
    return 0;
}
