#include<string>

#include "mysql_connection.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

using std::string;

class Session(){
    private:
        string loc, db, name, pass;
        sql::Driver *driver;
        sql::Connection *con;
        sql::ResultSet *res;
        
    public:
        Session();
        ~Session();
        
        void connect(string, string, string, string);
        void runQuery(string);   
}