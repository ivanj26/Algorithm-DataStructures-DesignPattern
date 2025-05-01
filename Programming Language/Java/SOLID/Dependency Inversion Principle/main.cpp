// DIP: High level module should not be dependent on low-level module (instantiation of the other class).
// Instead, we can use an abstraction

// Bad way to implement the DIP Princple
class MySQLConnector {
    public:
        bool connect();
        void query();
};

class Repository {
    private:
        MySQLConnector connector;
    public:
        Repository(MySQLConnector _connector) {
            this->connector = connector;
        }
};

// Good way to implement the DIP Principle
class DBConnector {
    public:
        virtual bool connect() = 0;
        virtual void query() = 0;
};

class MySQLConnector {
    public:
        virtual bool connect() = 0;
        virtual void query() = 0;
};

class PostgresConnector {
    public:
        virtual bool connect() = 0;
        virtual void query() = 0;
};

class Repository {
    private:
        DBConnector connector;
    public:
        Repository(DBConnector _connector) {
            this->connector = connector;
        }
};