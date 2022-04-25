#include <iostream>
#include <memory>
#include <utility>

class Shape {
public:
  virtual void Display() = 0;
  virtual ~Shape() = default;
};

class Line : public Shape {
public:
  void Display() override {
    std::cout<<"line! \n"; }
};


// 一个持有component指针的decorator, 它与提供Component一致的接口
class Decorator : public Shape {
public:
  Decorator (std::unique_ptr<Shape> p):shape_{std::move(p)} { }
  
  void Display() override {shape_->Display();}
  
private:
  std::unique_ptr<Shape> shape_;
};

class ColorDecorator : public Decorator {
public:
  using Decorator::Decorator;
  
  void Display() override {
    std::cout<<"red! \n";
    Decorator::Display();
  }
};

int main() {
  std::unique_ptr color_Decorator = std::make_unique<ColorDecorator>(std::make_unique<Line>());
  color_Decorator->Display();
}
