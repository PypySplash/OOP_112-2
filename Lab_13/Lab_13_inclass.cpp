#include <iostream>



class Strategy {
public:
    virtual void execute() const = 0;
    virtual ~Strategy() {}
};

class ConcreteStrategyA : public Strategy {
public:
    void execute() const override {
        std::cout << "Executing Strategy A" << std::endl;
    }
};

class ConcreteStrategyB : public Strategy {
public:
    void execute() const override {
        std::cout << "Executing Strategy B" << std::endl;
}
};

class Context {
private:
    Strategy* strategy;
public:
    Context(Strategy* strat = nullptr) : strategy(strat) {}
    void setStrategy(Strategy* strat) {
        strategy = strat;
    }
    void performTask() const {
        if (strategy) {
            strategy->execute();
        } else {
            std::cout << "Strategy not set" << std::endl;
        }
    }
};



int main() {
    ConcreteStrategyA strategyA;
    ConcreteStrategyB strategyB;
    Context context(&strategyA);
    context.performTask(); // Outputs: Executing Strategy A
    context.setStrategy(&strategyB);
    context.performTask(); // Outputs: Executing Strategy B
    context.setStrategy(nullptr);
    context.performTask(); // Outputs: Strategy not set
    return 0;
}
