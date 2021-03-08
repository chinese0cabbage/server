#include <iostream>
#include "rttr/registration"
#include "json_serialization/to_json.cpp"

struct test {
    std::string name;
    int age;

    test(const std::string &name, int age) : name(name), age(age) {}

RTTR_ENABLE()
};

RTTR_REGISTRATION {
    rttr::registration::class_<test>("test")
            .property("name", &test::name)
            .property("age", &test::age);
};

int main() {
    test t("wwww", 1);
    std::cout << io::to_json(t) << "\n";
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
