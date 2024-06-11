#include"codebegin.h"
class alignas(alignof(int)*4) a
{
 public:
     int s1:2;
     int s2:2;
};

int main() 
{   
    a o1[2];
    int *P=(int *)&o1;
    *(P)=1;
    *(P+3)=4;
    cout<<"alignof(a)"<<alignof(a)<<endl;
    cout<<"memory block likes this"<<endl;
    for (size_t i = 0; i < 4; i++)
    {
          cout<<* (P+i)<<endl;
    }
    cout<<"Adjacent memory block"<<endl;
    for (size_t i = 0; i < 4; i++)
    {
          cout<<* (P+i+4)<<endl;
    }
    o1[0].s1=1;
    o1[0].s2=2;

    cout<<"after o1[0].s1=1;  o1[0].s2=2;"<<endl;
    cout<<"memory block likes this"<<endl;
    for (size_t i = 0; i < 4; i++)
    {
          cout<<* (P+i)<<endl;
    }
     return 1;
}
 