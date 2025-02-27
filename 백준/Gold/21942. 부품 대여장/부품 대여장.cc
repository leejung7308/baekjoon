#include<bits/stdc++.h>
#include<unordered_map>
#define INF 1000000000
#define FAST_IO ios::sync_with_stdio; cin.tie(0); cout.tie(0)
using namespace std;
int days[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
int MonthtoDay(int month) {
	if (month == 1) return 0;
	int day = 0;
	for (int i = 0; i < month - 1; i++) {
		day += days[i];
	}
	return day;
}
int main() {
	FAST_IO;
	int n, f;
	string duration, date, time, thing, name;
	unordered_map<string, unordered_map<string, int>> data;
	map<string, long long> penalty;
	time_t bt, rt;
	struct tm burrowtime, returntime;
	cin >> n >> duration >> f;
	int dday = stoi(duration.substr(0, 3));
	int dhour = stoi(duration.substr(4, 2));
	int dmin = stoi(duration.substr(7));
	int durationmin = dday * 24 * 60 + dhour * 60 + dmin;
	while (n--) {
		cin >> date >> time >> thing >> name;
		int month = stoi(date.substr(5, 2));
		int day = stoi(date.substr(8)) + MonthtoDay(month);
		int hour = stoi(time.substr(0, 2));
		int minute = stoi(time.substr(3));
		int num = day * 1440 + hour * 60 + minute;
		if (data.find(name) == data.end()) data[name][thing] = num;
		else if (data[name].find(thing) == data[name].end()) data[name][thing] = num;
		else if (data[name][thing] == 0) data[name][thing] = num;
		else {
			int diff = num - data[name][thing];
			data[name][thing] = 0;
			if (diff > durationmin) penalty[name] += (diff - durationmin) * f;
		}
	}
	for (auto& p : penalty) {
		cout << p.first << ' ' << p.second << '\n';
	}
	if (penalty.size() == 0) cout << -1;
}