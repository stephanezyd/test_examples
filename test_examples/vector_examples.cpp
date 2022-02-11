//
// Created by stephane on 2/11/22.
//
/*
/* @Description:
/* @Author: stephane
/* @Data: 2021-08-26 3:18 PM
*/
#include "iostream"
#include "math.h"
#include "vector"
#include "boost/timer.hpp"
#include "thread"
#include "assert.h"
#include "jsoncpp/json/json.h"
#include "fstream"
#include "chrono"
#include "ctime"


#define my_assert(expr,...) \
  static_cast<bool>(expr) ?     \
  void(0) :                     \
  [](){               \
    std::cout<< __FILE__ << ' '<< __LINE__  << ' ' << #__VA_ARGS__ << std::endl; \
    abort();                    \
    }();

class A{
 public:
  A(){
    std::cout<<">>> construction: "<<std::endl;
  }
  A(const int v_):v(v_){
    std::cout<<">>> construction: "<<v<<std::endl;
  }
  ~A(){
    std::cout<<"<<< destruction: "<<v<<std::endl;
  };

  A(const A& alloc):v(alloc.v){
    std::cout<<"---> copy construction: "<<v<<std::endl;
  }
  A(A && alloc):v(alloc.v){
    std::cout<<"---> move construction: "<<v<<std::endl;
  }

  int getV(){return v;}
  void setV(const int v_){v = v_;}

 private:
  int v;

};


void test_fun_ptr( int* it,  std::vector<int> vec){
  it = &vec.front();
}

void test_fun_it(std::vector<int>::const_iterator it, const std::vector<int> vec){
  it = vec.begin();
}

int main(){

  std::chrono::time_point<std::chrono::system_clock> start_1, end_1, start_2, end_2;

  std::vector<A> buffer;

//  buffer.resize(3);
//  buffer[0].setV( 1);
//  buffer[1].setV( 2);
//  buffer[2].setV( 3);
//  std::cout<<buffer[2].getV()<<std::endl;

//  A a1(1),a2(2),a3(3);

//  std::cout<<"\n------ start to push_back ------\n"<<std::endl;
//  buffer.push_back(a1);
//  buffer.push_back(1);
//  buffer.emplace_back(a1);
//  buffer.emplace_back(1);
//  std::cout<<"\n------ finish push_back a1------ capacity: "<<buffer.capacity()<<"\n"<<std::endl;
//  buffer.push_back(a2);
//  buffer.push_back(2);
//  buffer.emplace_back(a2);
//  buffer.emplace_back(2);
//  std::cout<<"\n------ finish push_back a2 ----- capacity: "<<buffer.capacity()<<"\n"<<std::endl;
//  buffer.push_back(a3);
//  buffer.push_back(3);
//  buffer.emplace_back(a3);
//  buffer.emplace_back(3);
//  std::cout<<"\n------ finish push_back a3 ------ capacity: "<<buffer.capacity()<<"\n"<<std::endl;
  //  buffer.push_back(a4);
//  buffer.push_back(4);
//  buffer.emplace_back(a4);
//  buffer.emplace_back(4);

//  std::cout<<"\n------ finish push_back a4 ------ capacity: "<<buffer.capacity()<<"\n"<<std::endl;

  for(int i = 0 ; i < 4; i++){
    A a(i+1);
    buffer.push_back(a);
    std::cout<<"\n------ finish push_back a"<<std::to_string(i+1)<<" ------ capacity: "<<buffer.capacity()<<"\n"<<std::endl;
  }
//  for(int i = 0 ; i < 4; i++){
//    buffer.pop_back();
//    std::cout<<"\n------ finish pop_back a"<<std::to_string(i+1)<<" ------ capacity: "<<buffer.capacity()<<"\n"<<std::endl;
//  }

  std::cout<<"\n------- clear\n"<<std::endl;
  buffer.clear();
  std::cout<<"\n------- capacity: "<<buffer.capacity()<<"\n"<<std::endl;

  std::cout<<"\n------- resize(0)\n"<<std::endl;
  buffer.resize(0);
  std::cout<<"\n------- capacity: "<<buffer.capacity()<<"\n"<<std::endl;

  std::cout<<"\n------- reserve(0)\n"<<std::endl;
  buffer.reserve(0);
  std::cout<<"\n------- capacity: "<<buffer.capacity()<<"\n"<<std::endl;

  std::cout<<"Finish test"<<std::endl;

  return 0;
}
