#include <iostream>
#include<string.h>
#include <boost/algorithm/string/trim.hpp>
using namespace std;

int main(void) {
    cout<<"this is c++ test";
    cout << endl;

    string test = " hello I am OK! ";
    cout << test << endl;
    cout << test.size() << endl; //16

    boost::trim(test);  //��λ�ո�ȥ�����ı�ԭ�ַ���
    cout << test << endl;

    cout << test.size() << endl; //14

    return 0;
}