#include "./string.h"
#include <iostream>

bool str_eq(const char* p1, const char* p2){
	if (strlen(p1) == strlen(p2)){
		for (int i = 0; i<strlen(p1)+1; i++){
			if (p1[i] != p2[i]){
				return false;
			}
		}
		return true;
	}
	return false;
}

int strlen(const char* str){
	int i = 0;
	for (i; str[i] != '\0'; i++){}
	return i;
}

string::string(const string& p){
	char* p_str = p.c_str();
	nchar_ = strlen(p_str);
	tabsize_ = nchar_;
	str_ = new char[tabsize_];
	for(int i = 0; i<nchar_; i++){
		str_[i] = p_str[i];
	}
};

string::string(const char* init){
	nchar_ = strlen(init),
	tabsize_ = nchar_;
	str_ = new char[tabsize_];
	for(int i = 0; i<nchar_; i++){
		str_[i] = init[i];
	}
};

char* string::c_str() const{
	char* ret = new char[nchar_+1];
	for (int i = 0; i<nchar_; i++){
		ret[i] = str_[i];
	}
	ret[nchar_] = '\0';
	return ret;
};

int string::size() const{
	return nchar_*sizeof(char);
}

void string::clear(){
	delete[] str_;
	str_ = new char[0];
}
