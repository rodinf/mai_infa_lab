#include <iostream>
#include <windows.h>
#include <math.h>

struct year {
	unsigned int god, m1, d1, m2, d2;	
};

unsigned int months[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool visokosny_check(unsigned int _year) {
	if(_year % 4 == 0) {
		if(_year % 100 == 0){
			if(_year % 400 == 0){
				return true;
			}
			else 
				return false;
		}
		else
			return true;
	}
	else
		return false;
		
}

int main() {
	year Year;
	
	std::cin >> Year.god >> Year.m1 >> Year.d1 >> Year.m2 >> Year.d2;
	
	if(visokosny_check(Year.god) == true){
		months[2] = 29;
		std::cout<<"Visokosny: Yes"<<std::endl;	
	}
	else 
		std::cout<<"Visokosny: No"<<std::endl;
	
	for(int i=1; i<= 12; i++){
		std::cout<<months[i]<<" ";
	}
	
	std::cout<<std::endl;
		
	int diff = abs(Year.d2 - Year.d1);
	
	unsigned int m1_sort = Year.m1, m2_sort = Year.m2, m_flip;
	
	if(Year.m1 > Year.m2){
		m_flip = m1_sort;
		m1_sort = m2_sort;
		m2_sort = m_flip;
	}
	
	for(int i = m1_sort; i< m2_sort; i++){
		
		diff += months[i];
		
	}
	
	std::cout<<"Raznica: "<<diff<<std::endl;

	system("pause");
	
	
}
