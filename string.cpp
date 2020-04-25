#include "./string.h"

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
	nchar_ = min(strlen(p_str), maxsize_);
	tabsize_ = nchar_;
	str_ = new char[tabsize_];
	for(int i = 0; i<nchar_; i++){
		str_[i] = p_str[i];
	}
};

string::string(const char* init){
	nchar_ = min(strlen(init), maxsize_);
	tabsize_ = nchar_;
	str_ = new char[tabsize_];
	for(int i = 0; i<nchar_; i++){
		str_[i] = init[i];
	}
};

string::~string(){	
	delete[] str_;
}

char* string::c_str() const{
	char* ret = new char[nchar_+1];
	for (int i = 0; i<nchar_; i++){
		ret[i] = str_[i];
	}
	ret[nchar_] = '\0';
	return ret;
};

size_t string::size() const{
	size_t ret = nchar_*sizeof(char);
	return ret;
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

size_t string::length() const{
	return nchar_*sizeof(char);
}


size_t string::capacity() const{
	size_t ret = tabsize_*sizeof(char);
	return ret;
}

bool string::empty() const{
	if (nchar_ == 0){
		return true;
	} else {
		return false;
	}
}

void string::reserve(size_t n){
	int new_size = min(maxsize_, n);
	char* new_str = new char[new_size];
	for (int i = 0; i<nchar_; i++){
		new_str[i] = str_[i];
	}
	delete[] str_;
	str_ = new_str;
	tabsize_ = new_size;
}

string& string::operator=(const char* s){
	int size_s = strlen(s);
	if (size_s >= tabsize_){
		nchar_ = size_s;
		for (int i = 0; i<nchar_; i++){
			str_[i] = s[i];
		}
	} else {
		nchar_ = min(maxsize_, size_s);
		tabsize_ = nchar_;
		delete[] str_;
		str_ = new char[tabsize_];
		for (int i = 0; i<nchar_; i++){
			str_[i] = s[i];
		}
	}
	return *this;
}
