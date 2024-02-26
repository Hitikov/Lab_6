#include <iostream>
#include <string>

using namespace std;

void find_overlaps(string s1, string s2) 
{
	int overlaps = 0;
	string spaces;

	for (int x = 0; x < s1.size(); ++x) 
	{
		for (int y = 0; y < s2.size(); ++y) 
		{
			if (s1[x] == s2[y])
			{
				++overlaps;
				cout << "Кроссворд " << overlaps << ":" << endl;
				spaces.insert(0, x, ' ');
				for (int i = 0; i < y; ++i)
				{
					cout << spaces << s2[i] << endl;
				}
				cout << s1 << endl;
				for (int i = y + 1; i < s2.size(); ++i)
				{
					cout << spaces << s2[i] << endl;
				}
				cout << endl;
				spaces.clear();
			}
		}
	}
	if (overlaps == 0)
	{
		cout << "Ошибка входных данных, невозможно построить кроссворд.";
	}
}

int main() {
	string in_string, str_1, str_2;
	system("chcp 1251");
	setlocale(LC_ALL, "ru");


	cout << "Введите два слова, разделенных пробелом:" << endl;
	getline(cin, in_string);

	int i = 0;
	while ((in_string[i] != '\0') && (in_string[i] != 32))
	{
		++i;
	}

	str_1.insert(0, in_string, 0, i);
	str_2.insert(0, in_string, i + 1, in_string.size() - 1);

	find_overlaps(str_1, str_2);

	return 0;
}