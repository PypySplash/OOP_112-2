#include <iostream>
using namespace std;
#include <vector>



class Animal
{
protected:
    string name;
public:
    Animal(string n) : name(n) {}
    virtual void sound() {}
};



class Cat : public Animal
{
public:
    Cat(string name) : Animal(name) {}
    void sound() override
    {
        cout << "The cat meows." << endl;
    }
};



class Dog : public Animal
{
public:
    Dog(string name) : Animal(name) {}
    void sound() override
    {
        cout << "The dog barks." << endl;
    }
};



class Zoo
{
private:
    vector<Animal*> animalPtrArr;
public:
    void addAnimal(Animal* animal)
    {
        animalPtrArr.push_back(animal);
    }
    void makeAllSounds()
    {
        for (Animal* animal : animalPtrArr)
        {
            animal->sound();
        }
    }
};



int main() {
Zoo zoo;
Cat cat("Oscar");
Dog dog("Buddy");
zoo.addAnimal(&cat);
zoo.addAnimal(&dog);
zoo.makeAllSounds(); // output comes from this call
return 0;
}
