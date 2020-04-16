#include "./string.h"
#include <iostream>

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

int main(){
	string test_cstring_constructor("Hello World"); 
	string test_copy_constructor(test_cstring_constructor); 
	string test_clear_str("Hello World"); 
	string test_eq_char_str("Hello World");

	std::cout << test_c_str(test_cstring_constructor) << std::endl;
	std::cout << test_c_str(test_copy_constructor) << std::endl;
	
	std::cout << test_size(test_cstring_constructor, 11) << std::endl;
	std::cout << test_size(test_copy_constructor, 11) << std::endl;

	std::cout << test_clear(test_clear_str) << std::endl;
	
	std::cout << test_eq_char(test_eq_char_str, 'c') << std::endl;
	std::cout << test_eq_char(test_clear_str, 'c') << std::endl;

	std::cout << test_addition() << std::endl;

	std::cout << test_length() << std::endl;

	return 0;
}
