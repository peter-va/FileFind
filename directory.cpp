#include <iostream>
#include <fstream>
#include <cstring>
#include "directory.h"
#include "list.cpp"

using std::cout;
using std::endl;

File::File(const char *nm)
{
  name = new char[strlen(nm) + 1];
  strcpy(name, nm);
} //file constructor

const char* File::getName()
{
  return name;
} //file getname

File::~File()
{
  if (name)
    delete []name;
} //file deconstructor

bool File::find(const char *fin)
{
  if (!strcmp(name, fin))
  {
    cout << fin << endl;
    return true;
  } //print it

  return false;
} //file find

void File::insert(File &ins) {}//file insert

bool File::operator==(const File &rhs) const
{
  if (!strcmp(name, rhs.name))
  {
    return true;
  } //equals
  else // if not equals
    return false;
} //file operator==

bool File::operator<(const File &rhs) const
{
  if (strcmp(name, rhs.name) > 0)
  {
    return true;
  } //less than
  else //if not less than
    return false;
} //file operator<

bool File::operator>(const File &rhs) const
{
  if (strcmp(name, rhs.name) < 0)
  {
    return true;
  } //greater than
  else // if not greater than
    return false;
} //file operator>

Directory::Directory(const char *nm) : File(nm), files() {} //constructor

Directory::~Directory() {} //empty destructor

bool Directory::operator==(File &rhs) const
{
  if ((strncmp(name, rhs.getName(), strlen(rhs.getName())))
      && (name[strlen(rhs.getName())] == '/'))
  {
    return true;
  } // if equals to this point
  else // if not equals
    return false;
} //directory operator==

bool Directory::operator<(File &rhs) const
{
  if ((strcmp(name, rhs.getName())) > 0)
  {
    return true;
  } //less than
  else // if not less than
    return false;
} //directory operator<

bool Directory::operator>(File &rhs) const
{
  if ((strcmp(name, rhs.getName())) < 0)
  {
    return true;
  } //greater than
  else // if not greater than 
    return false;
} //directory operator>

bool Directory::find(const char *ins)
{
  if (!strcmp(name, ins))
  {
    files.print();
    return true;
  } //matches directory
  
  File* aaa = new File(ins);
  files.find(aaa);
  return true;
} //directory find

void Directory::insert(File &ins)
{
  if (strcmp(name, ins.getName()))
  {
    File* temp = &ins;
    files.insert(temp);
  } //check for insertion of self
} //directory insert
