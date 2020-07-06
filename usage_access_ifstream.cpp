#include <unistd.h>
#include <iostream>
#include <string.h>
#include <fstream>
#include <boost/algorithm/string/trim.hpp>
#include <boost/algorithm/string.hpp>
#include<unordered_map>

using namespace std;


int main(void)
{
	unordered_map<string, string> params;
	string strConfPath = "config.ini";
	//或者：access(strConfPath.c_str(), F_OK)
	if(-1 == access(strConfPath.c_str(), 0))
	{
		cout << "file : " << strConfPath << " does not exist!" << endl;
	}

	else
	{
		cout << "file : " << strConfPath << " exists!" << endl;
	}

	/*
 	#include <fstream>
	ofstream //文件写操作 内存写入存储设备 
	ifstream //文件读操作，存储设备读区到内存中
	fstream  //读写操作，对打开的文件可进行读写操作
	ios_base::in	为输入(读)而打开文件
	fin_streamconfigfile.is_open() 成功返回True
  	*/

	ifstream fin_streamconfigfile; 
	fin_streamconfigfile.open(strConfPath.c_str(), ios_base::in);

	if(!fin_streamconfigfile.is_open())
	{
        	cout <<  "Config file " << strConfPath.c_str() <<  " open failed!!!!" << endl;
	}

	char ConfigLine[1024];
	string str_ConfigKey;
	string str_ConfigValue;
	vector<string> vs_Config;

	//读取方式: 逐行读取, 将行读入字符数组:ConfigLine, 行之间用回车换行区分
	//读取的每一行长度不能超过1024，如果超过，程序会陷入死循环，内存会被慢慢耗尽
	//https://blog.csdn.net/yafeng_jiang/article/details/7106109
	while(fin_streamconfigfile.getline(ConfigLine, 1024))
	{
		//ConfigLine中保存的是配置文件中每一行的数据
		//判断字符*ConfigLine是否为字母或数字
		//isalpha()用来判断一个字符是否为字母，如果是字符则返回非零，否则返回零
		//isalnum()用来判断一个字符是否为数字或者字母，也就是说判断一个字符是否属于a~z||A~Z||0~9
		//islower()用来判断一个字符是否为小写字母，也就是是否属于a~z
		//isupper()和islower相反，用来判断一个字符是否为大写字母
		if(isalnum(*ConfigLine))
		{
			vs_Config.clear();
			/*boost::split()函数用于切割string字符串，将切割之后的字符串放到一个std::vector<std::string> 之中
			以boost::split(type, select_list, boost::is_any_of(","), boost::token_compress_on);
			(1)、type类型是std::vector<std::string>，用于存放切割之后的字符串
			(2)、select_list：传入的字符串，可以为空。
			(3)、boost::is_any_of(",")：设定切割符为,(逗号)
			(4)、boost::token_compress_on：将连续多个分隔符当一个，默认没有打开，当用的时候一般是要打开的。
			*/
			boost::split(vs_Config, ConfigLine, boost::is_any_of("="));
			//key = value
			if(vs_Config.size() != 2)
			{
				continue;
			}

			//去除字符串中首尾的空格
			//为了使自己的程序有很好的移植性，c++程序员应该尽量使用size_t和size_type而不是int, unsigned
			for(size_t i=0; i<vs_Config.size(); i++)
			{
				boost::trim(vs_Config.at(i));
			}

			str_ConfigKey = vs_Config.at(0);
			//数值型
			if (str_ConfigKey == "update_delta" or 
				str_ConfigKey == "parse_ratio" or 
				str_ConfigKey == "use_word" or 
				str_ConfigKey == "update_all_delta" or 
				str_ConfigKey == "open_intent_check")
			{
				str_ConfigValue = vs_Config.at(1);
			}

			else
			{
				str_ConfigValue = "../data/" + vs_Config.at(1);
			}
			//插入数据有三种方式，请参考：usage_unordered_map.cpp
			params.insert(pair<string,string>(str_ConfigKey, str_ConfigValue));

			cout << ConfigLine << "\t" << str_ConfigKey << ":" << str_ConfigValue << endl;
		}
	}

	fin_streamconfigfile.close();

	return 0;
}
