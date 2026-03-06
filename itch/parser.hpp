#include <sys/mman.h>

class Reader{

    Reader() = delete;              // must provide filename
    Reader(char const* filename);
    void readItch();
    void decode();
    ~Reader(){
        
    }

    private:
    const char* filename_;
}


class Decoder{

    Decoder
}

class OrderBook{

}