#include <cstddef>

class string
{
	private:
		char* str_ = nullptr; //array of char
		int nchar_ = 0; //number of (relevant) char in the array
		int tabsize_ = 0; //actual size of the array
		int maxsize_ = 100; //maximal size of the array
	public:
		string(const string&);
		string(const char*);
		char* c_str() const;
		size_t size() const;
		void clear();
		string& operator =(char);
		int length(); 
};

string operator +(const string&, const char*);
bool str_eq(const char*, const char*);
int strlen(const char*);
