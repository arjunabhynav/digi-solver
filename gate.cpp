#include <iostream>
#include <string>
#include <vector>

#include "circuit.h"
#include "gate.h"

Gates::Gates()
{

}

Gates::Gates(std::vector<std::string> v)
{
  if(v.size() == 3)
  {
    type = v[0];
    inputx = atoi(v[1].c_str());
    inputy = 0;
    output = atoi(v[2].c_str());
  }
  else if(v.size() == 4)
  {
    type = v[0];
    inputx = atoi(v[1].c_str());
    inputy = atoi(v[2].c_str());
    output = atoi(v[3].c_str());
  }
}

void Gates::evaluate(Circuit* c)
{
  if(c->evalFlag[output - 1])
    return;
  if(type == "AND")
  {
    if(c->evalFlag[inputx - 1] && c->evalFlag[inputy - 1])
    {
      c->value[output - 1] = (c->value[inputx - 1] && c->value[inputy - 1]);
      c->evalFlag[output - 1] = 1;
    }
  }
  else if(type == "OR")
  {
    if(c->evalFlag[inputx - 1] && c->evalFlag[inputy - 1])
    {
      c->value[output - 1] = (c->value[inputx - 1] || c->value[inputy - 1]);
      c->evalFlag[output - 1] = 1;
    }
  }
  else if(type == "NAND")
  {
    if(c->evalFlag[inputx - 1] && c->evalFlag[inputy - 1])
    {
      c->value[output - 1] = (!(c->value[inputx - 1])  || !(c->value[inputy - 1]));
      c->evalFlag[output - 1] = 1;
    }
  }
  else if(type == "NOR")
  {
    if(c->evalFlag[inputx - 1] && c->evalFlag[inputy - 1])
    {
      c->value[output - 1] = (!(c->value[inputx - 1] && c->value[inputy - 1]));
      c->evalFlag[output - 1] = 1;
    }
  }
  else if(type == "INV")
  {
    if(c->evalFlag[inputx - 1])
    {
      c->value[output - 1] = !(c->value[inputx - 1]);
      c->evalFlag[output - 1] = 1;
    }
  }
  else if(type == "BUF")
  {
    if(c->evalFlag[inputx - 1])
    {
      c->value[output - 1] = c->value[inputx - 1];
      c->evalFlag[output - 1] = 1;
    }
  }
}

void Gates::display()
{
  std::cout<<type<<" "<<inputx<<" "<<inputy<<" "<<output<<"\n";
}
