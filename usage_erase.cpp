#include <iostream>
#include <vector>


using namespace std;

int main(void) {
    cout<<"this is c++ test" << endl;
    vector<string> orig_terms(3, "hello");
    orig_terms.push_back(" ");
    orig_terms.push_back("Jim");
    
    for (int i = orig_terms.size()-1; i >= 0; i--)
    {
        if (orig_terms[i] == " ")
        {
            orig_terms.erase(orig_terms.begin()+i);
        }
    }
    
    for (int i = orig_terms.size()-1; i >= 0; i--)
    {
        cout << orig_terms[i] << endl;
    }

    return 0;
}
