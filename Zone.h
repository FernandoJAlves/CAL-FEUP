#ifndef ZONE_H_
#define ZONE_H_

#include <string>

class Zone{
private:
  std::string name;
  double x,y;
  bool acessable = true;
  int limit;
public:
  Zone();
  Zone(std::string name, double x, double y, int limit);
  Zone(std::string name, double x, double y, int limit, bool acessable);
  double getX();
  double getY();
  std::string getName();
  bool isAcessable();
  int getLimit();
  void setAcess(bool acess);
};


#endif
