
#include "stdio.h"
#include "stdlib.h"

#include <vector>
#include <iostream>

namespace Joanna
{
template <class T> class Queue
{
  public:

    void push(T item)
    {
      data.push_back(item);
    }
    
    T pop()
    {
      if(!empty())
      {
        T returnValue = data[0];
        data.erase(data.begin());
        return returnValue;
      }
      else 
      {
        std::cout << "Wtf is you doing\n";
        exit(1);
      }
    }

    bool empty()
    {
      return data.size() == 0;
    }

  private:

    std::vector<T> data;
};

template <class T> class Stack
{
  public:

  void push(T item)
  {
    data.push_back(item);
  }
  
  T pop()
  {
    if (!empty()) 
    {
    T returnValue = data[data.size()-1];
    data.pop_back();
    return returnValue;
    } else {
      std::cout << "stack is empty\n";
      exit(1);
    }
  }

  bool empty()
  {
    return data.size() == 0;
  }

  private:
  std::vector<T> data;
};
}

class Person
{
  public:
  std::string name;
  int id;
  int id2;
  int DateofBirth;

  void print()
  {
    printf("%s %d %d %d\n", name.c_str(), id, id2, DateofBirth);
  }
};



int main(int argumentCount, char** arguments)
{
  using namespace std;
  using namespace Joanna;


  Stack<Person> q;

  q.push({ "chris", 0, 32935908, 121287});
  q.push({"sooyeon", 1, 23235, 121289});
  q.push({"choonsik", 2, 63643, 121225});

  while(!q.empty())
  {
    Person d = q.pop();
    d.print();
  }
}
