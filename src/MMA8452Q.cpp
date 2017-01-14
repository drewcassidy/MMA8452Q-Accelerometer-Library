/*
   Copyright 2017 Andrew Cassidy

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

#include "MMA8452Q.h"
#include <mbed.h>
#include <stdint.h>

MMA8452Q::MMA8452Q(PinName sda, PinName scl, uint8_t addr) {
    _bus  = new I2C(sda, scl);
    _addr = addr;
}

void MMA8452Q::write_byte(Register reg, uint8_t data) {
    char bytes[2] = {reg, data};
    _bus -> write(_addr, bytes, 1, true);
    _bus -> write(_addr, bytes + 1, 1);
}

uint8_t MMA8452Q::read_byte(Register reg) {
    char bytes[2] = {reg, 0};
    _bus -> write(_addr, bytes, 1, true);
    _bus -> read(_addr, bytes + 1, 1, false);
    return bytes[1];
}
