#include "./string.h"
#include <iostream>

bool test_c_str(string test){
	char* value = test.c_str();
	if (str_eq(value, "Hello World") && !str_eq(value, "Hello world")){
		return true;
	} else {
		return false;
	}
}

int main(){
	string test("Hello World"); 
	std::cout << test_c_str(test) << std::endl;
	return 0;
}
