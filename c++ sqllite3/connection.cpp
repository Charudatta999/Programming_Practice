// main.cpp
#include <sqlite3.h>
#include <iostream>

int main()
{
    std::cout << "Sqlite version: " << sqlite3_libversion() << std::endl;

    sqlite3 *mydb;
    std::cout << sqlite3_open("test.db", &mydb) << std::endl;
    std::cout << "Database file:" << mydb << std::endl;
    std::cout << sqlite3_close(mydb);

    return 0;
}