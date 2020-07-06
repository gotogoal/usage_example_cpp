#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;


bool myfunction(int i,int j)
{
    return (i<j);//升序排列
}

bool myfunction2(int i,int j)
{
    return (i>j);//降序排列
}

struct myclass
{
  bool operator()(int i,int j)
  {
      return (i<j);
  }
}myobject;
    

int main ()
{
    cout<<"this is c++ test";
    cout << endl;

    int a[10]={2, 4, 1, 23, 5, 76, 0, 43, 24, 65};

    for(int i=0; i<10; i++)
        cout << a[i] << ' ';

    //输出结果是升序排列。（两个参数的sort默认升序排序）
    sort(a, a+10);

    cout << endl;

    for(int i=0; i<10; i++)
        cout << a[i] << ' ';
        
    cout << endl;

    //展示第三个参数使用
    int myints[8] = {32, 71, 12, 45, 26, 80, 53, 33};
    vector<int> myvector (myints, myints+8);
    
    // using default comparison (operator <):
    sort(myvector.begin(), myvector.begin()+4);
    //(12 32 45 71)26 80 53 33
    for (vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
        cout << ' ' << *it;
    cout << endl;
    
    // using function as comp
    sort(myvector.begin()+4, myvector.end(), myfunction);
    // 12 32 45 71(26 33 53 80)
    for (vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
        cout << ' ' << *it;
    cout << endl;

    // using object as comp
    sort(myvector.begin(), myvector.end(), myobject);
    //(12 26 32 33 45 53 71 80)
    for (vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
        cout << ' ' << *it;
    cout << endl;

    cout << "myvector contains:";
    for (vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
        cout << ' ' << *it;
        
    cout << '\n';
    return 0;
}