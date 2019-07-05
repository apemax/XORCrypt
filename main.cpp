/*
    This file is part of XORCrypt.

    XORCrypt is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    XORCrypt is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with XORCrypt.  If not, see <http://www.gnu.org/licenses/>.
*/
// Copyright (C) 2019
// Author: Peter (apemax) Wright
// XORCrypt

#include "crypt.h"
using namespace std;

int main(int argc, char const *argv[])
{
  string InputFileName;
  string OutputFileName;
  string KeyFileName;
  string InputFileContents;
  string OutputFileContents;
  string Key;

  if(argc <= 1)
  {
    cout << "No options specified, Type -h for usage information." << endl;
  }
  else
  {
    string CLOption1 = argv[1];

    if(CLOption1 == "-h")
    {
      cout << "Usage:" << endl;
      cout << "XORCrypt [-ih] InputFileName" << endl;
      cout << "XORCrypt [-ih] InputFileName [-k] KeyFileName" << endl;
      cout << endl;
      cout << "Options:" << endl;
      cout << "-i   Encrypt or decrypt a text file." << endl;
      cout << "-k   Specify the file name for the key file, If this option isn't used the default file name \"key.dat\" will be used." << endl;
      cout << "-h   Display this help." << endl;
      cout << endl;
      cout << "Example:" << endl;
      cout << "XORCrypt -i filename -k keyfile //Encrypt or decrypt the text file \"filename\"." << endl;
    }
    else if(CLOption1 == "-i")
    {
      string CLOption2 = argv[3];

      InputFileName = argv[2];

      if(CLOption2 == "-k")
      {
        KeyFileName = argv[4];
      }
      else
      {
        KeyFileName = "key.dat";
      }

      OutputFileName = InputFileName;

      OutputFileName.append(".xor");

      ifstream InputFile(InputFileName, ios::in);
      ofstream OutputFile(OutputFileName, ios::out);
      ifstream KeyFile(KeyFileName, ios::in);

      if(KeyFile.is_open())
      {
        getline(KeyFile, Key, '\n');
      }

      if(InputFile.is_open())
      {
        bool RunningE = true;

        while(RunningE == true)
        {
          getline(InputFile, InputFileContents, '\n');

          OutputFileContents = EncryptDecrypt(InputFileContents, Key);

          OutputFile << OutputFileContents << endl;

          if(InputFile.eof())
          {
            RunningE = false;
          }
        }
      }
    }

  }
  return 0;
}
