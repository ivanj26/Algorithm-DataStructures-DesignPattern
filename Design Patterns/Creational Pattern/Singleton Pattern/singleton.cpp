class Singleton {
    static Singleton* instance;
    int someValue;
    Singleton(int val = 0) {
        someValue = val;
    }

    public:
        static Singleton* getInstance() {
            if (instance == nullptr) {
                instance = new Singleton();
            }

            return instance;
        }

        void setValue(int val) {
            someValue = val;
        }

        int getValue() const {
            return someValue;
        }
};

Singleton *Singleton::instance = 0;