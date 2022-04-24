#include <iostream>
#include <sqlite3.h>

using namespace std;

int main()
{
    // Pointer to SQLite connection
    sqlite3 *db;

    // Save the connection result
    int exit = 0;
    exit = sqlite3_open("example.db", &db);

    // Test if there was an error
    if (exit)
    {

        cout << "DB Open Error: " << sqlite3_errmsg(db) << endl;
    }
    else
    {

        cout << "Opened Database Successfully!" << endl;
    }

    // Close the connection
    sqlite3_close(db);

    return (0);
}