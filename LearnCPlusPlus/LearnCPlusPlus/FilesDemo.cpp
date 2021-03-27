#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

#define TEXT_FIE_PATH "data/data.txt"

#define BIN_FIE_PATH "data/data.bin"

enum class Options {Add=1,View=2};

typedef struct {
	string name;
	double salary;
	string position;
} Employee;


// For text file
void addToTextFile(string text, string filePath) {

	try {
		ofstream myfile;
		myfile.open(filePath, ios::out | ios::app);
		myfile << text + "\n";
		myfile.close();
		cout << "--> Record is added to file\n";
    } catch (exception& e) {
		cout << "--> Standard exception: " << e.what() << endl;
	}
}

vector<string> readFromTextFile(string filePath) {
	vector<string> fileLines;
	string line;
	try {
		ifstream myfile(filePath);
		if (myfile.is_open()) {

			while (getline(myfile, line)) {
				fileLines.push_back(line);
			}
			myfile.close();
		}
		else {
			cout << "--> Unable to open file";
		}
	}catch (exception& e) {
		cout << "--> Standard exception: " << e.what() << endl;
	}

	return fileLines;
}

void addToText() {

	string text;
	int options;
	while (true) {
		cout << "-->\n1- Add new record\n2-View records\nAny other key to Exit\n";
		cin >> options;
		if (options == (int)Options::Add) {
			cout << "Enter text:";
			std::cin >> std::ws;
			getline(cin, text);
			addToTextFile(text, TEXT_FIE_PATH);
		}
		else if (options == (int)Options::View) {
			cout << "\n============= FileContent =============\n";
			vector<string> fileLines = readFromTextFile(TEXT_FIE_PATH);
			for (auto line = fileLines.begin(); line != fileLines.end(); line++) {
				cout << *line << endl;
			}
		}
		else {
			break;
		}
	}
}


// For binrary file

void addToBin(Employee employee, string filePath) {
	try {
		ofstream myfile;
		myfile.open(filePath, ios::out | ios::app | ios::binary);
		myfile.write((char*)&employee,sizeof(employee));
		myfile.close();
		cout << "--> Record is added to file\n";
	}
	catch (exception& e) {
		cout << "--> Standard exception: " << e.what() << endl;
	}
}

vector<Employee*>  readBinFile(string filePath) {
	vector<Employee*> fileEmployee;
	string line;
	try {
		ifstream myfile(filePath,ios::in| ios::binary | ios::ate);
		if (myfile.is_open()) {
			streampos size = myfile.tellg();
			char* memblock = new char[size];
			myfile.seekg(0, ios::beg);
			myfile.read(memblock, size); // all file data on buffer
			myfile.close();

			long long byteIndex = 0;
			while (byteIndex < size) {
				Employee* employee = (Employee*)(memblock + byteIndex);
				fileEmployee.push_back(employee);
				byteIndex += sizeof(Employee);
			}
			 
		}
		else {
			cout << "--> Unable to open file";
		}
	}
	catch (exception& e) {
		cout << "--> Standard exception: " << e.what() << endl;
	}

	return fileEmployee;
}

void addToBin() {

	string text;
	int options;
	while (true) {
		cout << "-->\n1- Add new record\n2-View records\nAny other key to Exit\n";
		cin >> options;
		if (options == (int)Options::Add) {
			Employee employee;
			cout << "employee name: ";
			std::cin >> std::ws;
			getline(cin, employee.name);

			cout << "employee position: ";
			getline(cin, employee.position);

			cout << "employee salary: ";
			cin>> employee.salary;

			addToBin(employee, BIN_FIE_PATH);
		}
		else if (options == (int)Options::View) {
			cout << "\n============= FileContent =============\n";
			vector<Employee*> fileLines = readBinFile(BIN_FIE_PATH);
			for (auto line = fileLines.begin(); line != fileLines.end(); line++) {
				Employee* employee = *line;
				cout << "employee->name: " << employee->name << "\n";
				cout << "employee->position: " << employee->position << "\n";
				cout << "employee->salary: " << employee->salary << "\n";
				cout << "\n-----------\n";
			}
		}
		else {
			break;
		}
	}
}
int main20() {

	//addToText();
	addToBin();
 
	system("pause");

	return 0;
}