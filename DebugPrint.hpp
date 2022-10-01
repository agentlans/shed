#ifndef _DEBUGPRINTER
#define _DEBUGPRINTER

#include <iostream>
#include <map>
#include <tuple>
#include <vector>

using std::ostream;

// Prints various C++ standard library data structures to stdout
// or to other `std::ostream's

// For printing a vector
template <class T> ostream &operator<<(ostream &os, const std::vector<T> &obj) {
  auto it = obj.begin();
  os << "[";
  while (it != obj.end()) {
    os << *it;
    it++;
    if (it != obj.end()) {
      os << ", ";
    }
  }
  os << "]";
  return os;
}

// For printing a map
template <class T, class U>
ostream &operator<<(ostream &os, const std::map<T, U> &obj) {
  auto it = obj.begin();
  os << "{";
  while (it != obj.end()) {
    os << it->first << ": " << it->second;
    it++;
    if (it != obj.end()) {
      os << ", ";
    }
  }
  os << "}";
  return os;
}

// Templates for printing tuples.
template <int I, class... Ts> // I is the number of elements remaining
struct TuplePrinter {
  static void print(ostream &os, std::tuple<Ts...> obj) {
    constexpr int n = std::tuple_size<decltype(obj)>::value;
    os << std::get<n - I>(obj);
    if (I != 1) {
      os << ", ";
    }
    TuplePrinter<I - 1, Ts...>::print(os, obj);
  }
};

template <class... Ts> struct TuplePrinter<0, Ts...> {
  // After all the elements have been printed
  static void print(ostream &os, std::tuple<Ts...> obj) { os << ")"; }
};

template <class... Ts> struct TupleP {
  // Print the first element
  TupleP(ostream &os, std::tuple<Ts...> obj) {
    os << "(";
    constexpr int n = std::tuple_size<decltype(obj)>::value;
    TuplePrinter<n, Ts...>::print(os, obj);
  }
};

// The output operator for the tuple
template <class... Ts>
ostream &operator<<(ostream &os, const std::tuple<Ts...> &obj) {
  TupleP<Ts...>(os, obj);
  return os;
}

#endif
