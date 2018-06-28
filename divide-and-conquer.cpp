#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<math.h>
#include<algorithm>

#include <time.h>
#include <windows.h>
using namespace std;
int opt(int i,int j);

char x[10]={'A','A','C','A','A','C','T'};
char y[10]={'T','A','A','A','C','T','C'};
int m=0,n=0;

int opt(int i,int j)
{
    int penalty;
    if(i==m)
        return 2*(n-j);
    else if(j==n)
        return 2*(m-i);
    else{
        if(x[i]==y[j])
            penalty=0;
        else
            penalty=1;
        return min(opt(i+1,j+1)+penalty,min(opt(i+1,j)+2,opt(i,j+1)+2));
    }
}
int main(){
	DWORD star_time = GetTickCount();
    m=strlen(x);
    n=strlen(y);
    int op=opt(0,0);
	DWORD end_time = GetTickCount();
	cout<<m<<" "<<n<<endl;
    cout<<op<<endl;
	cout<<"运行时间为"<<end_time - star_time<<"ms."<<endl;
	return 0;
}