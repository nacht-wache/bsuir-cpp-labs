#ifndef BSUIR_CPP_LABS_LAB8_EXCEPTIONS_11_SRC_MY_EXCEPTION_H_
#define BSUIR_CPP_LABS_LAB8_EXCEPTIONS_11_SRC_MY_EXCEPTION_H_

class My_exception {
 public:
  My_exception() = default;
  My_exception(const My_exception&) = default;
  My_exception& operator=(const My_exception&) = default;
  ~My_exception() = default;
};

class Helper_throw {
 public:
  Helper_throw() {
  	throw My_exception();
  }
  Helper_throw(const Helper_throw&) {
	throw My_exception();
  }
  ~Helper_throw() = default;
  explicit Helper_throw(char ch) : ch(ch) {}
 private:
  char ch = '0';
};

#endif //BSUIR_CPP_LABS_LAB8_EXCEPTIONS_11_SRC_MY_EXCEPTION_H_
