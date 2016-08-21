#include <string>
#include <iostream>
#include "myM3u8.h"
using namespace std;

int main()
{
	m3U8 m3u8;
	string m3u8filepath = "C:\\Users\\Administrator\\Desktop\\m3u8file\\MasterPlaylistwithAlternativevideo.m3u8";
	string m3u8filepath1 = "C:\\Users\\Administrator\\Desktop\\m3u8file\\LiveMediaPlaylistusingHTTPS.m3u8";
	string m3u8filepath2 = "C:\\Users\\Administrator\\Desktop\\m3u8file\\Master Playlist with I-Frames.m3u8";
	m3u8.parseM3U8(m3u8filepath2, m3u8);
	m3u8.printf_M3U8();

	system("pause");
	return 0;
}