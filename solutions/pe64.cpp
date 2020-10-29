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
    vector<long long int> perSq;
	long long int counter = 0;
	for(int i=0;i<1000;++i){
        if(i*i <= 10000)
            perSq.push_back(i*i);
        else
            break;
	}
	for(int i=2;i<10000;++i){
        vector<long long int>::iterator it = find(perSq.begin(),perSq.end(),i);
        if(it != perSq.end())
            continue;
        int mNot = 0,dNot = 1;
        int aNot;
        for(int j=0;j<perSq.size();++j){
            if(i > perSq[j] && i < perSq[j+1]){
                aNot = j;
                break;
            }
        }
        int aNplus1 = aNot;
        int len = 0;
        do{
            mNot = dNot*aNplus1-mNot;
            dNot = (i-mNot*mNot)/dNot;
            aNplus1 = (aNot+mNot)/dNot;
            len++;
        }while(aNot*2 != aNplus1);
        if(len%2 == 1)
            counter++;
	}
	cout << counter << endl;
	return 0;
}
    /*
	vector<long long int> perSq;
	long long int counter = 0;
	for(int i=0;i<1000;++i){
        if(i*i <= 10000)
            perSq.push_back(i*i);
        else
            break;
	}
	for(int i=2;i<10000;++i){
        vector<long long int>::iterator it = find(perSq.begin(),perSq.end(),i);
        if(it != perSq.end())
            continue;
        string analysis;
        int aNot;
        for(int j=0;j<perSq.size();++j){
            if(i > perSq[j] && i < perSq[j+1]){
                aNot = j;
                break;
            }
        }
        analysis += (char)(aNot+48);
        int baseInit = i - aNot*aNot;
        int factor = (2*aNot)/baseInit;
        int nextSub = factor*baseInit-aNot;
        analysis += (char)(factor+48);
        for(int j=0;j < 3000;++j){
            int x = nextSub;
            int q = i - x*x;
            q /= baseInit;
            int number;
            if((2*x)/q == 0)
                number = 1;
            else
                number = (2*x)/q;
            nextSub = number*q-x;
            analysis += (char)(number+48);
            baseInit = q;
        }
        long long int answer = analyser(analysis);
        cout << "#root (" << i << ")  =  " << answer << endl;
        if(answer%2 == 1)
            counter++;
	}*/
/*
long long int analyser(string str){
    long long int length = str.length();
    for(long long int sizer = 1;sizer < length;++sizer){
        if(sizer > 500)
            system("pause");
        string part1 = str.substr(length-1-sizer,sizer);
        bool fff = true;
        for(int i=1;i<8;++i){
            string parter = str.substr(length-1-(i*sizer),sizer);
            if(parter != part1)
                fff = false;
        }
        if(fff)
            return sizer;
    }
    return 0;
}*/
