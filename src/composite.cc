#include <algorithm>
#include <iostream>
#include <memory>
#include <utility>

class Shape {
public:
  virtual void Display() = 0;
  virtual void Append(const std::shared_ptr<Shape> &) {}
  virtual void Remove(const std::shared_ptr<Shape> &) {}

  virtual std::shared_ptr<Shape> Child(std::size_t) { return nullptr; }

  virtual ~Shape() = default;
};

// line object, override display with other mem_fn default impl
class Line : public Shape {
public:
  void Display() override { std::cout << 1; }
};

// rect object, override display with other mem_fn default impl
class Rect : public Shape {
public:
  void Display() override { std::cout << 2; }
};

// compose some singleton obj
class Picture : public Shape {
  public:
  void Display() override {
    for(auto&& x:shapes_) {
      x->Display();
    }
  }
  
  void Append(const std::shared_ptr<Shape>& s) override {
    shapes_.emplace_back(s);
  }
  
  void Remove(const std::shared_ptr<Shape>& s) override {
    if(const auto it = std::find(shapes_.begin(),shapes_.end(),s);
      it!=shapes_.end()) {
      shapes_.erase(it);
    }
  }
  
  std::shared_ptr<Shape> Child(std::size_t n) override { return shapes_.at(n);}
  
  private:
  std::vector<std::shared_ptr<Shape>> shapes_;
};


int main() {
  std::unique_ptr<Shape> picture = std::make_unique<Picture>();
  const auto line = std::make_shared<Line>();
  const auto rect = std::make_shared<Rect>();
  
  picture->Append(line);
  picture->Append(rect);
  picture->Display();
  
  picture->Remove(line);
  picture->Display();
}