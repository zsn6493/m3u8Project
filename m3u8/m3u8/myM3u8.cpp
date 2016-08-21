#include "myM3u8.h"

void m3U8::printf_M3U8()
{
	for each (auto it in totalList)
	{
		cout << it.tagName << endl;
		for each (auto it2 in it.arr)
		{
			cout << it2 << endl;
		}
		cout << it.value << endl;
	}
}

string m3U8::do_strip(string& str, int striptype, const string& chars)
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
string m3U8::strip(string & str, const string & chars)
{
	return do_strip(str, BOTHSTRIP, chars);
}

void m3U8::split(std::string& s, std::string& delim, std::vector< std::string >* ret)
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

void m3U8::slipArr(string value)
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

void m3U8::slipTag(string value, m3U8Seg& m3u8seg)
{
	vector<string> vec;
	string delim = ",";
	split(value, delim, &vec);

	for each (auto it in vec)
	{
		m3u8seg.arr.push_back(it);
	}
}

void m3U8::parseM3U8(string filepath, m3U8& m3u8)
{
	char *line = new char();

	ifstream file;
	file.open(filepath, ios::out | ios::binary);
	if (file.is_open())
	{
		cout << "file is open\n";
	}

	char str[1024];
	string str2;
	int i = 0;

	while (!file.eof())
	{
		m3U8Seg m3u8seg;
		file.getline(str, 1024, '#');
		str2 = (string)str;
		if (str2 == "")
		{
			continue;
		}

		int index = str2.find(":");
		if (index == -1)
		{
			m3u8seg.tagName = str2;
			m3u8seg.value = "";
			m3u8.totalList.push_back(m3u8seg);
			i++;
			continue;
		}

		m3u8seg.tagName = str2.substr(0, index);
		string vl = str2.substr(index + 1);
		string value = strip(vl);

		slipTag(vl, m3u8seg);

		m3u8.totalList.push_back(m3u8seg);
		i++;
	}

	file.close();
}