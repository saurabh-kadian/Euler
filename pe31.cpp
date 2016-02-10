#include <iostream>
using namespace std;
int main()
{
    unsigned long long int comb = 0;
    long int thund = 200, hund = 100, fif = 50, twen = 20, ten = 10, fiv = 5, two = 2, one = 1;
    long int total = 200;
    for(long int q = 0;q <= (total)/200;++q){
        long int totalLessq = total-(q*200);
        if(totalLessq<0)
            break;
        for(long int a = 0;a<= (totalLessq)/100; ++a){
            long int totalLessqa = totalLessq - (a*100);
            if(totalLessqa<0)
                break;
            for(long int z = 0;z<=(totalLessqa)/50;++z){
                long int totalLessqaz = totalLessqa - (z*50);
                if(totalLessqaz<0)
                    break;
                for(long int w = 0;w<= (totalLessqaz)/20 ;++w){
                    long int totalLessqazw = totalLessqaz - (w*20);
                    if(totalLessqazw<0)
                        break;
                    for(long int s = 0;s<= (totalLessqazw)/10;++s){
                        long int totalLessqazws = totalLessqazw - (s*10);
                        if(totalLessqazws<0)
                            break;
                        for(long int x = 0;x<= (totalLessqazws)/5;++x){
                            long int totalLessqazwsx = totalLessqazws - (x*5);
                            if(totalLessqazwsx<0)
                                break;
                            for(long int e=0 ; e<= (totalLessqazwsx)/2;++e){
                                long int totalLessqazwsxe = totalLessqazwsx - (e*2);
                                if(totalLessqazwsxe<0)
                                    break;
                                for(long int d=0;d<= (totalLessqazwsxe)/1;++d){
                                    long int totalLessqazwsxed = totalLessqazwsxe - (d*1);
                                    if(totalLessqazwsxed == 0)
                                        comb++;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << comb << endl;
    return 0;
}
