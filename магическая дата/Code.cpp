# include <iostream>

int modul(int n, int d);
bool Is_Day_Magic(int day, int month, int year);
void output(int day, int month, int year);
int number_of_day(int month, int year);

int main() {
	for (int year = 1901; year < 2001; year++)
		for (int month = 1; month < 12; month++)
			for (int day = 1; day < number_of_day(month, year); day++)
				if (Is_Day_Magic(day, month, year))
					output(day, month, year);
	return 0;
}

bool Is_Day_Magic(int day, int month, int year) {
	return day * month == modul(year, 100);
}

int modul(int n, int d) {
	while (n >= d)
		n -= d;
	return n;
}

void output(int day, int month, int year) {
	if (day < 10 && month >= 10) printf("0%d.%d.%d\n", day, month, year);
	else if (day < 10 && month < 10) printf("0%d.0%d.%d\n", day, month, year);
	else if (day >= 10 && month >= 10) printf("%d.%d.%d\n", day, month, year);
	else if (day >= 10 && month < 10) printf("%d.0%d.%d\n", day, month, year);
}

int number_of_day(int month, int year) {
	if (month == 2 && modul(year, 4) == 0) return 29;
	if (month == 2) return 28;
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) return 31;
	if (month == 4 || month == 6 || month == 9 || month == 11) return 30;
	return 0;
}
