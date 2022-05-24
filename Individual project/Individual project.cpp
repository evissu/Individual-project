#include <Windows.h>
#include <iostream>
using namespace std;
int years;
bool vysokostnyi(int years) {       // делаю даты надо учитывать вискокостный года
	bool r = false;						
	if (years % 4 == 0) {
		r = true;
	}
	if (years % 400 == 0) {
		r = true;
	}
	if (years % 100 == 0) {
		r = false;
	}
	return r;
}
int func(int day, int month,int yar ) {          // учитываем дни в месяцах
	int kk = day;
	if (vysokostnyi(years) && (month > 2))
		kk += yar * 366;
	else yar += yar * 365;
	switch (month - 1) {
	case 1: kk += 31;
	case 2: kk += 28;
	case 3: kk += 31;
	case  4: kk += 30;
	case  5: kk += 31;
	case  6: kk += 30;
	case  7: kk += 31;
	case  8: kk += 31;
	case  9: kk += 30;
	case  10: kk += 31;
	case  11: kk += 30;
	case  12: kk += 31;
	}
	return kk;
}
int raznica(int day1,int month1,int year1,int day2,int month2,int year2) { // короче считаем разницу саму
	int kkk = func(day2, month2, year2) - func(day1, month1, year1);
	return kkk;
}
int main()														// вывод всего нужного в итоге
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int day1, month1, year1, day2, month2, year2;
	cout << "Введите пожалуйста первую свою дату:)))\n";
	cout << "Введите изначальный день\n";
	cin >> day1;
	cout << "Введите изначальный месяц\n";
	cin >> month1;
	cout << "Введите изначальный год\n";
	cin >> year1;
	cout << "Введите пожалуйста свою вторую дату:)))\n";
	cout << "Введите ласт день\n";
	cin >> day2;
	cout << "Введите ласт месяц\n";
	cin >> month2;
	cout << "Введите ласт год\n";
	cin >> year2;
	cout << "Между двумя датами которые вы назвали находятся:\n";
	cout << raznica(day1, month1, year1, day2, month2, year2) << "дней между ними:)))\n";
}
