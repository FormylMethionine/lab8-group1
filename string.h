class string
{
	private:
		char* str_ = nullptr;
		int nchar_ = 0;
	public:
		string(const char*);
		char* c_str();
};

bool str_eq(const char*, const char*);
int strlen(const char*);
