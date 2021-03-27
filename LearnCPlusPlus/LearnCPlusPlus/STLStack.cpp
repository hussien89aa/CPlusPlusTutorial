#include <iostream>
#include <vector>
#include <stack>
#include <set>

using namespace std;

struct City{
	string name;
	vector<struct City*> connections;
	City(string cityName) {
		name = cityName;
	}
	void connect(struct City* city) {
		connections.push_back(city);
	}

};

City* buildMap() {

	City* city1 = new City("City 1");
	City* city2 = new City("City 2");
	City* city3 = new City("City 3");
	City* city4 = new City("City 4");

	city1->connect(city2);
	city1->connect(city3);
	city2->connect(city3);
	city3->connect(city4);
	city4->connect(city1);

	return city1;
}
int main() {

	City* startCity = buildMap();

	stack<City*> st;
	set<City*> visited;

	st.push(startCity);

	while (!st.empty()) {

		City* lastCity = st.top();
		visited.insert(lastCity);
		for (auto conn = lastCity->connections.begin(); conn != lastCity->connections.end(); conn++) {
			City* connectedCity = (City*)*conn;
			if (visited.find(connectedCity) == visited.end()) {
				st.push(connectedCity);
				break;
			}

		}

		if (st.top() == lastCity) {
			cout << lastCity->name << endl;
			st.pop();
			delete lastCity;
		}
	}

	system("pause");

	return 0;
}