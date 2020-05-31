/*
	Author: Donovan Torgerson
	Email: Donovan@Torgersonlabs.com

	Instructions can be found in hw1.txt

*/

#include <iostream>
#include <stdlib.h>
#include <sstream>

using namespace std;

int main()
{
	const string wGet = "wget -q -O- ", unlink = "unlink ";
	string page[] = {"http://www.cnn.com/2013/09/01/world/meast/syria-civil-war/index.html?hpt=hp_t1", "http://www.foxnews.com/politics/2013/09/01/kerry-confident-congress-will-back-syria-attrack-but-lawmakers-express/", "http://www.foxnews.com/politics/2013/08/31/president-obama-statement-on-syria/", "http://www.cnn.com/2013/09/01/justice/oklahoma-city-thunder-deandre-liggins/index.html?hpt=hp_t2", "http://www.ktvb.com/news/national/221949511.html", "http://worldnews.nbcnews.com/_news/2013/09/01/20280931-arab-states-call-for-international-action-against-syrian-regime?lite", "http://www.bbc.co.uk/news/uk-politics-23918915", "http://www.wdaz.com/event/article/id/19329/", "http://news.yahoo.com/lawmakers-begin-grapple-syria-215018877--politics.html", "http://news.yahoo.com/us-weighing-limited-narrow-action-against-syria-035535999.html"}, findMessage = "find | grep -oh \"Syria\" ";
	for (int x = 0; x < 10; x++)
	{
		cout << page[x] << endl;
		string systemMessage = wGet;
		string systemUnlinkMessage = unlink;
		string systemFindMessage = findMessage;
		systemMessage += page[x];
		systemMessage += " -O ";
		stringstream s;
		s << x;
		systemMessage += s.str();
		systemMessage += ".html";
		system(systemMessage.c_str());
		stringstream t;
		t << x;
		systemFindMessage += t.str();
		systemFindMessage += ".html";
		system(systemFindMessage.c_str());
		stringstream u;
		u << x;
		systemUnlinkMessage += u.str();
		systemUnlinkMessage += ".html";
		system(systemUnlinkMessage.c_str());
		systemFindMessage = "";
	}
	return 0;
}