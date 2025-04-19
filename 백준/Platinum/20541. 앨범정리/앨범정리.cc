#include<bits/stdc++.h>
#include<unordered_map>
#define INF 1000000000
#define FAST_IO ios::sync_with_stdio; cin.tie(0); cout.tie(0)
#define DIR const vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}
using namespace std;
const pair<int, int> operator+(const pair<int, int>& a, const pair<int, int>& b) {
	return { a.first + b.first,a.second + b.second };
}
struct album {
	album(album* p, string n) {
		parent = p;
		name = n;
	}
	album* parent;
	string name;
	map<string, bool> photos;
	map<string, album*> albums;
};
pair<int, int> getcount(album& a) {
	pair<int, int> ret = { 1, a.photos.size() };
	for (const auto& p : a.albums) ret = ret + getcount(*p.second);
	return ret;
}
int main() {
	FAST_IO;
	int n;
	album* root = new album(NULL, "album");
	album* cur = root;
	cin >> n;
	while (n--) {
		string command, option;
		cin >> command >> option;
		if (command == "mkalb") {
			if (cur->albums.find(option) != cur->albums.end()) cout << "duplicated album name\n";
			else cur->albums[option] = new album(cur, option);
		}
		else if (command == "rmalb") {
			if (cur->albums.size() == 0) cout << "0 0\n";
			else if (option == "-1") {
				pair<int, int> out = getcount(*cur->albums.begin()->second);
				cur->albums.erase(cur->albums.begin());
				cout << out.first << ' ' << out.second << '\n';
			}
			else if (option == "0") {
				pair<int, int> out = { 0,0 };
				for (const auto& p : cur->albums) out = out + getcount(*p.second);
				cur->albums.clear();
				cout << out.first << ' ' << out.second << '\n';
			}
			else if (option == "1") {
				auto it = --cur->albums.end();
				pair<int, int> out = getcount(*it->second);
				cur->albums.erase(it);
				cout << out.first << ' ' << out.second << '\n';
			}
			else {
				if (cur->albums.find(option) == cur->albums.end()) cout << "0 0\n";
				else {
					pair<int, int> out = getcount(*cur->albums[option]);
					cur->albums.erase(option);
					cout << out.first << ' ' << out.second << '\n';
				}
			}
		}
		else if (command == "insert") {
			if (cur->photos.find(option) != cur->photos.end()) cout << "duplicated photo name\n";
			else cur->photos[option] = true;
		}
		else if (command == "delete") {
			if (cur->photos.size() == 0) cout << "0\n";
			else if (option == "-1") {
				cur->photos.erase(cur->photos.begin());
				cout << "1\n";
			}
			else if (option == "0") {
				cout << cur->photos.size() << '\n';
				cur->photos.clear();
			}
			else if (option == "1") {
				auto it = --cur->photos.end();
				cur->photos.erase(it);
				cout << "1\n";
			}
			else {
				if (cur->photos.find(option) == cur->photos.end()) cout << "0\n";
				else {
					cur->photos.erase(option);
					cout << "1\n";
				}
			}
		}
		else if (command == "ca") {
			if (option == ".." && cur != root) cur = cur->parent;
			else if (option == "/") cur = root;
			else if (cur->albums.find(option) != cur->albums.end()) cur = cur->albums[option];
			cout << cur->name << '\n';
		}
	}
}