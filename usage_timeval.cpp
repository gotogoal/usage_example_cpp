#include <iostream>
#include <sys/time.h>
using namespace std;

int main(void) {
    cout<<"this is c++ test";
    cout << endl;
    
    struct timeval t_TimeStart, t_TimeEnd;
    gettimeofday(&t_TimeStart, NULL);
    gettimeofday(&t_TimeEnd, NULL);
    
    cout << "time cost!" << endl;
    
    cout << t_TimeEnd.tv_usec - t_TimeStart.tv_usec << endl;
    cout << t_TimeEnd.tv_sec - t_TimeStart.tv_sec << endl;
    
    return 0;
}