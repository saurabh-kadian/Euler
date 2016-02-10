#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <cstdlib>
#include <string>
#include <cmath>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <iterator>
using namespace std;
int main(){
    long long int o1,o2,o3,o4,o5;
    long long int i1,i2,i3,i4,i5;
    string str = "0123456789";
    string maxi = "0";
    long int counter = 0;
    do{
        counter++;
        o1 = str[0]-48;
        if(o1 == 0)
            o1 = 10;
        o2 = str[1]-48;
        if(o2 == 0)
            o2 = 10;
        o3 = str[2]-48;
        if(o3 == 0)
            o3 = 10;
        o4 = str[3]-48;
        if(o4 == 0)
            o4 = 10;
        o5 = str[4]-48;
        if(o5 == 0)
            o5 = 10;
        i1 = str[5]-48;
        if(i1 == 0)
            i1 = 10;
        i2 = str[6]-48;
        if(i2 == 0)
            i2 = 10;
        i3 = str[7]-48;
        if(i3 == 0)
            i3 = 10;
        i4 = str[8]-48;
        if(i4 == 0)
            i4 = 10;
        i5 = str[9]-48;
        if(i5 == 0)
            i5 = 10;
        if(((o1+i1+i2) == (o2+i2+i3)) && ((o2+i2+i3) == (o3+i3+i4)) && ((o3+i3+i4) == (o4+i4+i5)) && ((o4+i4+i5) == (o5+i5+i1)) && ((o5+i5+i1) == (o1+i1+i2))){
            if(o1+o2+o3+o4+o5 != 40)
                continue;
            string str1 = "";
            string part[6] = {"","","","","",""};
            part[1] += o1+48;
            part[1] += i1+48;
            part[1] += i2+48;
            part[2] += o2+48;
            part[2] += i2+48;
            part[2] += i3+48;
            part[3] += o3+48;
            part[3] += i3+48;
            part[3] += i4+48;
            part[4] += o4+48;
            part[4] += i4+48;
            part[4] += i5+48;
            part[5] += o5+48;
            part[5] += i5+48;
            part[5] += i1+48;
            sort(part+1,part+6);
            for(int p=1;p<6;++p){
                for(int i=0;i<part[p].length();++i){
                    if(part[p][i] == ':'){
                        part[p].erase(part[p].begin()+i);
                        part[p].insert(i,"10");
                    }
                }
            }
            str1 += part[1];
            str1 += part[5];
            str1 += part[4];
            str1 += part[3];
            str1 += part[2];
            if(str1 > maxi && str1.length() == 16)
                maxi = str1;
        }
    }while(next_permutation(str.begin(),str.end()));
    cout << "ProjectEuler 68 : " << maxi << endl;
	return 0;
}
