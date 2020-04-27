#include <cstddef>

//Non member function, applying to cstrings
int strlen(const char*);

class string
{
	private:
		char* str_ = nullptr; //array of char
		size_t nchar_ = 0; //number of (relevant) char in the array
		size_t tabsize_ = 0; //actual size of the array
		size_t maxsize_ = 100; //maximal size of the array
	public:
		//Constructors
		string(const string&);
		string(const char*);
		//Destructor
		~string();
		//char*
		char* c_str() const;
		//size_t
		size_t size() const;
		size_t length() const; 
		size_t capacity() const;
		size_t maxsize() const;
		//void
		void clear();
		void reserve(size_t);
		void resize(size_t);
		//bool
		bool empty() const;
		//Operators
		string& operator =(char);
		string& operator =(const char*);
};

//Non member operators
string operator +(const string&, const char*);
string operator +(const string&, const string&);
