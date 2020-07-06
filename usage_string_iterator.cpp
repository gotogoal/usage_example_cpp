#include <iostream>
#include<string>

using namespace std;

int main(void) {
    cout<<"this is c++ test";
    cout << "\n";
    
    string s1 = "abcdefghijk";
    for(int i = 0; i < s1.length(); i++)
    {
        cout <<s1[i] << " "; 
    }
    
    cout << endl;
    
    string::iterator it;
    for(it = s1.begin(); it != s1.end(); it++)
    {
        cout << *it << " ";
    }
    
    return 0;
}