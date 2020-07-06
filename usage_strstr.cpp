#include <iostream>
#include<string.h>
using namespace std;

int main(void) {
    cout<<"this is c++ test";
    cout << "\n";
    
    char str[] = "http://see.xidian.edu.cn/cpp/u/xitong/";
    char substr[] = "see";
	
    char *before = strstr(str, substr);
    char *after = strstr(str, "xidian");
	
    cout << before << endl;;
    cout << after << endl;
	
	//等价于string mid(before+1,after);
    string mid = string(before + 1, after);
    cout << mid << endl;
    
    return 0;
}