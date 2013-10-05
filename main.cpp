/**
 * Digital Circuit Solver
 * Author: Arjun Abhynav
 * License: GPLv2
 */

#include <iostream>
#include <string>
#include <vector>

#include "circuit.h"

#define BINARY_INPUT "1100110"
#define CIRCUIT_FILE "circuits/A.txt"

int main()
{
  int i;
  Circuit c = Circuit(CIRCUIT_FILE, BINARY_INPUT);
  c.displayFinalOutputValues();
  return 0;
}
