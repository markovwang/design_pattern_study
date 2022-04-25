#include <memory>
#include <cstdio>
class Door {
public:
  virtual ~Door() = default;
};

class Window {
public:
  virtual ~Window() = default;
};

class House {
public:
  virtual void set_door(const Door &) { printf("set door!\n");}
  virtual void set_window(const Window &) {}
  virtual ~House() = default;
};

class HouseFactory {
public:
  virtual std::unique_ptr<Door> make_door() { return std::make_unique<Door>(); }

  virtual std::unique_ptr<Window> make_window() {
    return std::make_unique<Window>();
  }

  virtual std::unique_ptr<House> make_house() {
    return std::make_unique<House>();
  }

  virtual ~HouseFactory() = default;
};

class Life {
public:
  std::unique_ptr<House> create_house(HouseFactory &factory) {
    auto door = factory.make_door();
    auto windwow = factory.make_window();
    auto house = factory.make_house();
    house->set_door(*door);
    house->set_window(*windwow);
    return house;
  }
};

class WoodDoor : public Door {};
class WoodWindow : public Window {};
class WoodHouse : public House {};

class WoodHouseFactory : public HouseFactory {
public:
  std::unique_ptr<Door> make_door() override {
    return std::make_unique<WoodDoor>();
  }
};

int main() {
  Life life;
  WoodHouseFactory factory;
  std::unique_ptr<House> house = life.create_house(factory);
}