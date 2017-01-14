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

#ifndef MMA8452Q_H
#define MMA8452Q_H

#include <mbed.h>
#include <stdint.h>

/**
 * @brief API for using the Freescale MMA8452Q Accelerometer with mbedOS.
 *
 * @details The MMA8452Q is a smart, low-power, three-axis, accelerometer
 * with 12 bits of resolution. It has user selectable full scales of ±2g/±4g/±8g
 * with high-pass filter filtered data as well as non-filtered data available real-time
 */
class MMA8452Q {
public:
    /**
     * @brief Creates a new instance of the MMA8452Q Accelerometer
     *
     * @param sda SDA pin for I2C
     * @param scl SCL pin for I2C
     * @param addr I2C device address, 0x38 if SA0 is pulled low
     */
    MMA8452Q(PinName sda, PinName scl, uint8_t addr);

    void write_byte(Register reg, uint8_t data);
    uint8_t read_byte(Register);

private:
    I2C     *_bus;
    uint8_t _addr;

    enum Register {
        REG_Status               = 0x00,
        REG_XUpper               = 0x01,
        REG_XLower               = 0x02,
        REG_YUpper               = 0x03,
        REG_YLower               = 0x04,
        REG_ZUpper               = 0x05,
        REG_ZLower               = 0x06,
        REG_Mode                 = 0x0B,
        REG_InteruptStatus       = 0x0C,
        REG_Whoami               = 0x0D,
        REG_XYZConfig            = 0x0E, // R/W
        REG_FilterThreshold      = 0x0F, // R/W
        REG_OrientationStatus    = 0x10,
        REG_OrientationConfig    = 0x11, // R/W
        REG_OrientationCounter   = 0x12,
        REG_OrientationZLock     = 0x13,
        REG_OrientationThreshold = 0x14,
        REG_FreefallConfig       = 0x15, // R/W
        REG_FreefallSource       = 0x16,
        REG_FreefallThreshold    = 0x17, // R/W
        REG_FreefallCounter      = 0x18, // R/W
        REG_TransientConfig      = 0x1D, // R/W
        REG_TransientSource      = 0x1E,
        REG_TransientThreshold   = 0x1F, // R/W
        REG_TransientCounter     = 0x20, // R/W
        REG_PulseConfig          = 0x21, // R/W
        REG_PulseSource          = 0x22,
        REG_PulseXThreshold      = 0x23, // R/W
        REG_PulseYThreshold      = 0x24, // R/W
        REG_PulseZThreshold      = 0x25, // R/W
        REG_PulseLimit           = 0x26, // R/W
        REG_PulseLatency         = 0x27, // R/W
        REG_PulseWindow          = 0x28, // R/W
        REG_aslpCounter          = 0x29, // R/W
        REG_Control1             = 0x2A, // R/W
        REG_Control2             = 0x2B, // R/W
        REG_Control3             = 0x2C, // R/W
        REG_Control4             = 0x2D, // R/W
        REG_Control5             = 0x2E, // R/W
        REG_XOffset              = 0x2F, // R/W
        REG_YOffset              = 0x30, // R/W
        REG_ZOffset              = 0x31  // R/W
    };
};

#endif //MMA8452Q_H
