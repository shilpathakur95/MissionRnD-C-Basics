/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/
int power(int a, int b);
int isOlder(char *dob1, char *dob2) {
	int iterator = 0, iterator2,iterator3=1, day1 = 0, month1 = 0, day2 = 0, month2 = 0, year1 = 0, year2 = 0,count=0;
	for (iterator = 0; dob1[iterator] != '-'; iterator++)
	{
		day1 += ((dob1[iterator] - 48)*power(10,iterator3));
		iterator3--;
	}
	iterator3 = 1;
	for (iterator2 = iterator + 1; dob1[iterator2] != '-'; iterator2++)
	{
		month1 +=(( dob1[iterator2] - 48) * power(10, iterator3));
		iterator3--;
	}
	for (iterator = iterator2 + 1; dob1[iterator] != '\0'; iterator++)
		count++;
	iterator3 = count-1;
	for (iterator = iterator2 + 1; dob1[iterator] != '\0'; iterator++)
	{
		year1 += ((dob1[iterator] - 48 )* power(10, iterator3));
		iterator3--;
	}
	iterator3 = 1;
	for (iterator = 0; dob2[iterator] != '-'; iterator++)
	{
		day2 += ((dob2[iterator] - 48) * power(10, iterator3));
		iterator3--;
	}
	iterator3 = 1;
	for (iterator2 = iterator + 1; dob2[iterator2] != '-'; iterator2++)
	{
		month2 += ((dob2[iterator2] - 48 )* power(10, iterator3));
		iterator3--;
	}
	count = 0;
	for (iterator = iterator2 + 1; dob2[iterator] != '\0'; iterator++)
		count++;
	iterator3 = count-1;
	for (iterator = iterator2 + 1; dob2[iterator] != '\0'; iterator++)
	{
		year2 += ((dob2[iterator] - 48) * power(10, iterator3));
		iterator3--;
	}
	if (day1 > 31 || day2 > 31 || month1 > 12 || month2 > 12 )
		return -1;
	if(day1 <= 0 || day2 <= 0 || month1 <= 0 || month2 <= 0 || year1 <= 0 || year2 <= 0)
		return -1;
	if (day1 > 30 && (month1 == 4 || 6 || 9 || 11))
		return -1;
	if (day2 > 30 && (month2 == 4 || 6 || 9 || 11))
		return -1;
	if ((day1 > 29 && month1 == 2 && year1 % 4 == 0) || (day2 > 29 && month2 == 2 && year2 % 4 == 0))
		return -1;
	if ((day1 > 28 && month1 == 2 && year1 % 4 != 0) || (day2 > 28 && month2 == 2 && year2 % 4 != 0))
		return -1;
	if (year1 < year2)
		return 1;
	else if (year1 > year2)
		return 2;
	else 
	{
		if (month1 < month2)
			return 1;
		else if (month1 > month2)
			return 2;
		else 
		{
			if (day1 < day2)
				return 1;
			else if (day1 > day2)
				return 2;
			else 
				return 0;
		}
	}
	return 0;
}
int power(int a, int b)
{
	int it,pow=1;
	if (b != 0)
	{
		for (it = 1; it <= b; it++)
			pow = pow * a;
	}
	return pow;
}