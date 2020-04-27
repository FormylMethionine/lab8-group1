#include "./string.h"
#include "./tests.h"
#include <iostream>

int main(){
	string test_cstring_constructor("Hello World"); 
	string test_copy_constructor(test_cstring_constructor); 
	string test_clear_str("Hello World"); 
	string test_eq_char_str("Hello World");

	std::cout << "string can't exceed the maximal size: "
		<< test_maxsize() << std::endl;

	std::cout << "test for cstring constructor: "
		<< test_c_str(test_cstring_constructor) << std::endl;

	std::cout << "test for copy constructor: "
		<< test_c_str(test_copy_constructor) << std::endl;
	
	std::cout << "test for size_t size() const method: "
		<< test_size(test_cstring_constructor, 11) << std::endl;

	std::cout << "test for void clear() method: "
		<< test_clear(test_clear_str) << std::endl;
	
	std::cout << "test for string& operator =(const char): "
		<< test_eq_char(test_eq_char_str, 'c') << std::endl;
	//std::cout << test_eq_char(test_clear_str, 'c') << std::endl;
	//second test need to be combined in first

	std::cout << "test for string operator +(const string&, const char*): "
		<< test_addition() << std::endl;

	std::cout << "test for size_t length() const: "
		<< test_length() << std::endl;

	std::cout << "test for size_t capacity() const: " 
		<< test_capacity() << std::endl;

	std::cout << "test for void empty(): "
		<< test_empty() << std::endl;

	std::cout << "test for void reserve(size_t): " 
		<< test_reserve() << std::endl;

	std::cout << "test for string operator =(const char*): "
		<< test_eq_cstr() << std::endl;

	std::cout << "test for string operator =(const char*, const char*): "
		<< test_plus_2str() << std::endl;

	return 0;
}
