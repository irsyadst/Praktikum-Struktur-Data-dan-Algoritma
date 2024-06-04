#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<string, int> m;

    m["Igo"] = 25;
    m["Nur"] = 30;
    m["Cahyo"] = 35;

    cout << "Umur Igo: " << m["Igo"] << endl;
    cout << "Umur Nur: " << m["Nur"] << endl;

    if (m.find("Cahyo") != m.end())
    {
        cout << "Umur Cahyo adalah " << m["Cahyo"] << endl;
    }

    for (auto it = m.begin(); it != m.end(); ++it)
    {
        cout << it->first << ": " << it->second << endl;
    }

    return 0;
}
