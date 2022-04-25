#include <memory>
#include <iostream>
#include <tuple>
#include <utility>
#include <type_traits>

class Shape {
public:
  virtual void Display() = 0;
  virtual ~Shape() = default;
};

template<typename ...T>
class Line : public Shape, public T... {
public:
  void Display() override {
    std::apply(
    [](auto&&... x) { (x.Display(),...);},
    std::forward_as_tuple(T()...)
  );
  std::cout<<"line! \n";
  }
};

class ColorDecorator {
  public:
  void Display() {
    std::cout<<"red ";
  }
};

class WeightDecorator{
  public:
  void Display() {
    std::cout<<"bold ";
  }
};


int main() {
  Line line1;
  Line<ColorDecorator> line2;
  Line<WeightDecorator> line3;
  Line<WeightDecorator,ColorDecorator> line4;
  
  line1.Display();
  line2.Display();
  line3.Display();
  line4.Display();
}