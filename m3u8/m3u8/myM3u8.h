#include <iostream>
#include <string>
#include <list>
#include <vector>
#include<fstream>

using namespace std;

const int LEFTSTRIP = 0;
const int RIGHTSTRIP = 1;
const int BOTHSTRIP = 2;

typedef struct mapSimilar
{
public:
	string key;
	string value;
}mapSimilar;

typedef struct m3U8Seg
{
	list<string> arr;  //arrlist
	string tagName;
	string value;  //URL
}m3U8Seg;

class m3U8
{
public:
	string eXTM3U;
	string eXTXVERSION;
	string eXTXENDLIST;
	string eXTXTARGETDURATION;
	string eXTXMEDIASEQUENCE;
	list<m3U8Seg> totalList;

public:
	void parseM3U8(string filepath, m3U8& m3u8);
	void printf_M3U8();

private:
	void split(std::string& s, std::string& delim, std::vector< std::string >* ret);
	void slipTag(string value, m3U8Seg& m3u8seg);
	void slipArr(string value);
	string do_strip(string& str, int striptype, const std::string & chars = "");
	string strip(string & str, const std::string & chars = "");
};

struct attr
{
	string BANDWIDTH;
	string AVERAGEBANDWIDTH;
	string CODECS;
	string RESOLUTION;
	string FRAMERATE;
	string AUDIO;
	string VIDEO;
	string SUBTITLES;
	string CLOSEDCAPTIONS;
	string TYPE;
	string URI;
	string GROUPID;
	string LANGUAGE;
	string ASSOCLANGUAGE;
	string NAME;
	string DEFAULT;
	string AUTOSELECT;
	string FORCED;
	string INSTREAMID;
	string CHARACTERISTICS;
	string time;
};

#define BANDWIDTH "BANDWIDTH"
#define AVERAGEBANDWIDTH "AVERAGEBANDWIDTH"
#define CODECS "CODECS"
#define RESOLUTION "RESOLUTION"
#define FRAMERATE "FRAMERATE"
#define AUDIO "AUDIO"
#define VIDEO "VIDEO"
#define SUBTITLES "SUBTITLES"
#define CLOSEDCAPTIONS "CLOSEDCAPTIONS"
#define TYPE "TYPE"
#define URI "URI"
#define GROUPID "GROUPID"
#define LANGUAGE "LANGUAGE"
#define ASSOCLANGUAGE "ASSOCLANGUAGE"
#define NAME "NAME"
#define DEFAULT "DEFAULT"
#define AUTOSELECT "AUTOSELECT"
#define FORCED "FORCED"
#define INSTREAMID "INSTREAMID"
#define CHARACTERISTICS "CHARACTERISTICS"
#define TIME "TIME"

#define EXTM3U "EXTM3U"
#define EXTXVERSION "EXT-X-VERSION"
#define EXTXENDLIST "EXT-X-ENDLIST"
#define EXTXTARGETDURATION "EXT-X-TARGETDURATION"
#define EXTXMEDIASEQUENCE "EXT-X-MEDIA-SEQUENCE"