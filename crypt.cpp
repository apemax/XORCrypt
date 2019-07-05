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

string EncryptDecrypt(string Input, string XORKey)
{
  string Output = Input;

  int Ilen = Input.size();
  int Klen = XORKey.size();

  for (int i = 0; i < Ilen; i++)
  {
      Output[i] = Input[i] ^ XORKey[i % Klen];
  }
  
  return Output;
}
