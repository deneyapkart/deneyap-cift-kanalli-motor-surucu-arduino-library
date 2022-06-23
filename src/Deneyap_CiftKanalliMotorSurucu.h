/*
*******************************************************************************************
@file         Deneyap_CiftKanalliMotorSurucu.h
@mainpage     Deneyap Dual Channel Motor Driver TC78H660FTG Arduino library header file
@version      v1.0.0
@date         June 23, 2022
@brief        This file contains all function prototypes and macros
              for Deneyap Dual Channel Motor Driver TC78H660FTG Arduino library
********************************************************************************************
*/

#ifndef __TC78H660FTG_H
#define __TC78H660FTG_H

#include <Wire.h>
#include <Arduino.h>
#include <deneyap.h>

#define I2C_SLV_ADDR_DEFAULT    (uint8_t)0x16
#define I2C_SLV_ADDR_ALT1       (uint8_t)(I2C_SLV_ADDR_DEFAULT + 1)
#define I2C_SLV_ADDR_ALT2       (uint8_t)(I2C_SLV_ADDR_DEFAULT + 2)
#define I2C_SLV_ADDR_ALT3       (uint8_t)(I2C_SLV_ADDR_DEFAULT + 3)

#define DATA_BUFFER_SIZE        2     // in Byte (max data size)

#define SDA_PIN                 4
#define SCL_PIN                 15

typedef struct                        // Data packet (protocol) created by master
{																			// for I2C data exchange process 
  uint8_t command       : 3;
  uint8_t dataSize      : 2;
  uint8_t data[DATA_BUFFER_SIZE];
} TC78H660FTG_DataPacket_TypeDef;

enum TC78H660FTG_packetCommands                   // Commands in data packet (protocol)
{
  DRIVE_MOTOR1 = (uint8_t)0x00,
  DRIVE_MOTOR2,
  MOTOR_PWM,
  MOTOR_DIRECTION,
  TC78H660FTG_CHANGE_ADDR,
  TC78H660FTG_REQUEST_FW_VERSION,
};

class DualMotorDriver
{ 
  public:
    /* Check device status */
    bool begin(uint8_t address = I2C_SLV_ADDR_DEFAULT, TwoWire &port = Wire); 
    bool isConnected();                                                       
    uint16_t getFwVersion();                                                  
    bool setI2Caddress(uint8_t newAddress);                                      

    /* Functions for data manipulation (create and send packet data) */
    bool Motor1Drive(uint8_t dutyCycleData, uint8_t directionData);
    bool Motor2Drive(uint8_t dutyCycleData, uint8_t directionData);
  
  private:
    TwoWire* _i2cPort;                // Port selection (0 or 1)
    uint8_t _i2cAddress;              // Device I2C address
    TC78H660FTG_DataPacket_TypeDef _dataPacket;   // Struct to transfer data over I2C interface

    /* I2C data transaction functions */
    uint8_t I2C_ReadData8bit(TC78H660FTG_DataPacket_TypeDef* dataPacket);
    uint16_t I2C_ReadData16bit(TC78H660FTG_DataPacket_TypeDef* dataPacket);
    bool I2C_SendDataPacket(TC78H660FTG_DataPacket_TypeDef* dataPacket);
};


#endif /* __TC78H660FTG_H */
