#ifndef CIRCUIT_H
#define CIRCUIT_H

#include "gate.h"

class Circuit
{
  private:
  std::string circuitFile;
  std::string inputValues;

  int portCount;
  int gateCount;

  int inputPortCount;
  int outputPortCount;

  int inputPorts[250];
  int outputPorts[250];

  int value[250];
  int evalFlag[250];

  friend class Gates;
  Gates gate[250];

  public:
  Circuit();

  Circuit(std::string circuitFile, std::string inputValues);

  private:
  void readCircuitAndCount();

  void createGatesFromCircuit(Gates* );

  void assignValuesToInputPorts(std::string );

  void evaluateGates();

  public:
  bool isAllEvaluated();

  void displayFinalInputValues();
  void displayFinalOutputValues();

  void displayCircuitDetails();

};

#endif
