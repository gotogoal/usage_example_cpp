#include<unordered_map>
#include <iostream>
#include <fstream>

#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/trim.hpp>

using namespace std;


//g++ -std=c++0x usage_unordered_map_vector.cpp 
int main(void) {
	string intent_Path = "intent_category.txt";
	ifstream fin_streamIntent;
	fin_streamIntent.open(intent_Path.c_str(), ios_base::in);
	char c_Line[200];
	vector<string> vs_LineItems;
	unordered_map< string, vector <pair<string, string> > > dict;
	while (fin_streamIntent.getline(c_Line, 200))
	{
		if ('#' == *c_Line)
		{
			continue;
		}
		string s_Line(c_Line);
		boost::algorithm::trim(s_Line);
		boost::split(vs_LineItems, s_Line, boost::is_any_of("\t"));
		string s_key = vs_LineItems[1];

		if(dict.find(s_key) != dict.end())
		{
			dict[s_key].push_back(std::make_pair(vs_LineItems[2], vs_LineItems[3]));
		}
		else
		{
			dict[s_key] = {std::make_pair(vs_LineItems[2], vs_LineItems[3])};
		}
	}

	fin_streamIntent.close();

	unordered_map<string, vector <pair<string, string>>>::iterator iter;
	for(iter=dict.begin(); iter!=dict.end(); iter++)
	{
		for(int i=0;i < iter->second.size(); i++)
		{
			cout << iter->first << "\t" << iter->second[i].first << "\t" << iter->second[i].second << endl; 
		}
	}
	return 0;
}
