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
	string test1("");
	test1 = c;
	if (str_eq(test.c_str(), str_test) && str_eq(test1.c_str(), str_test)){
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

bool test_maxsize(){
	char* test1 = new char[105];
	for (int i=0; i<105; i++){
		test1[i]='a';
	}
	string test2(test1);
	if (test2.length() == 100 && strlen(test2.c_str()) == 100){
		return true;
	} else {
		return false;
	}
}

bool test_capacity(){
	string test1("Hello World");
	char* test2 = new char[105];
	for (int i=0; i<105; i++){
		test2[i]='a';
	}
	string test3(test2);
	if (test1.capacity() == 11 && test3.capacity() == 100){
		return true;
	} else {
		return false;
	}
}

bool test_empty(){
	string test1("");
	string test2("42");
	if (test1.empty() && !test2.empty()){
		return true;
	} else {
		return false;
	}
}

bool test_reserve(){
	string test1("Salut, et encore merci pour le poisson");
	string test2("Le dernier restaurant avant la fin du monde");
	test1.reserve(50);
	test2.reserve(105);
	if (test1.capacity() == 50 && test2.capacity() == 100){
		return true;
	} else {
		return false;
	}
}
