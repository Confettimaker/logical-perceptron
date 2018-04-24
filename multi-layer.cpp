#include <iostream>
#include "perceptron.h"

using std::cout;
using std::endl;

int main()
{
  srand(time(NULL));
  Perceptron p_or;
  Perceptron p_and;
  Perceptron p_xor;
  Xor_Gate gate_xor;
  And_Gate gate_and;
  Or_Gate gate_or;

  int train_for = 1000;
  int cycles = 100;
  float inputs[2];
  float error;
  int guess;
  int correct = 0, incorrect = 0;

  //Trainging gate_or perceptron
  for (int i = 0;i < train_for;i++)
  {
    correct = incorrect = 0;
    for (int j = 0;j < cycles;j++)
    {
      gate_or.reset_values();
      inputs[0] = gate_or.get_a();
      inputs[1] = gate_or.get_b();
      guess = p_or.guess(inputs, 2);
      error = gate_or.get_output() - guess;
      if (error == 0)
      {
        correct ++;
      }
      else
      {
        incorrect ++;
        p_or.train(error, inputs, 2);
      }
    }
  }

  cout << "OR PERCEPTRON\n\nCorrect: " << correct << "\nIncorrect: " << incorrect << endl;

  //Trainging gate_and perceptron
  for (int i = 0;i < train_for;i++)
  {
    correct = incorrect = 0;
    for (int j = 0;j < cycles;j++)
    {
      gate_and.reset_values();
      inputs[0] = gate_and.get_a();
      inputs[1] = gate_and.get_b();
      guess = p_and.guess(inputs, 2);
      error = gate_and.get_output() - guess;
      if (error == 0)
      {
        correct ++;
      }
      else
      {
        incorrect ++;
        p_and.train(error, inputs, 2);
      }
    }
  }

  cout << "\n\nAND PERCEPTRON\n\nCorrect: " << correct << "\nIncorrect: " << incorrect << endl;

  //Trainging gate_xor perceptron
  train_for = 1000;
  cycles = 100;
  float alt_inputs[2];
  for (int i = 0;i < train_for;i++)
  {
    correct = incorrect = 0;
    for (int j = 0;j < cycles;j++)
    {
      gate_or.reset_values();
      gate_and.set_values(gate_or.get_a(), gate_or.get_b());
      gate_xor.set_values_from_gates(gate_or.get_output(), gate_and.get_output());
      alt_inputs[0] = gate_or.get_a();
      alt_inputs[1] = gate_or.get_b();
      inputs[0] = p_or.guess(alt_inputs, 2);
      alt_inputs[0] = gate_and.get_a();
      alt_inputs[1] = gate_and.get_b();
      inputs[1] = p_and.guess(alt_inputs, 2);
      guess = p_xor.guess(inputs, 2);
      error = gate_xor.get_output() - guess;
      if (error == 0)
      {
        correct ++;
      }
      else
      {
        incorrect ++;
        p_xor.train(error, inputs, 2);
      }
    }
    //cout << "Weight 1: " << p_xor.get_weight(0) << "\tWeight 2: " << p_xor.get_weight(1) << endl;
  }

  cout << "\n\nXOR PERCEPTRON\n\nCorrect: " << correct << "\nIncorrect: " << incorrect << endl;
  cout << "Should be: " << gate_xor.get_output() << endl;
  cout << "Result: (" << gate_xor.get_a() << " || " << gate_xor.get_b() << ") && !(" << gate_xor.get_a() << " && " << gate_xor.get_b() << ") = " << guess << endl;

  return 0;
}