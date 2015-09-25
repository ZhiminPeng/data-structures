
#include <iostream>
using namespace std;

int main ()
{
   int  var;
   int  *ptr;
   int  **pptr;

   var = 3000;

   /* take the address of var */
   ptr = &var;

   /* take the address of ptr using address of operator & */
   pptr = &ptr;

   /* take the value using pptr */
   cout<<var<<endl;
   cout<<ptr<<endl;
   cout<<&ptr<<endl;
   cout<<pptr<<endl;

   return 0;
}
