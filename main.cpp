#include <iostream>
#include "perceptron.h"

using std::cout;
using std::endl;

int main()
{
  srand(time(NULL));
  Perceptron p;
  float inputs[2];
  int train_for = 100000;
  int cycles = 100;
  int correct = 0, incorrect = 0;
  int output;
  int guess;

  //Training perceptron to become an OR gate

  Or_Gate gate_or;
  for (int i = 0;i < train_for;i++)
  {
    correct = incorrect = 0;
    for (int j = 0;j < cycles;j++)
    {
      inputs[0] = gate_or.get_a();
      inputs[1] = gate_or.get_b();
      output = gate_or.get_output();
      guess = p.guess(inputs, 2);
      float error = output - guess;
      if (error == 0)
        correct ++;
      else
      {
        incorrect ++;
        p.train(error, inputs, 2);
      }
      gate_or.reset_values();
    }
  }

  cout << "\nCorrect: " << correct << "\nIncorrect: " << incorrect << endl;
  cout << "Actual: " << output << "\nGuess: " << guess << endl;
  cout << "(" << inputs[0] << " || " << inputs[1] << ")" << " = " << guess << endl;

  //Training perceptron to become an AND gate

  And_Gate gate_and;
  for (int i = 0;i < train_for;i++)
  {
    correct = incorrect = 0;
    for (int j = 0;j < cycles;j++)
    {
      inputs[0] = gate_and.get_a();
      inputs[1] = gate_and.get_b();
      output = gate_and.get_output();
      guess = p.guess(inputs, 2);
      float error = output - guess;
      if (error == 0)
        correct ++;
      else
      {
        incorrect ++;
        p.train(error, inputs, 2);
      }
      gate_and.reset_values();
    }
  }

  cout << "\nCorrect: " << correct << "\nIncorrect: " << incorrect << endl;
  cout << "Actual: " << output << "\nGuess: " << guess << endl;
  cout << "(" << inputs[0] << " && " << inputs[1] << ")" << " = " << guess << endl;

  return 0;
}
