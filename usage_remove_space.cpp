#include <iostream>
#include <vector>
#include <string>
#include <memory.h>
#include <boost/algorithm/string.hpp>
using namespace std;


//g++ -std=c++0x usage_remove_space.cpp
int main(void)
{
	static vector<char> JoinSigns = { '_',' ','-','.','	','/' };
	string word = "GFG Style.59";
	string e_word_shrink;

	char arr[1024];
	//memset函数通常用来对一块已经分配地址的内存进行初始化，并且通常初始化为0或者字符'\0'
	//（实际上是一样的）
	memset(arr, 0, sizeof(arr));
	int i = 0;
	int pos = 0;
	for (char ch : word)
	{
		if(find(JoinSigns.begin(), JoinSigns.end(), ch) == JoinSigns.end())
		{
			arr[i] = ch;
			i++;
		}

		else if (ch == '.')
		{
			if (pos < word.size() - 1 && isdigit(word[pos+1]))
			{
				arr[i] = ch;
				i++;
			}
		}

		pos++;
	}
	e_word_shrink = arr;
	boost::replace_all(e_word_shrink, "·", "");
	cout << e_word_shrink << endl;
	return 0;
}
