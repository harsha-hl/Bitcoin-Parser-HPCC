#ifndef BLOCKHEADER_HPP
#define BLOCKHEADER_HPP

#include <stdint.h>
#include <fstream>
#include "picosha2.h"
#include "Blob.hpp"

class BlockHeader {
    private:
    uint32_t version;
    uint256_t prevBlock;
    uint256_t merkleRoot;
    uint32_t timestamp, bits;
    uint64_t nonce;
    
    uint256_t hash;
    
public:
    BlockHeader(std::istream &input);
    BlockHeader();
    
    void init(std::istream &input);
    
    int32_t getVersion() const;
    uint256_t getPreviousBlock();
    uint256_t getMerkleRoot();
    int32_t getTimestamp() const;
    int32_t getBits() const;
    uint64_t getNonce() const;
    
    uint256_t getHash() const;
    std::string getHashStr() const;
    std::string getHashStrReverse() const;

    
protected:
    void calcHash();
};

#endif
