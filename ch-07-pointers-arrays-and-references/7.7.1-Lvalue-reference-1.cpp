#include <iostream>
#include <utility>
#include <vector>
using namespace std;

template<typename K, typename V>
class MyMap {
	public:
		V& operator[](const K& k) {
			for(auto& x : elem)
				if(k == x.first)
					return x.second;

			elem.push_back({k, V{}});
			return elem.back().second;
		} 

        pair<K, V>* begin() { return &elem[0]; }
        pair<K, V>* end() { return &elem[0]+elem.size(); }

    private:
        vector<pair<K, V>>elem;
};

int main() {
    MyMap<string, int> buf;

    for(string s; cin>>s;) ++buf[s];

    for(const auto& x : buf)
        cout << x.first << ": " << x.second << '\n';
}
