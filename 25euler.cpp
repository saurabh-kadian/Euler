#include <iostream>
using namespace std;
int main()
{
    int fibbo1[1000],fibbo2[1000],fibbofin[1000];
    for(int i=0;i<1000;++i)
        fibbo1[i]=fibbo2[i]=fibbofin[i]=-1;
    unsigned long long int counter = 2;
    fibbo1[999]=fibbo2[999]=1;
    while(1)
    {
        counter++;
        int carry = 0;
        for(int index = 999;fibbo2[index]!=-1;--index){
            if(fibbo1[index]!=-1){
            fibbofin[index]=fibbo1[index]+fibbo2[index]+carry;
            carry = fibbofin[index]/10;
            fibbofin[index] = fibbofin[index]%10;
            }
            else
                fibbofin[index]=fibbo2[index];
        }
        for(int i=0;i<999;++i)
        {
            fibbo1[i]=fibbo2[i];
            fibbo2[i]=fibbofin[i];
        }
        if(fibbofin[997]!=-1)
            break;
        cout << counter << endl;
    }
    cout << counter << endl;
    return 0;
}
