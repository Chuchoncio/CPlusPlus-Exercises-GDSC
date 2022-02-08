#include <iostream>
#include <cstring>
using namespace std;

int findVowel(string username, int size_cad) {
    int i;

    for(i = 0; i < size_cad; i++) {
        if(username.find('a', 0) == string::npos || username.find('e', 0) == string::npos || username.find('i', 0) == string::npos
           || username.find('o', 0) == string::npos || username.find('u', 0) == string::npos)
           {
                return 1;
           }
    }
    return 0;
}

int main() {
	int t;

	cin >> t;
	fflush(stdin);

	while(t) {

        string username;
	    getline(cin, username);

	    if( username.substr(0, 1) == "k" || username.substr(0, 1) == "n")
	        {
	            if(findVowel(username, username.length()) == 1)
	                cout << "Yes" << endl;
	        }
	    else if(username.substr(0, 1) == "a" || username.substr(0, 1) == "e" ||
	            username.substr(0, 1) == "o")
                {
	                cout << "Yes" << endl;
	            }
	    else
	            cout << "No" << endl;

        fflush(stdin);
	    t--;
	}

	return 0;
}
