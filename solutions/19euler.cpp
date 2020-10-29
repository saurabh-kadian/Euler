#include <iostream>
using namespace std;
int main()
{
    int sun_count = 0;
    int monscore[]={0,1,4,4,0,2,5,0,3,6,1,4,6};
    for(int cen_year=1901;cen_year<2001;++cen_year)
    {
        int century = cen_year/100;
        int year = cen_year%100;
        for(int month = 1;month <= 12; ++month)
        {
            long long int exp=0;
            exp += year;
            exp /= 4;
            exp += 1;
            if(cen_year%4==0 && (month == 1 || month == 2))
                exp+=(monscore[month]-1);
            else
                exp+=monscore[month];
            if(century==19)
                exp+=0;
            else
                exp+=6;
            exp+=year;
            exp%=7;
            if(exp==1)
                sun_count++;
        }
    }
    cout << sun_count << endl;
    return 0;
}
