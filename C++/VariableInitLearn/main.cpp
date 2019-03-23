#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class People {
public:
    int id = -100;
    char *name;

    People(const char name[], int id) : id(id) {
        cout << "2 construct function call..." << endl;
        this->name = new char[32];
        strcpy(this->name, name);
//        this->id = id;
    }

    People() : id(-1) {
        cout << "0 construct function call..." << endl;
        this->name = new char[32];
//        this->id = -1;
    }

//    People(const People &people) : id(people.id) {
//        cout << "copy construct function call..." << endl;
//        this->name = new char[32];
//        strcpy(name, people.name);
//    }

    ~People() {
//        cout << "destructor..." << endl;
        delete[]name;
    }

//    People &operator=(const People &people) {
//        cout << "operator=(people) call..." << endl;
//        if (this == &people) {
//            return *this;
//        }
//
//        delete[] this->name;
//        this->name = new char[strlen(people.name) + 1];
//        strcpy(this->name, people.name);
//        this->id = people.id;
//        return *this;
//    }

    People &operator=(const char *const &name) {
        cout << "operator=(name) call..." << endl;

        delete[] this->name;
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        return *this;
    }
};

void InitLearn();

void show(const std::string &name, const People &people);

void PtrLearn();

int main() {
    People people = {"hzh", 23};
    People people1;
    People people2 = {};

//    PtrLearn();
//    InitLearn();


}

void PtrLearn() {
    const char *name = "huang";

    int a = 10, b = 30;
    const int c = 40;
    int const d = 50;

    // 指针常量
    int *const p = &a;
    // 常量指针
    int const *p1 = &a;
    const int *p2 = &a;

    cout << "p:" << *p << endl;

    *p = 20;

    cout << "p:" << *p << endl;
}

void show(const std::string &name, const People &people) {
    std::cout << name << "  :" << std::endl;
    std::cout << "id:{" << people.id << "}" << " " << "name:{" << people.name << "}" << std::endl;
}

void InitLearn() {
    std::vector<int> v;

    People people;
    std::cout << "People  :" << std::endl;
    std::cout << "id:{" << people.id << "}" << " " << "name:{" << people.name << "}" << std::endl;

    People people1();
    std::cout << "People2 :" << std::endl;
//  std::cout << "id:{" << people2.id << "}" << " " << "name:{" << people2.name << "}" << std::endl;

    People *people2;
    people2 = new People();
    std::cout << "People3 :" << std::endl;
    std::cout << "id:{" << people2->id << "}" << " " << "name:{" << people2->name << "}" << std::endl;
}