#include <iostream>
#include <cstring>
#include <algorithm>


class ResourceOwner {

public:
    explicit ResourceOwner(const char res[]) {
        printf("construct %s\n", res);

        this->theResource = new char[1024];
        std::strcpy(this->theResource, res);
    }

    ResourceOwner(const ResourceOwner &other) {
        printf("copy %s\n", other.theResource);

        this->theResource = new char[1024];
        std::strcpy(this->theResource, other.theResource);
    }

    ResourceOwner &operator=(const ResourceOwner &other) {
        printf("assign %s\n", other.theResource);

        std::strcpy(this->theResource, other.theResource);

        return *this;
    }

//    ResourceOwner &operator=(const char res[]) {
//        printf("assign %s\n", res);
//
//        std::strcpy(this->theResource, res);
//
//        return *this;
//    }

    ~ResourceOwner() {
        if (theResource) {
            printf("destructor %s\n", this->theResource);
            delete[]theResource;
        }
    }

private:
    char *theResource;
};

void testCopy() {
    // case 1
    printf("=====start testCopy()=====\n");
    ResourceOwner res1("res1");
    ResourceOwner res2("res2");
    res2 = "tmp";
    //copy res1
    printf("=====destructors for stack vars, ignore=====\n");
}

void testAssign() {
    // case 2
    printf("=====start testAssign()=====\n");
    ResourceOwner res1("res1");
    ResourceOwner res2("res2");
    res2 = res1;
    //copy res1, assign res1, destrctor res2
    printf("=====destructors for stack vars, ignore=====\n");
}

void testRValue() {
    // case 3
    printf("=====start testRValue()=====\n");
    ResourceOwner res2("res2");
    res2 = ResourceOwner("res1");
    //copy res1, assign res1, destructor res2, destructor res1
    printf("=====destructors for stack vars, ignore=====\n");
}

int main() {
    testCopy();
//    testAssign();
//    testRValue();
}