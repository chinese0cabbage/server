//
// Created by johnjun on 2021/3/5.
//

#ifndef SERVER_MYSQL_CONNECT_H


#include "mysql_connection.h"
#include "mysql_driver.h"
#include "cppconn/driver.h"
#include "cppconn/metadata.h"
#define SERVER_MYSQL_CONNECT_H

using namespace sql;

int execute(){//sudo apt-get install libmysqlcppconn-dev
    Driver *driver = get_driver_instance();
    Connection *connection = driver->connect("tcp://127.0.0.1:3306", "root", "yy19960510");
    std::cout << connection->getAutoCommit() << std::endl;
    std::cout<< connection->getMetaData()->getMaxConnections()<<std::endl;
    return 1;
}

#endif //SERVER_MYSQL_CONNECT_H
