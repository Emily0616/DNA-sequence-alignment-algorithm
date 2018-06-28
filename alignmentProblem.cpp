
#include <iostream>

#include <vector>

#include <string>

#include <windows.h>
using namespace std;

 

const int costCopy=-1;

const int costReplace=1;

const int costDelete=2;

const int costInsert=2;

enum {cop=1,replace,del,insert};

 

void trackBack(vector < vector<int> > operMatrix,const string &s1,

     const string &s2){

     int len1=s1.size();

     int len2=s2.size();

     string seq1,seq2;

     int i=len1;

     int j=len2;

     while(i>0&&j>0){

         switch(operMatrix[i][j]){

           case 1://copy

           {

             seq1.insert(seq1.begin(),s1[i-1]);

             seq2.insert(seq2.begin(),s2[j-1]);

             i--;j--;

             break;

           }

           case 2://replace

           {

             seq1.insert(seq1.begin(),s1[i-1]);

             seq2.insert(seq2.begin(),s2[j-1]);

             i--;j--;

             break;

           }

           case 3://delete

           {

             seq1.insert(seq1.begin(),s1[i-1]);

             seq2.insert(seq2.begin(),' ');

             i--;

             break;

           }

           case 4://insert

           {

             seq1.insert(seq1.begin(),' ');

             seq2.insert(seq2.begin(),s2[j-1]);

             j--;

             break;

           }      

         }

     }

     if(i==0){

       for(;j>0;j--){ 

         seq1.insert(seq1.begin(),' ');

         seq2.insert(seq2.begin(),s2[j-1]);

       }

     }

     else{

       for(;i>0;i--){

         seq1.insert(seq1.begin(),s1[i-1]);

         seq2.insert(seq2.begin(),' '); 

       }

     }

     cout<<seq1.c_str()<<endl;

     cout<<seq2.c_str()<<endl;

}

 

int levenshteinDistance(const string &s1,const string &s2){

  int len1=s1.size();

  int len2=s2.size();

  if(!len1) return len2;

  if(!len2) return len1;

  

  vector <vector <int> > dp(len1+1,vector <int>(len2+1,0));

  //record the action

  vector <vector <int> > oper(len1+1,vector <int>(len2+1,0));

 

  //initialize dp

  for(int i=1;i<len1+1;i++){

    dp[i][0]=dp[i-1][0]+costDelete;

    oper[i][0]=del;

  }

  for(int j=1;j<len2+1;j++){

    dp[0][j]=dp[0][j-1]+costInsert;

    oper[0][j]=insert;

  }

 

  //dp

  for(i=1;i<=len1;i++){

    for(int j=1;j<=len2;j++){

      int minDis=0;

      if(s1[i-1]==s2[j-1]){

        minDis=dp[i-1][j-1]+costCopy;

        oper[i][j]=cop;

      }

      else{

        minDis=dp[i-1][j-1]+costReplace;

        oper[i][j]=replace;

      }

      int tempDis=dp[i-1][j]+costDelete;

      if(minDis>tempDis){

        minDis=tempDis;

        oper[i][j]=del;

      }

      tempDis=dp[i][j-1]+costInsert;

      if(minDis>tempDis){

        minDis=tempDis;

        oper[i][j]=insert;

      }

      dp[i][j]=minDis;

    }

  }

  cout<<"***************************"<<endl;

  for(i=0;i<=len1;i++){

    for(int j=0;j<=len2;j++){

      cout<<dp[i][j]<<" ";

    }

    cout<<endl;

  }

  cout<<"**************************"<<endl;

  cout<<"***************************"<<endl;

  for(i=0;i<=len1;i++){

    for(j=0;j<=len2;j++){

      cout<<oper[i][j]<<" ";

    }

    cout<<endl;

  }

  cout<<"**************************"<<endl;

 

  trackBack(oper,s1,s2);

  return dp[len1][len2];

}

 

 

 

int main(){
  DWORD star_time = GetTickCount();

  string s1("GATCGGCAT");

  string s2("CAATGTGAATC");

  cout<<"�༭����:"<<levenshteinDistance(s1,s2)<<endl;
  DWORD end_time = GetTickCount();
  cout<<"����ʱ��Ϊ"<<end_time - star_time<<"ms."<<endl;
  return 0;

}
