#include <iostream>
#include <vector>
#include "picosha2.h"

#include "Helpers.hpp"
#include "Input.hpp"
#include "Output.hpp"
#include "Transaction.hpp"
#include "BlockHeader.hpp"
#include "Block.hpp"
using namespace std;

int main(int argc, char ** argv) {
    if (argc < 2) {
        std::cout << "Command: " << argv[0] << " FILENAME" << std::endl;
        return 0;
    }
    

    std::ifstream input(argv[1], std::ios::binary);
    
    uint32_t counter = 0;
    
    std::vector<Block> blocks;
    
    while (!input.eof()) {
        Block block(input);
        
        if (!input.fail()) {
            /*std::cout << block.getHeader().getHash() << std::endl;
            std::cout << std::dec << "Size: " << block.getSize() << std::endl;
            std::cout << "Output Satoshi: " << std::dec << block.getOutputsValue() << " in " << block.getTransactionCounter() << " transactions. " << std::endl;
            std::cout << "MR: " << std::dec << (int)(*block.getHeader().getMerkleRoot()) << std::endl;
            std::cout << input.tellg() << std::endl << std::endl;*/
            
            blocks.push_back(block);
            
            counter++;
        }
    }
    
    input.close();
    
    std::cout << std::dec << counter << " blocks" << std::endl;
    
    int blockNum = 0;
    
    while (true) {
        std::cout << "Pick one block: ";
        
        std::cin >> blockNum;
        if (blockNum < 0) break;
        
        Block block = blocks[blockNum];
        std::cout << "BLOCK " << blockNum << std::endl;
        std::cout << "Magic Number: " << std::hex << block.getMagicNumber() << std::endl;
        std::cout << std::dec << "Size: " << block.getSize() << std::endl;
        std::cout << "Version: " << block.getHeader().getVersion() << std::endl;
        cout<< "Merkle Root: " << block.getHeader().getMerkleRoot().getHexStringReverse()<<endl;
        std::cout << "Previous Block: " << block.getHeader().getPreviousBlock().getHexStringReverse() << std::endl;
		time_t t = 0;
		t += block.getHeader().getTimestamp();
		std::cout<<std::dec<<"Timestamp : "<<asctime(localtime(&t));

        std::cout << "Bits: " << block.getHeader().getBits() << std::endl;
        std::cout << "Nonce: " << block.getHeader().getNonce() << std::endl;
        std::cout << "Hash: " << block.getHeader().getHashStrReverse() << std::endl;


        std::cout << "Transactions: " << block.getTransactionCount() << std::endl;


        std::cout << "Pick one transaction: ";
        int transaction = 0;
        std::cin >> transaction;
        
        Transaction tr = block.getTransactions()[transaction];
        
        std::cout << "TRANSACTION " << transaction << " IN BLOCK " << blockNum << std::endl;
        std::cout << "Inputs: " << tr.getInputsCount() << "\t" << "Outputs: " << tr.getOutputsCount() << std::endl;
        
        std::cout << "\tINPUTS" << std::endl;
        
        for (Input input : tr.getInputs()) {
            std::cout << "\tPrev TX: " << input.getPreviousTransaction().getHexString() << std::endl;
            std::cout << "\tTxOut Index: " << input.getTxOutIndex();
            
            if (input.getTxOutIndex() == 0xFFFFFFFF) {
                std::cout << "(COINBASE)";
            }
            std::cout << std::endl;
        }
        
        std::cout << "\tOUTPUTS" << std::endl;
        for (Output output : tr.getOutputs()) {
            std::cout << "\tValue: " << output.getValue()<< std::endl;
        }
        
    }
    
    std::cout << "Bye!" << std::endl;
    
    
    return 0;
}

