class string
{
	private:
		char* str_ = nullptr;
		int nchar_ = 0;
		int tabsize_ = 0;
	public:
		string(const string&);
		string(const char*);
		char* c_str() const;
		int size() const;
		void clear();
		string& operator =(char);
};

bool str_eq(const char*, const char*);
int strlen(const char*);
