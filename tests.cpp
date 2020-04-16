#include "./string.h"
#include "./tests.h"

bool str_eq(const char* p1, const char* p2){
	//test equality between two cstrings
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

bool test_c_str(string& test){
	char* value = test.c_str();
	if (str_eq(value, "Hello World") && !str_eq(value, "Hello world")){
		return true;
	} else {
		return false;
	}
}

bool test_size(string& test, int expected_size){
	int value = test.size();
	if (value == expected_size){
		return true;
	} else {
		return false;
	}
}

bool test_clear(string& test){
	test.clear();
	if (strlen(test.c_str()) == 0){
		return true;
	} else {
		return false;
	}
}

bool test_eq_char(string& test, char c){
	test = c;
	char str_test[1];
	str_test[0] = c;
	if (str_eq(test.c_str(), str_test)){
		return true;
	} else {
		return false;
	}
}

bool test_addition(){
	string test("Hello ");
	string value = test + "World";
	if (str_eq(value.c_str(), "Hello World")){
		return true;
	} else {
		return false;
	}
}

bool test_length(){
	string test1("Hello");
	string test2("Hello");
	test2 = 'c';
	if (test1.length() == 5*sizeof(char) && test2.length() == sizeof(char)){
		return true;
	} else {
		return false;
	}
}


