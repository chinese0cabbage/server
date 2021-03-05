#include <iostream>
#include "rttr/detail/base/version.h"
#include "json_serialization/from_json.h"
#include "mysql_connect.h"

int main() {
    std::cout<<RTTR_VERSION;
    std::cout << "Hello, World!" << std::endl;
    execute();
    return 0;
}
