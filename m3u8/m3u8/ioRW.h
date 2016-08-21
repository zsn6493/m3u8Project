#pragma once
#include "formatTools.h"
#include<iostream>
#include<fstream>
#include<map>
using namespace std;

typedef struct mapSimilar
{
public:
	string key;
	string value;
}mapSimilar;

void loadFile(string filepath, m3U8& m3u8);