#ifndef AND_H
#define AND_H

#include "or.h"

class And_Gate
{
  unsigned short A;
  unsigned short B;
  bool output;
  public:
    And_Gate()
    {
      A = rand() % 2;
      B = rand() % 2;
      output = (static_cast<bool>(A) && static_cast<bool>(B));
    }

    void reset_values()
    {
      A = rand() % 2;
      B = rand() % 2;
      output = (static_cast<bool>(A) && static_cast<bool>(B));
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
