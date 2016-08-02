/*
ID: ace1o1o2
PROG: beads
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <cstring>
#include "limits.h"
#include <stdio.h>
using namespace std;

ifstream fin("beads.in");
ofstream fout("beads.out");

#ifdef _DEBUG
#define out cout
#define in cin
#else
#define out fout
#define in fin
#endif

//为简化代码，在数组前后各加1位，这样i+1,i-1不会越界，也无需对边界情况特殊处理。
int l[2][702];
int r[2][702];


void solve()
{
    int num;
    in>>num;

    string s;
    in>>s;
    s+=s;

    std::memset(r,0,sizeof(l));
    std::memset(r,0,sizeof(r));

    for(int i=s.size();i>=1;--i){
        if(s[i-1]=='r'){
            r[0][i] = r[0][i+1]+1;
            r[1][i] = 0;
        }else if(s[i-1]=='b'){
            r[0][i] = 0;
            r[1][i] = r[1][i+1]+1;
        }else{
            r[0][i] = r[0][i+1]+1;
            r[1][i] = r[1][i+1]+1;
        }
    }

    for(int i=1;i<=s.size();++i){
        if(s[i-1]=='r'){
            l[0][i] = l[0][i-1]+1;
            l[1][i] = 0;
        }else if(s[i-1]=='b'){
            l[0][i] = 0;
            l[1][i] = l[1][i-1]+1;
        }else{
            l[0][i] = l[0][i-1]+1;
            l[1][i] = l[1][i-1]+1;
        }
    }

    int res = INT_MIN;

    for(int i=1;i<=num;++i){
        res = max(res, max(r[0][i],r[1][i])+max(l[0][i+num-1],l[1][i+num-1]));
    }

    // 在出现重叠的情况下，res会大于num.最大只能是num
    res = min(res,num);

    out<<res<<endl;
}

int main(int argc,char *argv[])
{
    solve();
    return 0;
}