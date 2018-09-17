#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <iostream>
#include <fstream>
#include <cstring>
#include "list.h"

class File
{
protected:
  char *name;
public:
  File(const char* nm);
  const char* getName();
  virtual ~File();
  virtual bool find(const char *fin);
  virtual void insert(File &ins);
  virtual bool operator ==(const File &rhs) const;
  virtual bool operator <(const File &rhs) const;
  virtual bool operator >(const File &rhs) const;
}; // File class

class Directory : public File
{
  List<File*> files;
public:
  Directory(const char *nm);
  ~Directory();
  bool find(const char *ins);
  using File::insert;
  void insert(File &ins);
  bool operator ==(File &rhs) const;
  bool operator <(File &rhs) const;
  bool operator >(File &rhs) const;
}; // Directory class


#endif //DIRECTORY_H
