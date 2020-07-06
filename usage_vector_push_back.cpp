#include<iostream>
#include<vector>

using namespace std;


int main()
{
	vector<int> a;
	cout << a.size() << endl;
	for(int i=0; i<10; i++)
	{
		a.push_back(9 - i);
	}

	cout << a.size() << endl;
	for(int i=0; i<10; i++)
	{
		cout << a[i] << endl;
	}

	return 0;
}
