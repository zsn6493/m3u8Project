#include <string>
#include <vector>
#include "formatTools.h"
#include <iostream>
using namespace std;

const int LEFTSTRIP = 0;
const int RIGHTSTRIP = 1;
const int BOTHSTRIP = 2;

string do_strip(string& str, int striptype, const string& chars)
{
	std::string::size_type strlen = str.size();
	std::string::size_type charslen = chars.size();
	std::string::size_type i, j;

	string sResult;

	//默认情况下，去除空白符
	if (0 == charslen)
	{
		i = 0;
		while (str[i] != '\0')
		{
			if (::isspace(str[i]))
			{
				for (int temp = i; str[temp] != '\0'; temp++)
				{
					str[temp] = str[temp + 1];
				}
				continue;
			}
			i++;
		}
	}
	else
	{
		//把删除序列转为c字符串
		const char*sep = chars.c_str();
		i = 0;
		if (striptype != RIGHTSTRIP)
		{
			//memchr函数：从sep指向的内存区域的前charslen个字节查找str[i]
			while (i < strlen&&memchr(sep, str[i], charslen))
			{
				i++;
			}
		}
		j = strlen;
		if (striptype != LEFTSTRIP)
		{
			j--;
			while (j >= i&&memchr(sep, str[j], charslen))
			{
				j--;
			}
			j++;
		}
	}

	return "";
}

//strip函数
string strip(string & str, const string & chars)
{
	return do_strip(str, BOTHSTRIP, chars);
}

void split(std::string& s, std::string& delim, std::vector< std::string >* ret)
{
	size_t last = 0;
	size_t index = s.find_first_of(delim, last);
	while (index != std::string::npos)
	{
		ret->push_back(s.substr(last, index - last));
		last = index + 1;
		index = s.find_first_of(delim, last);
	}
	if (index - last > 0)
	{
		ret->push_back(s.substr(last, index - last));
	}
}

void slipValue2(string value)
{
	vector<string> vec;
	string delim = "=";
	split(value, delim, &vec);

	int i = 0;
	string key;
	string URL;
	for each (auto it in vec)
	{
		if (i == 0)
		{
			key = it;
			cout << "attrKey:" << key << endl;
		}
		else
		{
			URL = it;
			cout << "attrValue:" << URL << endl;
		}

		i++;
	}
}

void slipValue(string value, m3U8Seg& m3u8seg)
{
	vector<string> vec;
	string delim = ",";
	split(value, delim, &vec);

	for each (auto it in vec)
	{
		//slipValue2(it);
		m3u8seg.arr.push_back(it);
	}
}