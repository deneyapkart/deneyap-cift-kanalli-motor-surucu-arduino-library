/*
*****************************************************************************
@file         Deneyap_CiftKanalliMotorSurucu.cpp
@mainpage     Deneyap Dual Channel Motor Driver TC78H660FTG Arduino library 
              source file
@maintainer   RFtek Electronics <techsupport@rftek.com.tr>
@version      v1.0.0
@date         June 23, 2022
@brief        Includes functions to control Deneyap Dual Channel Motor Driver
              TC78H660FTG Arduino library

Library includes:
--> Configuration functions
--> Data manipulation functions
--> I2C communication functions
*****************************************************************************
*/

#include "Deneyap_CiftKanalliMotorSurucu.h"

/* Device Status Functions ---------------------------------------------------*/

/**
* @brief  Configures I2C connection with user defined address and port
* @param  address: I2C address of the device, port: I2C port number (0 or 1)
* @retval connection status (1 --> connected, 0 --> not connected)
*/
bool DualMotorDriver::begin(uint8_t address, TwoWire &port)
{
   Wire.begin(SDA_PIN,SCL_PIN,50000);
  _i2cAddress = address;
  _i2cPort = &port;
  _dataPacket = {0};

  return isConnected();     
}

/**
* @brief  Checks whether I2C connection established
* @param  None
* @retval connection status (1 --> connected, 0 --> not connected)
*/
bool DualMotorDriver::isConnected()
{
  _i2cPort->beginTransmission(_i2cAddress);

  if(_i2cPort->endTransmission() == 0)
    return true;
  return false;
}

/**
* @brief  Requests firmware version of the device
* @param  None
* @retval Device firmware version
*/
uint16_t DualMotorDriver::getFwVersion()
{
  _dataPacket.command = TC78H660FTG_REQUEST_FW_VERSION;
  _dataPacket.dataSize = 0;
  return I2C_ReadData16bit(&_dataPacket);
}

/**
* @brief  Sets (changes) I2C address of the device
* @param  address: I2C address to be set
* @retval Transmission status (1 --> No error, Otherwise --> Transmission error)
*/

bool DualMotorDriver::setI2Caddress(uint8_t newAddress)
{
  _dataPacket.command = TC78H660FTG_CHANGE_ADDR;
  _dataPacket.dataSize = 1;
  _dataPacket.data[0] = newAddress;

  bool status = I2C_SendDataPacket(&_dataPacket);

  if(status == true)
  {
    _i2cAddress = newAddress;
    return true;
  }
  else
  {
    return false;
  }
}

/* I2C Data Manipulation Functions -------------------------------------------*/

/**
* @brief  Sends motor drive pwm data based on data protocol format
* @param  dutyCycleData: duty cycle data to be sent (0-100)
* @retval Transmission status (1 --> No error, Otherwise --> Transmission error)
*/
bool DualMotorDriver::Motor1Drive(uint8_t dutyCycleData, uint8_t directionData)
{
  _dataPacket.command = (uint8_t)DRIVE_MOTOR1;
  _dataPacket.dataSize = (uint8_t)0x02;
  _dataPacket.data[0] = dutyCycleData;
  _dataPacket.data[1] = directionData;
  return I2C_SendDataPacket(&_dataPacket);
}

bool DualMotorDriver::Motor2Drive(uint8_t dutyCycleData, uint8_t directionData)
{
  _dataPacket.command = (uint8_t)DRIVE_MOTOR2;
  _dataPacket.dataSize = (uint8_t)0x02;
  _dataPacket.data[0] = dutyCycleData;
  _dataPacket.data[1] = directionData;
  return I2C_SendDataPacket(&_dataPacket);
}

/* I2C Data Transaction Funstions --------------------------------------------*/

/**
* @brief  Reads 8bit data from I2C interface
* @param  dataPacket: includes protocol to request data
* @retval I2C 8bit data
*/
uint8_t DualMotorDriver::I2C_ReadData8bit(TC78H660FTG_DataPacket_TypeDef* dataPacket)
{
  _i2cPort->beginTransmission(_i2cAddress);
  _i2cPort->write(dataPacket->command);
  _i2cPort->endTransmission();

  if(_i2cPort->requestFrom(_i2cAddress, static_cast<uint8_t>(1)) != 0)
    return _i2cPort->read();
  return 0;       
}

/**
* @brief  Reads 16bit data from I2C interface
* @param  dataPacket: includes protocol to request data
* @retval I2C 16bit data
*/
uint16_t DualMotorDriver::I2C_ReadData16bit(TC78H660FTG_DataPacket_TypeDef* dataPacket)
{
  _i2cPort->beginTransmission(_i2cAddress);
  _i2cPort->write(dataPacket->command);
  _i2cPort->endTransmission();

  if(_i2cPort->requestFrom(_i2cAddress, static_cast<uint8_t>(2)) != 0)
  {
    uint16_t i2cData = _i2cPort->read();
    i2cData |= (_i2cPort->read() << 8);
    return i2cData;
  }
  return 0;       
}

/**
* @brief  Sends data packet based on a custom defined protocol
* @param  dataPacket: includes all related data 
* @retval Transmission status (1 --> No error, Otherwise --> Transmission error)
*/
bool DualMotorDriver::I2C_SendDataPacket(TC78H660FTG_DataPacket_TypeDef* dataPacket)
{
  _i2cPort->beginTransmission(_i2cAddress);
  _i2cPort->write(dataPacket->command);
  _i2cPort->write(dataPacket->dataSize);

  for(uint8_t i = 0; i < _dataPacket.dataSize; i++)
    _i2cPort->write(_dataPacket.data[i]);

  if(_i2cPort->endTransmission() == 0)
  return true;
  return false;
}
