#ifndef PERCEPTRON_H
#define PERCEPTRON_H

#include "xor.h"

class Perceptron
{
  float weights[2];
  float learn_rate = 0.01;
  float bias = 0.01;
  
  public:
    Perceptron()
    {
      for (int i = 0;i < 2;i++)
      {
        weights[i] = rand() % 2;
      }
    }

    // Activation function
    int activation(float n) const
    {
      if ((n - 1.5) < 0)
        return 0;
      return 1;
    }

    // Trains the perceptron
    void train(float error, float inputs[], int n)
    {
      for (int i = 0;i < n;i++)
      {
        weights[i] += error * (inputs[i] + bias) * learn_rate;
      }
    }

    float get_weight(const int n) const
    {
      return weights[n];
    }

    int guess(float inputs[], int n) const
    {
      float sum = 0;
      for (int i = 0;i < n;i++)
      {
        sum += weights[i] * inputs[i];
      }

      // Call and return result of activation function
      return activation(sum);
    }
};

#endif
