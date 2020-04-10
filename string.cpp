#include "./string.h"
#include <iostream>

bool str_eq(const char* p1, const char* p2){
	for (int i = 0; p1[i] != '\0' && p2[i] != '\0'; i++){
		if (p1[i] != p2[i]){
			return false;
		}
	}
	return true;
}

string::string(const char* init){
	str_ = new char[100];
	for(int i = 0; init[i] != '\0'; i++){
		str_[i] = init[i];
		nchar_ = i;
	}
};

char* string::c_str(){
	return str_;
};
