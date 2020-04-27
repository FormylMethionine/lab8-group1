#include "./string.h"
#include "./tests.h"
#include <iostream>

int main(){
	std::cout << "test for cstring constructor: "
		<< test_c_str() << std::endl;

	std::cout << "test for copy constructor: "
		<< test_c_str() << std::endl;
	
	std::cout << "test for size_t size() const method: "
		<< test_size() << std::endl;

	std::cout << "test for void clear() method: "
		<< test_clear() << std::endl;
	
	std::cout << "test for string& operator =(const char): "
		<< test_eq_char() << std::endl;
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

	std::cout << "test for size_t maxsize() const: "
		<< test_maxsize() << std::endl;

	std::cout << "test for void resize(size_t): "
		<< test_resize() << std::endl;

	return 0;
}
