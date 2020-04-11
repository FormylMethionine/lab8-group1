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

int main(){
	string test_cstring_constructor("Hello World"); 
	string test_copy_constructor(test_cstring_constructor); 
	std::cout << test_c_str(test_cstring_constructor) << std::endl;
	std::cout << test_c_str(test_copy_constructor) << std::endl;
	return 0;
}
