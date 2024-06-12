#include"codebegin.h"
class  base
{
public:
virtual void f()
{

       cout<<"base::f()"<<"address :"<<this<<endl;
}
~base()
{
      cout<<"~base()"<<"address :"<<this<<endl;
} 
};


class  a :public base
{
public:
void f()
{

       cout<<"a::f()"<<"address :"<<this<<endl;
}

~a()
{
      cout<<"~a()"<<"address :"<<this<<endl;
} 
};

int main() 
{ 
      int a=1;
      int b=2;
      return 0;
}
 