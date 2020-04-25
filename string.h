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
		~string();
		char* c_str() const;
		size_t size() const;
		void clear();
		string& operator =(char);
		size_t length() const; 
		size_t capacity() const;
		bool empty() const;
		void reserve(size_t n);
		string& operator=(const char*);
};

string operator +(const string&, const char*);
bool str_eq(const char*, const char*);
int strlen(const char*);
