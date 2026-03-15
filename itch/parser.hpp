#include <sys/mman.h>

#DEFINE SESSION_LENGTH 10
class Reader{

    Reader() = delete;              // must provide filename
    Reader(char const* filename);
    void readItch();
    void decode();
    ~Reader(){
        
    }

    private:
    const char* filename_;
};