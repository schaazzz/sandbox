#include <iostream>
#include <iterator>
#include <vector>
#include <string>

using namespace std;

int main(void) {
    vector<string> ss;

    ss.push_back("10");
    ss.push_back("20");
    ss.push_back("30");

    cout << "Loop:" << endl;

    int ii;
    for(ii = 0; ii < ss.size(); ii++) {
        cout << ss[ii] << endl;
    }

    cout << "Iterate:" << endl;

    vector<string> ::const_iterator cii;
    for(cii=ss.begin(); cii!=ss.end(); cii++) {
        cout << *cii << endl;
    }

    cout << "Copy:" << endl;
    copy(ss.begin(), ss.end(), ostream_iterator<string>(cout, "\n"));

    int x(0);
    int y(10);

    cout << x << endl;
    cout << y << endl;

    // string a = ss.pop_back();
    string b = ss.back();
    //
    // cout << a << std::endl;
    cout << b << std::endl;
    // cout << ss.size() << std::endl;
}
