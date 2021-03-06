#include "./string.h"

//============================================================================
// Non member useful functions
//============================================================================

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

//============================================================================
// Constructors
//============================================================================

string::string(){
	tabsize_ = 0;
	nchar_ = 0;
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

//============================================================================
// Destructor
//============================================================================

string::~string(){	
	delete[] str_;
}

//============================================================================
// char*
//============================================================================

char* string::c_str() const{
	char* ret = new char[nchar_+1];
	for (int i = 0; i<nchar_; i++){
		ret[i] = str_[i];
	}
	ret[nchar_] = '\0';
	return ret;
};

//============================================================================
// size_t
//============================================================================

size_t string::size() const{
	size_t ret = nchar_*sizeof(char);
	return ret;
}

size_t string::length() const{
	return nchar_*sizeof(char);
}

size_t string::capacity() const{
	size_t ret = tabsize_*sizeof(char);
	return ret;
}

size_t string::maxsize() const{
	size_t ret = maxsize_;
	return ret;
}

//============================================================================
// void
//============================================================================

void string::clear(){
	nchar_ = 0;
	tabsize_ = 0;
	delete[] str_;
	str_ = new char[tabsize_];
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

void string::resize(size_t n){
	if (n < nchar_){
		nchar_ = n;
	} else if (n > nchar_ && n > tabsize_){
		int new_size = min(maxsize_, n);
		char* new_str = new char[new_size];
		for (int i = 0; i<nchar_; i++){
			new_str[i] = str_[i];
		}
		delete[] str_;
		str_ = new_str;
		tabsize_ = new_size;
	}
}


//============================================================================
// bool
//============================================================================

bool string::empty() const{
	if (nchar_ == 0){
		return true;
	} else {
		return false;
	}
}

//============================================================================
// Operators
//============================================================================

string& string::operator =(char c){
	if (tabsize_ == 0){
		delete[] str_;
		str_ = new char[1];
		str_[0] = c;
		nchar_ = 1;
		tabsize_ = 1;
		return *this;
	} else {
		nchar_ = 1;
		str_[0] = c;
		return *this;
	}
}

string& string::operator =(const char* s){
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

string& string::operator =(const string& str){
	char* cstr = str.c_str();
	int size_s = strlen(cstr);
	if (size_s >= tabsize_){
		nchar_ = size_s;
		for (int i = 0; i<nchar_; i++){
			str_[i] = cstr[i];
		}
	} else {
		nchar_ = min(maxsize_, size_s);
		tabsize_ = nchar_;
		delete[] str_;
		str_ = new char[tabsize_];
		for (int i = 0; i<nchar_; i++){
			str_[i] = cstr[i];
		}
	}
	return *this;
}


//============================================================================
// Non member operators
//============================================================================

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

string operator +(const string& s1, const string& s2){
	char* s2_c = s2.c_str();
	string ret = s1 + s2_c;
	return ret;
}

string operator +(const string& s, const char c){
	char c2[1];
	c2[0] = c;
	string ret = s + c2;
	return ret;
}
