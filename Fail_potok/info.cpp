#include <iostream> 
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

void Valid(ifstream& o, int counter, string content) {
	int z, x;
	for (int i = 0; i < counter; i++) {
		z = 0, x = 0;
		for (int j = 0; j < content.length(); j++) {
			if (content[j] == '<') {
				z += 1;
				x += 1;
			}
			else if (content[j] == '>' && z == 1) {
				z = 0;
				x -= 1;
			}
		}
		if (x == 0) {
			cout << "\nЭтот стринг правильный: " << endl;
			cout << content << "\n\n";
		}
		else if (x != 0) {
			cout << "\nЭтот стрин не правильный : " << endl;
			cout << content << "\n";
		}
		break;
	}
}

int main() {
	setlocale(LC_ALL, "RUS");

	string path;
	cout << "Введите путь к файлу: ";
	getline(cin, path);

	ifstream open(path);
	string cont;
	int count = 0;
	if (open.is_open()) {
		do {
			getline(open, cont);
			count++;
			Valid(open, count, cont);
		} while (!open.eof());
	}
	else {
		cout << "\nФайл не найден\n";
	}
	open.close();
}