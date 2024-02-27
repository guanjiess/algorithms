#include <stdio.h>

int is_leap(int n){
    if((n % 4 == 0) && (n % 100 != 0) || (n % 400 == 0)){
	return 1;
    }
    return 0;
}

int main(){
    int month_day[13][2] = {{0, 0}, {31, 31}, {28, 29}, {31, 31}, {30, 30}, {31, 31}, {30, 30},
   			    {31, 31}, {31, 31}, {30, 30}, {31, 31}, {30, 30}, {31,31} };

    int date1, date2;
    int big_date, small_date;
    while(scanf("%d%d", &date1, &date2) != EOF){
    	big_date = date1 > date2 ? date1 : date2;
	small_date = date1 < date2 ? date1 : date2;
	//printf("bigdate is: %d, small date is%d\n", big_date, small_date);
	
	int y1, m1, day1;
	int y2, m2, day2;
	y1 = big_date / 10000;
	m1 = big_date % 10000 / 100;
	day1 = big_date % 100;
	y2 = small_date / 10000;
	m2 = small_date % 10000 / 100;
	day2 = small_date % 100;

	int days = 1;

	while(y2 < y1 || m2 < m1 || day2 < day1){
	    int is_y2_leap = is_leap(y2);
	    //printf("is_leap:%d\n", is_y2_leap);
	    int m_day = month_day[m2][is_y2_leap];
	    //printf("m_day is: %d\n", m_day);
	   
	    day2 ++;
	    if(day2 == m_day){
	    	m2 ++;
		day2 = 1;
		days ++;
	    }
	    if(m2 == 13){
	    	y2 ++;
		m2 = 1;
	    }
	    days ++;
	}
	printf("%d\n", days);
    } 
    return 0;
}
