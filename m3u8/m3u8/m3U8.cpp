#include <string>
#include <iostream>
#include <vector>
#include <list>
using namespace std;
//写了一个简单的m3u8解析的方法，把m3u8读取到string，然后输出一个vector：

/*
string getline()
{
size_t pos = string::npos;

if ((pos = value.find("\n")) != string::npos){
return value.substr(0, pos);
}

return value;
}

m3u8Tools& remove(int size)
{
if (size >= (int)value.length())
{
value = "";
return *this;
}

value = value.substr(size);
return *this;
}
const char* c_str(){
return value.c_str();
}
};

int ParseM3u8Data(string m3u8, vector<M3u8TS>& ts_objects)
{
int ret = -1;

m3u8Tools data(m3u8);

// http://tools.ietf.org/html/draft-pantos-http-live-streaming-08#section-3.3.1
// An Extended M3U file is distinguished from a basic M3U file by its
// first line, which MUST be the tag #EXTM3U.
if (!data.startswith("#EXTM3U")){
ret = -1;
//Error("invalid hls, #EXTM3U not found. ret=%d", ret);
return ret;
}

m3u8Tools value;
int target_duration = 0;

M3u8TS ts_object;
while (data.length() > 0)
{
m3u8Tools line;
data.remove(line.set_str(data.strip().getline()).strip().length()).strip();

// http://tools.ietf.org/html/draft-pantos-http-live-streaming-08#section-3.4.2
// #EXT-X-TARGETDURATION:<s>
// where s is an integer indicating the target duration in seconds.
if (line.startswith("#EXT-X-TARGETDURATION:", &value)){
target_duration = atoi(value.c_str());
ts_object.duration = target_duration;
continue;
}

// http://tools.ietf.org/html/draft-pantos-http-live-streaming-08#section-3.3.2
// #EXTINF:<duration>,<title>
// "duration" is an integer or floating-point number in decimal
// positional notation that specifies the duration of the media segment
// in seconds.  Durations that are reported as integers SHOULD be
// rounded to the nearest integer.  Durations MUST be integers if the
// protocol version of the Playlist file is less than 3.  The remainder
// of the line following the comma is an optional human-readable
// informative title of the media segment.
// ignore others util EXTINF
if (line.startswith("#EXTINF:", &value))
{
ts_object.duration = atof(value.c_str());
continue;
}

if (!line.startswith("#"))
{
//ts_object.ts_url = url.Resolve(line.c_str());
ts_object.ts_url = line.c_str();
ts_objects.push_back(ts_object);
continue;
}
}

return ret;
}

*/