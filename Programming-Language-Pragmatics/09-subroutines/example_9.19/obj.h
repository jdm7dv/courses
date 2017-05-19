// Example 9.19

class obj {
  public:
    obj();
    ~obj();
    explicit obj(const char* p);
    obj(const obj& other);
    obj(obj&& other);
    obj& operator=(const obj& other);
    obj& operator=(obj&& other);
  private:
    char* payload;
};

// Note that the following are not visible when compiling uses;
// this inhibits various copy-avoiding optimizations.

extern bool test();

extern obj foo(const char* p);
