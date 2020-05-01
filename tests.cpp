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

const char* test_c_str(){
	string test("Hello World");
	char* value = test.c_str();
	if (str_eq(value, "Hello World") && !str_eq(value, "Hello world")){
		return "PASS";
	} else {
		return "FAIL";
	}
}

const char* test_size(){
	string test("Mostly Harmless");
	if (test.size() == strlen("Mostly Harmless")){
		return "PASS";
	} else {
		return "FAIL";
	}
}

const char* test_clear(){
	string test("shenanigans");
	test.clear();
	if (strlen(test.c_str()) == 0){
		return "PASS";
	} else {
		return "FAIL";
	}
}

const char* test_eq_char(){
	string test1("doesn't matter");
	test1 = 'c';
	char str_test[1];
	str_test[0] = 'c';
	string test2("");
	test1 = 'c';
	if (str_eq(test1.c_str(), str_test)){
		return "PASS";
	} else {
		return "FAIL";
	}
}

const char* test_addition(){
	string test("Hello ");
	string value = test + "World";
	if (str_eq(value.c_str(), "Hello World")){
		return "PASS";
	} else {
		return "FAIL";
	}
}

const char* test_length(){
	string test1("Hello");
	string test2("Hello");
	test2 = 'c';
	if (test1.length() == 5*sizeof(char) && test2.length() == sizeof(char)){
		return "PASS";
	} else {
		return "FAIL";
	}
}

const char* test_maxsize(){
	char* test1 = new char[105];
	for (int i=0; i<105; i++){
		test1[i]='a';
	}
	string test2(test1);
	if (test2.length() == 100 && strlen(test2.c_str()) == 100 
			&& test2.maxsize() == 100){
		return "PASS";
	} else {
		return "FAIL";
	}
}

const char* test_capacity(){
	string test1("Hello World");
	char* test2 = new char[105];
	for (int i=0; i<105; i++){
		test2[i]='a';
	}
	string test3(test2);
	if (test1.capacity() == 11 && test3.capacity() == 100){
		return "PASS";
	} else {
		return "FAIL";
	}
}

const char* test_empty(){
	string test1("");
	string test2("42");
	if (test1.empty() && !test2.empty()){
		return "PASS";
	} else {
		return "FAIL";
	}
}

const char* test_reserve(){
	string test1("Salut, et encore merci pour le poisson");
	string test2("Le dernier restaurant avant la fin du monde");
	test1.reserve(50);
	test2.reserve(105);
	if (test1.capacity() == 50 && test2.capacity() == 100){
		return "PASS";
	} else {
		return "FAIL";
	}
}

const char* test_eq_cstr(){
	string test("Hello world");
	test = "The Amazing Maurice and His Educated Rodents";
	if (str_eq(test.c_str(), "The Amazing Maurice and His Educated Rodents")){
		return "PASS";
	} else {
		return "PASS";
	}
}


const char* test_plus_2str(){
	string test1("Hello ");
	string test2("World");
	string add = test1 + test2;
	if (str_eq(add.c_str(), "Hello World")){
		return "PASS";
	} else {
		return "FAIL";
	}
}

const char* test_resize(){
	string test1("I'm running out of ideas");
	string test2(test1);
	string test3(test2);
	test1.resize(2);
	test2.resize(50);
	test3.resize(120);
	if (str_eq(test1.c_str(), "I'")
			&& test2.capacity() == 50
			&& test3.capacity() == 100){
		return "PASS";
	} else {
		return "FAIL";
	}
}

const char* test_op_eq_str(){
	string test("OOOOOO");
	string copy = test;
	if (str_eq(copy.c_str(), test.c_str())
			&& copy.length() == test.length()
			&& copy.capacity() == test.capacity()){
		return "PASS";
	} else {
		return "FAIL";
	}
}

const char* test_op_plus_char(){
	string test("O");
	test = test + 'k';
	if (str_eq(test.c_str(), "Ok")){
		return "PASS";
	} else {
		return "FAIL";
	}
}
