#include "./string.h"
#include <iostream>

int strlen(const char* str){
	int i = 0;
	for (i; str[i] != '\0'; i++){}
	return i;
}

int min(int arg1, int arg2){
	if (arg1 < arg2){
		return arg1;
	} else {
		return arg2;
	}
}

string operator +(const string& p1, const char* p2){
	char* p1_c = p1.c_str();
	int lenp1 = strlen(p1_c);
	int lenp2 = strlen(p2);
	int len = lenp1 + lenp2;
	char* ret_c = new char[len];
	int i = 0;
	for (i; i<lenp1; i++){
		ret_c[i] = p1_c[i];
	}
	for (i; i<len; i++){
		ret_c[i] = p2[i - lenp1];
	}
	string ret(ret_c);
	return ret;
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
	nchar_ = 0;
	tabsize_ = 0;
	delete[] str_;
	str_ = new char[tabsize_];
}

string& string::operator =(char c){
	nchar_ = 1;
	str_[0] = c;
	return *this;
}

int string::length(){
	return nchar_*sizeof(char);
}
