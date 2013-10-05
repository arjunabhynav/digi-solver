#ifndef GATE_H
#define GATE_H

class Circuit;

class Gates
{
  public:

  std::string type;

  int inputx;
  int inputy;

  int output;

  Gates();

  Gates(std::vector<std::string> );

  void evaluate(Circuit* );
  
  void display();

};

#endif
