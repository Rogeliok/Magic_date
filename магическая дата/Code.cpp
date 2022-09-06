# include <iostream>

bool Is_Day_Magic(int day, int month, int year) {
	return day * month == year % 100;
}

void output(int day, int month, int year) {
	if (day < 10 && month >= 10) printf("0%d.%d.%d\n", day, month, year);
	else if (day < 10 && month < 10) printf("0%d.0%d.%d\n", day, month, year);
	else if (day >= 10 && month >= 10) printf("%d.%d.%d\n", day, month, year);
	else if (day >= 10 && month < 10) printf("%d.0%d.%d\n", day, month, year);
}

int number_of_day(int month, int year) {
	if (month == 2 && year % 4 == 0) return 29;
	else if (month == 2) return 28;
	else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) return 31;
	else if (month == 4 || month == 6 || month == 9 || month == 11) return 30;
	else return 0;
}

int main() {
	for (int year = 1901; year < 2001; year++)
		for (int month = 1; month < 13; month++)
			for (int day = 1; day < number_of_day(month, year) + 1; day++)
				if (Is_Day_Magic(day, month, year))
					output(day, month, year);
	return 0;
}
