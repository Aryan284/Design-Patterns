using namespace std;
#include <string>
#include <vector>
#include <iostream>

class Member {
 public:
  virtual int cost() const = 0;
};

class LifetimeSubscription : public Member {
 public:
  int cost() const override {
    return 3400;
  }
};

class AbstractDecorator : public Member {

 protected:
  Member* mem;

 public:
  AbstractDecorator(Member* m) : mem(m) {
  }

  int cost() const override {
    return this->mem->cost();
  }
};


class Assignment : public AbstractDecorator {

 public:
  Assignment(Member* m) : AbstractDecorator(m) {
  }
  int cost() const override {
    return 300 + AbstractDecorator::cost();
  }
};

class DoubtSession : public AbstractDecorator {
 public:
  DoubtSession(Member* m) : AbstractDecorator(m) {
  }

  int cost() const override {
    return 500 + AbstractDecorator::cost();
  }
};

class JobAssistance : public AbstractDecorator {
 public:
  JobAssistance(Member* m) : AbstractDecorator(m) {
  }

  int cost() const override {
    return 900 + AbstractDecorator::cost();
  }
};


void ClientCode(Member* m) {
  // ...
  std::cout << "Course Cost: " << m->cost();
  // ...
}

int main() {

  Member* lfs = new LifetimeSubscription;
  std::cout << "Client: LifetimeSubscription\n";
  ClientCode(lfs);
  std::cout << "\n\n";
  Member* afs = new Assignment(lfs);
  Member* dfs = new DoubtSession(afs);
  ClientCode(dfs);
  std::cout << "\n";

  return 0;
}