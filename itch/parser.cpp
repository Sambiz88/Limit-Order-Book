#include "parser.hpp"

Reader::Reader(char const* filename){

    filename_ = filename;

}


void Reader::readItch(){

    int fd = open(filename_, O_RDONLY);

    // gets file stats
    struct stat st;
    fstat(fd, &st);

    // buf points to top byte of itch file. used for munmap
    const uint8_t* buf = static_cast<const uint8_t*>(
        mmap(nullptr, file_size, PROT_READ, MAP_PRIVATE, fd, 0);
    );
    close(fd);

    const uint8_t* cur = buf;               // cur starts at byte 0
    const uint8_t* end = buf+st.st_size;    
    
    while(cur < end){
        // ntohs (network to host short) converts a 16-bit unsigned int from big-endian to little-endian
        // is very fast and is O(1)
        uint16_t len = ntohs(*(uint16_t*)cur); 
        cur +=2;
        char type = cur[0];

        cur+=len;
    }

    munmap((void*)buf, st.st_size);

}

void Reader::decode(const uint8_t* cur, uint16_t len){
    AddOrder msg;

    uint16_t u16;
    uint32_t u32;
    uint64_t u64;

    memcpy(&u16, cur+1, 2);
    msg.stockLocate = ntohs(u16);
}

struct AddOrder{
    uint16_t stockLocate;
    uint16_t trackingNumber;
    uint64_t timestamp;
    uint64_t orderRef;
    char side;
    uint32_t shares;
    char stock[9];
    uint32_t price;
}