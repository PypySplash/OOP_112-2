#include <iostream>
#include <vector>
using namespace std;



class Person 
{
private:
    string name;
    int age;
public:
    Person(string n, int a) : name(n), age(a) {}
    string getName() {return name;}
    int getAge() {return age;}
};



class PersonVector 
{
private:
    vector<Person> persons;
public:
    void addPersons() 
    {
        int n;
        cin >> n;
        string name;
        int age;
        for (int i = 0; i < n; i++)
        {
            cin >> name >> age;
            persons.push_back(Person(name, age));
        }
    }
    void displayPersons()
    {
        for (int i = 0; i < persons.size(); i++)
        {
            cout << persons[i].getName() << ": " << persons[i].getAge() << endl;
        }
    }
};



int main(){
PersonVector pv;
pv.addPersons();
pv.displayPersons();
return 0;
}
