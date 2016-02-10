#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;
int main()
{
    long long int pent[5000],mindiff = 999999;
    for(int i=0;i<5000;++i)
        pent[i] = (i*(3*i-1))/2;
    for(int i=1;i<5000;++i){
        for(int j=i+1;j<5000;++j){
            long long int sum = pent[j]+pent[i];
            bool found = false;
            for(int k=1;k<5000;++k){
                if(sum == pent[k]){
                    found = true;
                    break;
                }
            }
            if(found == false)
                continue;
            long long int diff = pent[j]-pent[i];
            found = false;
            for(int k=1;k<5000;++k){
                if(diff == pent[k]){
                    found = true;
                    break;
                }
            }
            if(found == false)
                continue;
            cout << i << "=" << pent[i] << " " << j << "=" << pent[j] << endl;
            if(diff < mindiff){
                mindiff = diff;
            }
        }
    }
    cout << mindiff;
    return 0;
}
