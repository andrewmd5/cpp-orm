
Session::Session(){
    this->driver = get_driver_instance();
}

Session::~Session(){
    delete this->con;
}

void Session::connect(string loc, string db, string name, string pass){
    this->loc = loc;
    this->db = db;
    this->name = name;
    this->pass = pass;
    
    try{
        this->con = this->driver->connect(loc, name, pass);
        this->con->setSchema(db);
    } catch(sql::SQLException &e) {
      //this should go to a debug file instead of stdout
      cout << "# ERR: SQLException in " << __FILE__;
      cout << "(" << __FUNCTION__ << ") on line " »
         << __LINE__ << endl;
      cout << "# ERR: " << e.what();
      cout << " (MySQL error code: " << e.getErrorCode();
      cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
}

void Session::runQuery(string query){
    try {
        sql::Statement *stmt;
        
        stmt = this->con->createStatement();
        this->res = stmt->executeQuery(query);
        
        //delete res
        //delete stmt;
        
    } catch (sql::SQLException &e) {
      //this should go to a debug file instead of stdout
      cout << "# ERR: SQLException in " << __FILE__;
      cout << "(" << __FUNCTION__ << ") on line " »
         << __LINE__ << endl;
      cout << "# ERR: " << e.what();
      cout << " (MySQL error code: " << e.getErrorCode();
      cout << ", SQLState: " << e.getSQLState() << " )" << endl;    
    }
}