#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>

#include "helper.h"
#include "circuit.h"

Circuit::Circuit()
{
  this->gateCount = this->portCount = 0;
  this->inputPortCount = this->outputPortCount = 0;
  for(int i = 0; i < 250; i++)
    this->evalFlag[i] = 0;
}

Circuit::Circuit(std::string circuitFile, std::string inputValues)
{
  this->circuitFile = circuitFile;
  this->inputValues = inputValues;
  this->gateCount = this->portCount = 0;
  this->inputPortCount = this-> outputPortCount = 0;
  this->readCircuitAndCount();
  for(int i = 0; i < this->gateCount; i++)
    this->evalFlag[i] = 0;
  this->createGatesFromCircuit(this->gate);
  this->assignValuesToInputPorts(this->inputValues);
  this->evaluateGates();
}

void Circuit::readCircuitAndCount()
{
  std::fstream file;
  std::vector<std::string> v;
  file.open(this->circuitFile.c_str());
  std::string line;
  int no;
  while(getline(file, line))
  {
    v = split(line, ' ');
    no = atoi(v[v.size() - 1].c_str());
    this->portCount = (no > this->portCount) ? no : this->portCount;
    this->gateCount++;
    v.clear();
  }
  this->gateCount = this->gateCount - 2;
  file.close();
}

void Circuit::createGatesFromCircuit(Gates g[])
{
  std::fstream file;
  std::vector<std::string> v;
  file.open(this->circuitFile.c_str());
  std::string line;
  int i = 0;
  while(i < this->gateCount)
  {
    getline(file, line);
    v = split(line, ' ');
    g[i] = Gates(v);
    v.clear();
    i++;
  }
  getline(file, line);
  std::string::iterator new_end = unique(line.begin(), line.end(), bothAreSpaces);
  line.erase(new_end, line.end());
  v = split(line, ' ');
  this->inputPortCount = v.size() - 2;
  for(i = 0; i < this->inputPortCount; i++)
    this->inputPorts[i] = atoi(v[i+1].c_str());
  v.clear();
  getline(file, line);
  new_end = unique(line.begin(), line.end(), bothAreSpaces);
  line.erase(new_end, line.end());
  v = split(line, ' ');
  this->outputPortCount = v.size() - 2;
  for(i = 0; i < this->outputPortCount; i++)
    this->outputPorts[i] = atoi(v[i+1].c_str());
  v.clear();
  file.close();
}

void Circuit::assignValuesToInputPorts(std::string s)
{
  int l = s.length();
  if(l != this->inputPortCount)
  {
    std::cout<<"Incorrect number of inputs!";
    exit(1);
  }
  int i;
  for(i = 0; i < this->inputPortCount; i++)
  {   
    this->evalFlag[this->inputPorts[i] - 1] = 1;
    this->value[this->inputPorts[i] - 1] = s.at(i) - '0';
  }
}

void Circuit::evaluateGates()
{
  int i;
  for(i = 0; this->isAllEvaluated(); i = ((i + 1) % this->gateCount))
    this->gate[i].evaluate(this);
}

void Circuit::displayFinalInputValues()
{
  int i;
  std::cout<<"\nFinal Input Ports\n";
  for(i = 0; i < this->inputPortCount; i++)
    std::cout<<this->inputPorts[i]<<" -> "<<this->value[this->inputPorts[i] - 1]<<"\n";
}

void Circuit::displayFinalOutputValues()
{
  int i;
  std::cout<<"\nFinal Output Ports\n";
  for(i = 0; i < this->outputPortCount; i++)
    std::cout<<this->outputPorts[i]<<" -> "<<this->value[this->outputPorts[i] - 1]<<"\n";
}

bool Circuit::isAllEvaluated()
{
  int i;
  for(i = 0; i < this->portCount; i++)
  {
    if(this->evalFlag[i] == 0)
      return true;
  }
  return false;
}

void Circuit::displayCircuitDetails()
{
  int i;
  this->displayFinalInputValues();
  std::cout<<"Gate Count = "<<this->gateCount<<"\n";
  std::cout<<"Port Count = "<<this->portCount<<"\n";
  std::cout<<"Input Port Count = "<<this->inputPortCount<<"\n";
  std::cout<<"Output Port Count = "<<this->outputPortCount<<"\n";
  std::cout<<"Input Ports: ";
  for(i = 0; i < this->inputPortCount; i++)
    std::cout<<this->inputPorts[i]<<" ";
  std::cout<<"\nOutput Ports: ";
  for(i = 0; i < this->outputPortCount; i++)
    std::cout<<this->outputPorts[i]<<" ";
}
