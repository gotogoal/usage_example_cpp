#include <iostream>

using namespace std;

int main(void) {
    cout<<"this is c++ test";
    cout << endl;
    
    int arr[10];
    for(int i=0;i<10;i++)
    {
        arr[i]=i;
    }
    
    for(auto a : arr)
    {
        cout << a;
    }
    
    return 0;
}

//for(auto a:b)中b为一个容器，效果是利用a遍历并获得b容器中的每一个值，但是a无法影响到b容器中的元素。
//for(auto &a:b)中加了引用符号，可以对容器中的内容进行赋值，即可通过对a赋值来做到容器b的内容填充。