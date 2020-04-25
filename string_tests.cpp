#include "./string.h"
#include "./tests.h"
#include <iostream>

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

	std::cout << test_maxsize() << std::endl;

	std::cout << test_capacity() << std::endl;

	std::cout << test_empty() << std::endl;

	std::cout << test_reserve() << std::endl;

	return 0;
}
