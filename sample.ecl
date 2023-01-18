
inRec := { DATA1 id };
ds := DATASET([x'F9', x'BE', x'B4', x'D9', x'DC', x'02', x'00', x'00',x'F9', x'BE', x'B4', x'D9', x'23', x'23', x'12', x'56', x'F9', x'BE'], inRec);

STRING traceDataset(STRING path) := EMBED(C++)
#include <stdio.h>
#include <unordered_map>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;

#body
    FILE *fp = fopen(path, "r");
    char buff[100];
    while(fgets(buff,sizeof(buff),fp)) break;

    __lenResult = 100;
    __result = buff;

ENDEMBED;

OUTPUT(traceDataset('/home/harsha/cpp-bitcoin-block-parser/a.txt'));