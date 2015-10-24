#include <ctime>
#include <cinttypes>
#include <cstdio>
#include <string>

using std::string;

#ifndef __STDC_FORMAT_MACROS
#define __STDC_FORMAT_MACROS
#endif

class timeStamp
{
public:
	static const int microsecondPerSecond = 100000;
	timeStamp();
	string toString();
	string toFormat(bool showMicrosecond);
private:
	int64_t microsecondSinceEpoch;
};

timeStamp::timeStamp()
{
	time_t now;
	time(&now);
	microsecondSinceEpoch = static_cast<int64_t>(now*microsecondPerSecond);

}
string timeStamp::toString()
{
	char buf[32] = { 0 };
	sprintf_s(buf, "%"PRId64, microsecondSinceEpoch);
	return buf;
}
string timeStamp::toFormat(bool showMicrosecond)
{
	char buf[100] = { 0 };
	time_t seconds = static_cast<time_t>(microsecondSinceEpoch / microsecondPerSecond);
	struct tm tm_time;
	gmtime_s(&tm_time, &seconds);
	if (showMicrosecond)
	{
		sprintf_s(buf, "%4d %02d %02d %02d:%02d:%02d",
			tm_time.tm_year + 1900, tm_time.tm_mon + 1, tm_time.tm_mday,
			tm_time.tm_hour, tm_time.tm_min, tm_time.tm_sec);	
	}
	else
	{
		sprintf_s(buf, "%4d %02d %02d %02d:%02d",
			tm_time.tm_year + 1900, tm_time.tm_mon + 1, tm_time.tm_mday,
			tm_time.tm_hour, tm_time.tm_min);
	}
	return buf;
}
int tmain()
{
	timeStamp timeNow;
	printf("%s\n", timeNow.toString().c_str());
	printf("%s\n", timeNow.toFormat(true).c_str());
	printf("%s\n", timeNow.toFormat(false).c_str());

	return 0;
}