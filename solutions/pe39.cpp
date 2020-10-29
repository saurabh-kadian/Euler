#include <iostream>
#include <string>
using namespace std;
bool is_right(long int h,long int p,long int b){
    h = h*h;
    p = p*p;
    b = b*b;
    if(h == (p+b) || p == (h+b) || b == (h+p))
        return true;
    return false;
}
int main(){
    long int maxi = 0,temp = 0;
    for(long int p=600;p<=1000;++p){
            long int counter = 0;
    for(long int i=1;i<=p/2;++i){
        for(long int j=1;j<=p/2;++j){
            for(long int k=1;k<=p/2;++k){
                    if(is_right(i,j,k) == true && (i+j+k) == p){
                    counter++;
                }
            }
        }
    }
    if(maxi < counter/6){
        maxi = counter/6;
        temp = p;
        cout << maxi << " " << p << endl;}
    }
    cout << temp << endl;
    return 0;
}
