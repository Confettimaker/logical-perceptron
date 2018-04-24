#ifndef XOR_H
#define XOR_H

#include "and.h"

class Xor_Gate
{
  unsigned short A;
  unsigned short B;
  bool output;
  public:
    Xor_Gate()
    {
      A = rand() % 2;
      B = rand() % 2;
      output = ((static_cast<bool>(A) || static_cast<bool>(B)) && !(static_cast<bool>(A) && static_cast<bool>(B)));
    }

    void reset_values()
    {
      A = rand() % 2;
      B = rand() % 2;
      output = ((static_cast<bool>(A) || static_cast<bool>(B)) && !(static_cast<bool>(A) && static_cast<bool>(B)));
    }

    void set_values(const int a, const int b)
    {
      A = a;
      B = b;
      output = ((static_cast<bool>(A) || static_cast<bool>(B)) && !(static_cast<bool>(A) && static_cast<bool>(B)));
    }

    void set_values_from_neurons(const int a, const int b)
    {
      A = a;
      B = b;
      output = (static_cast<bool>(a) && !static_cast<bool>(b));
    }

    bool get_output() const
    {
      return output;
    }

    unsigned short get_a() const
    {
      return A;
    }

    unsigned short get_b() const
    {
      return B;
    }
};

#endif
