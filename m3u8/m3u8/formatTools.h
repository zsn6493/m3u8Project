#pragma once

#include <string>
#include <map>
#include <list>
using namespace std;

/*
string BasicTags[] =
{
"EXTM3U",
"EXT-X-VERSION",
};

string MediaSegmentTags[] =
{
"EXTINF",
"EXT-X-BYTERANGE",
"EXT-X-DISCONTINUITY",
"EXT-X-KEY",
"EXT-X-MAP",
"EXT-X-PROGRAM-DATE-TIME",
"EXT-X-DATERANGE"
};

string MediaPlaylistTags[] =
{
"EXT-X-TARGETDURATION",
"EXT-X-MEDIA-SEQUENCE",
"EXT-X-DISCONTINUITY-SEQUENCE",
"EXT-X-ENDLIST",
"EXT-X-PLAYLIST-TYPE",
"EXT-X-I-FRAMES-ONLY",
};

string MasterPlaylistTags[] =
{
"EXT-X-MEDIA",
"EXT-X-STREAM-INF",
"EXT-X-I-FRAME-STREAM-INF",
"EXT-X-SESSION-DATA",
"EXT-X-SESSION-KEY",
};

string MediaorMasterPlaylistTags[] =
{
"EXT-X-INDEPENDENT-SEGMENTS",
"EXT-X-START"
};

string EXTXMEDIA[] = { "TYPE", "URI", "GROUP-ID", "LANGUAGE", "ASSOC-LANGUAGE", "NAME", "DEFAULT", "AUTOSELECT", "FORCED", "INSTREAM-ID", "CHARACTERISTICS" };
string EXTXSTREAMINF[] = { "BANDWIDTH", "AVERAGE-BANDWIDTH", "CODECS", "RESOLUTION", "FRAME-RATE", "AUDIO", "VIDEO", "SUBTITLES", "CLOSED-CAPTIONS" };
string EXTXIFRAMESTREAMIN[] = { "URI", "BANDWIDTH", " AVERAGE-BANDWIDTH", "CODECS", "RESOLUTION", "FRAME-RATE", "AUDIO", "VIDEO", "SUBTITLES", "CLOSED-CAPTIONS" };
string EXTXKEY[] = { "METHOD", "URI", "IV", "KEYFORMAT", "KEYFORMATVERSIONS" };
string EXTXIFRAMESTREAMINF[] = { "BANDWIDTH", "URI" };
string EXTXSESSIONDATA[] = { "DATA-ID", " VALUE", "URI", "LANGUAGE" };
string EXTXSTART = { "TIME-OFFSET", "PRECISE" };
string EXTXMAP = { "URI", "BYTERANGE" };*/

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
	void printf_M3U8();
};

std::string do_strip(std::string &str, int striptype, const std::string&chars);

std::string strip(std::string & str, const std::string & chars = "");

//slipValueº¯Êý
void slipValue(string value, m3U8Seg& m3u8seg);