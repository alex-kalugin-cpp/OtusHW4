/*!
\file
\brief Файл с печатью условного IP адреса

Данный файл содержит в себе прикладной код
печати условного IP адреса при различных входных значениях
*/

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include "include/IPPrinter.h"
#include "include/toPrintTuple.h"


int main()
{
    //main1
    char ch = -1;
    short sh = 0;
    int ii = 2130706433;
    unsigned long long li = 8875824491850138409;

    std::cout << "\n";
       //print integral types
    /*!
    \brief вывод интегральных типов


    */
    {
         printIP(std::cout,ch);
         std::cout << "\n";
         printIP(std::cout,sh);
         std::cout << "\n";
         printIP(std::cout,ii);
         std::cout << "\n";
         printIP(std::cout,li);
         std::cout << "\n";

    }
       std::string s1 = "localhost";
       std::vector<int>v1{1,2,3,4};
       std::list<int> l1{5,6,7,8};
       //print string and containers
   {
           printIP(std::cout,s1);
           std::cout << "\n";
           printIP(std::cout,v1);
           std::cout << "\n";
           printIP(std::cout,l1);
           std::cout << "\n";
   }
       //opional print tuple
        std::tuple<int,int,int,int> t1 = std::make_tuple(0, 1, 2, 3);
       {
            printIP(std::cout,t1);
            std::cout << "\n";
       }

      std::cout << "\n";
       return 0;
}
