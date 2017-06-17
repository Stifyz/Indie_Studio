//
// error.hpp for cpp_plazza in /home/maxoulak/work/B4/C++/cpp_plazza/include/
//
// Made by Maxime Maisonnas
// Login   <maxime.maisonnas@epitech.eu>
//
// Started on  Tue Apr 11 12:31:48 2017 Maxime Maisonnas
// Last update Thu Jun  1 16:33:05 2017 Maxime Maisonnas
//

#ifndef ERROR_HPP_
# define ERROR_HPP_

# include <iostream>
# include <exception>

class                 Error : public std::exception {
public:
  Error(std::string const &err) throw() {
    _err = "Error : " + err + ".";
  }
  virtual ~Error() throw() {}

  virtual const char  *what() const throw() {
    return (_err.c_str());
  }
private:
  std::string         _err;
};

class                 Stop : public std::exception {
public:
  Stop() throw() {}
  virtual ~Stop() throw() {}

  virtual const char  *what() const throw() { return (""); }
private:
  std::string         _err;
};

class                 NetErr : public std::exception {
public:
  NetErr(std::string const &err) throw() {
    _err = "Network error : " + err + ".";
  }
  virtual ~NetErr() throw() {}

  virtual const char  *what() const throw() {
    return (_err.c_str());
  }
private:
  std::string         _err;
};

#endif /* end of include guard: ERROR_HPP_ */
