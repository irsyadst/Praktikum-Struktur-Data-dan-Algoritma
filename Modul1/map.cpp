#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

map<string, int> m;
unordered_map<string, int> u;

int main() {
	cout << "=====================Section A======================" << endl;
	cout << "====================================================" << endl;
	
	int age[5] = {17, 15, 18};
	
	cout << "Before insert:" << endl;
	cout << "Standard  Map M size:" << m.size() << endl;
	cout << "Unordered Map M size:" << u.size() << endl;
	
	// insert
	m["candi"] = age[0];
	m["budi"] = age[1];
	u["candi"] = age[0];
	u["budi"] = age[1];
	
	cout << "After insert:" << endl;
	cout << "Standard  Map M size:" << m.size() << endl;
	cout << "Unordered Map M size:" << u.size() << endl;
	
	cout << "=====================Section B======================" << endl;
	cout << "====================================================" << endl;
	
	// search
	cout << "'candi' value from m: " << m["candi"] << endl;
	cout << "'candi' value from u: "<< u["candi"] << endl;
	
	cout << "=====================Section C======================" << endl;
	cout << "====================================================" << endl;
	
	// check before insert
	if(!m["adi"]){
		m["adi"] = age[2];
	}
	if(!u["adi"]){
		u["adi"] = age[2];
	}
	if(!m["candi"]){
		m["candi"] = -100;
	}
	cout << "Standard  Map M size:" << m.size() << endl;
	cout << "Unordered Map M size:" << u.size() << endl;
	
	cout << "=====================Section D======================" << endl;
	cout << "====================================================" << endl;
	
	map<string, int>::iterator im;
	unordered_map<string, int>::iterator iu;
	
	cout << "Iterate over m" << endl;
	for(im=m.begin();im!=m.end();im++){
		cout << "key: " << im->first << ",  value: " << im->second << endl;
	}
	
	cout << "Iterate over u" << endl;
	for(iu=u.begin();iu!=u.end();iu++){
		cout << "key: " << iu->first << ",  value: " << iu->second << endl;
	}
	
	return 0;
}