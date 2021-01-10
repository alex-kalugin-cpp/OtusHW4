/*!
\file
\brief Файл с тестами
Данный файл содержит в себе тестовые примеры выводов условного IP адреса

*/
#include "../include/IPPrinter.h"

#include "gtest/gtest.h"
#include <sstream>
#include <list>
#include <set>
#include <deque>
TEST(printIPtest, chartest){
        std::stringstream ss;
        printIP(ss,char('0'));
        std::string out = ss.str();
        EXPECT_EQ("48",out);
};
TEST(printIPtest, shorttest){
        std::stringstream ss;
        printIP(ss,short(1025));
        std::string out = ss.str();
        EXPECT_EQ("4.1",out);
};
TEST(printIPtest, inttest){
        std::stringstream ss;
        printIP(ss,int(1234));
        std::string out = ss.str();
        EXPECT_EQ("0.0.4.210",out);
};
TEST(printIPtest, longtest){
        std::stringstream ss;
        printIP(ss,long(-1));
        std::string out = ss.str();
        EXPECT_EQ("255.255.255.255.255.255.255.255",out);
};
TEST(printIPtest, literalstringtest){
    std::stringstream ss;
       printIP(ss,"ololo");
    std::string out = ss.str();
    EXPECT_EQ("ololo",out);
};
TEST(printIPtest, stringtest){
    std::stringstream ss;
    std::string in = "trololo";
    printIP(ss,in);
    std::string out = ss.str();
    EXPECT_EQ(in,out);
};
TEST(printIPtest, conteiner1){
std::stringstream ss;
std::vector<int> in{127,0,0,1};
printIP(ss,in);
std::string out = ss.str();
EXPECT_EQ("127.0.0.1",out);
}
TEST(printIPtest, conteiner2){
std::stringstream ss;
std::list<int> in{5,4,3,2,1};
printIP(ss,in);
std::string out = ss.str();
EXPECT_EQ("5.4.3.2.1",out);
}
TEST(printIPtest, conteiner3){
std::stringstream ss;
std::vector<int> in{};
printIP(ss,in);
std::string out = ss.str();
EXPECT_EQ("",out);
}
TEST(printIPtest, conteiner4){
std::stringstream ss;
std::set<int> in{2,1};
printIP(ss,in);
std::string out = ss.str();
EXPECT_EQ("1.2",out);
}
TEST(printIPtest, conteiner5){
std::stringstream ss;
std::deque<int> in{666};
printIP(ss,in);
std::string out = ss.str();
EXPECT_EQ("666",out);
}
TEST(printIPtest, tupletest1){
std::stringstream ss;
std::tuple<int,int,int,int> in = std::make_tuple(1,2,3,4);
printIP(ss,in);
std::string out = ss.str();
EXPECT_EQ("1.2.3.4",out);
}
TEST(printIPtest, tupletest2){
    std::stringstream ss;
    std::tuple<int,char,int> in = std::make_tuple(1,'2',3);
    printIP(ss,in);
    std::string out = ss.str();
    EXPECT_EQ("WARNING: Tulpe members are not same type",out);
};
TEST(printIPtest, tupletest3){
std::stringstream ss;
std::tuple<> in = std::make_tuple();
printIP(ss,in);
std::string out = ss.str();
EXPECT_EQ("",out);
}
int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
