#include <iostream>
#include <sys/time.h>
#include <string>
#include <regex.h>
#include <sstream>
#include <boost/algorithm/string/trim.hpp>
using namespace std;


//https://adairjun.github.io/2015/11/29/regex/
class RegRecognizer
{
public:
        RegRecognizer(const char* pattern)
        {
                regcomp(&m_reg, pattern, REG_EXTENDED);
        };

        ~RegRecognizer()
        {
                regfree(&m_reg);
        };

        void RegSplit(string& iquery, string splitor)
        {
                regmatch_t pmatch;
                int start = 0;
                stringstream ss;
                const char* buf = iquery.c_str();
                int status = regexec(&m_reg, buf, 1, &pmatch, REG_NOTBOL);
                while (status == 0)
                {
                        if (pmatch.rm_so > 0)
                        {
                                string temp = iquery.substr(start, pmatch.rm_so);
                                if (temp != " ")
                                {
                                        boost::trim(temp);
                                        ss << temp << splitor;
                                }
                        }
                        string temp2 = iquery.substr(start + pmatch.rm_so, pmatch.rm_eo - pmatch.rm_so);
                        if (temp2 != " ")
                        {
                                boost::trim(temp2);
                                ss << temp2 << splitor;
                        }
                        string query1 = ss.str();
                        start += pmatch.rm_eo;
                        status = regexec(&m_reg, buf + start, 1, &pmatch, REG_NOTBOL);
                }
                if (start < iquery.size())
                {
                        string temp3 = iquery.substr(start, iquery.size());
                        ss << temp3;
                }
                iquery = ss.str();
        }
private:
        regex_t m_reg;
};


int main(void) {
    cout<<"this is c++ test" << endl;
    const char pattern[200] = "([0-9]{1}\\.[0-9]+)";
    RegRecognizer* m_pReg = new RegRecognizer(pattern);
    string iquery = "丰田埃尔法25.49万";
    cout << iquery << endl;
    m_pReg->RegSplit(iquery, " ");
    cout << iquery << endl;
    
    return 0;
}
