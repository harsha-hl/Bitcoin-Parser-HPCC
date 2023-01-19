INTEGER traceDataset(STRING path) := EMBED(C++)
#include <stdio.h>
#include <unordered_map>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;

#body
    FILE *fp = fopen(path, "r");
    char buff[10];
    while(fgets(buff,sizeof(buff),fp)) break;
	  return 0;
ENDEMBED;

OUTPUT(traceDataset('/var/lib/HPCCSystems/hpcc-data/thor/bitcoinraw._1_of_1'));