/************************************************************************/
/*                                                                      */
/* Make Ansi to Unicode Charmap 1.0 (EUC-KR front-end) for next-c4 lib. */
/*                                                                      */
/* Version: 1.0                                                         */
/* Author:  kuyur (kuyur@kuyur.info)  -->twitter: @kuyur                */
/* Published under LGPL-3.0                                             */
/* https://www.gnu.org/licenses/lgpl-3.0.en.html                        */
/*                                                                      */
/* Copyright 2015 Project next-c4                                       */
/* https://github.com/kuyur/next-c4                                     */
/*                                                                      */
/************************************************************************/

#pragma once

#include "stdafx.h"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

unsigned char CharToHex(char ch) 
{ 
    // 0-9
    if (ch>='0'&&ch<='9')
        return (ch-'0');
    // 9-15
    if (ch>='A'&&ch<='F')
        return (ch-'A'+0xA);
    // 9-15
    if (ch>='a'&&ch<='f')
        return (ch-'a'+0xA);

    return(0);
}

int _tmain(int argc, _TCHAR* argv[])
{
    string inFileName = "../maps/src/CP949.txt";
    ifstream infile(inFileName.c_str());
    if (!infile)
    {
        cerr<<"Unable to open ../maps/src/CP949.txt!\n";
        return -1;
    }

    ofstream outfile_littleendian("../maps/dest/front-kr2u-little-endian.map",ios::binary);
    if (!outfile_littleendian)
    {
        cerr<<"Can not open ../maps/dest/front-kr2u-little-endian.map!\n";
        return -1;
    }

    string str;
    int i=0;
    int offset=0x8140;
    char zero[2]={'\xFD','\xFF'};
    while(getline(infile, str))
    {
        i++;

        int KRoffset;
        KRoffset=CharToHex(str[5])+CharToHex(str[4])*16+CharToHex(str[3])*16*16+CharToHex(str[2])*16*16*16;

        while(offset!=KRoffset)
        {
            offset++;
            outfile_littleendian.write(zero,2);
        }
        offset++;

        unsigned char HighByte,LowByte;
        HighByte=CharToHex(str[9])*16 +CharToHex(str[10]);
        LowByte =CharToHex(str[11])*16+CharToHex(str[12]);

        if ((HighByte>255)||(LowByte>255))
            cerr<<"Error occur in Line "<<i<<"!\n";

        outfile_littleendian.write((char*)&LowByte,1);
        outfile_littleendian.write((char*)&HighByte,1);
    }
    cout<<i<<" lines done!\n";
    infile.close();
    outfile_littleendian.close();

    return 0;
}
