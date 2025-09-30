/*
*******************************************************************************************
@file         Deneyap_CiftKanalliMotorSurucu.h
@mainpage     Deneyap Dual Channel Motor Driver Arduino library header file
@version      v1.1.1
@date         December 19, 2022
@brief        This file contains all function prototypes and macros
              for Deneyap Dual Channel Motor Driver Arduino library
********************************************************************************************
*/

#ifndef __Deneyap_CiftKanalliMotorSurucu_H
#define __Deneyap_CiftKanalliMotorSurucu_H

#include <Wire.h>
#include <Arduino.h>

#define I2C_SLV_ADDR_DEFAULT    (uint8_t)0x16
#define I2C_SLV_ADDR_ALT1       (uint8_t)(I2C_SLV_ADDR_DEFAULT + 1)
#define I2C_SLV_ADDR_ALT2       (uint8_t)(I2C_SLV_ADDR_DEFAULT + 2)
#define I2C_SLV_ADDR_ALT3       (uint8_t)(I2C_SLV_ADDR_DEFAULT + 3)

#define DATA_BUFFER_SIZE        4     // in Byte (max data size)

#define DISABLE                 0
#define ENABLE                  1 

#define STEP                    0
#define DC                      1

#define MOTOR1                  1
#define MOTOR2                  2

#define FORWARD                 1
#define REVERSE                 0

#define SET                     1
#define RESET                   0

#define delayms                 1
#define delayus                 1

typedef struct                        // Data packet (protocol) created by master
{                                     // for I2C data exchange process 
  uint8_t command       : 4;
  uint8_t dataSize      : 3;
  uint8_t data[DATA_BUFFER_SIZE];
} DualMotorDriver_DataPacket_TypeDef;

enum DualMotorDriver_packetCommands                   // Commands in data packet (protocol)
{
  DRIVE_MOTOR1 = (uint8_t)0x00,
  DRIVE_MOTOR2,
  STEP_MOTOR,
  MOTOR_PWM_SETTING,
  STANDBY,
  MODE,
  CHANGE_ADDR,
  REQUEST_FW_VERSION,
  CHECK_MOTOR_ERROR,
};

class DualMotorDriver
{ 
  public:
    /* Check device status */
    bool begin(uint8_t address, uint32_t Freq = 500, TwoWire &port = Wire); 
    bool isConnected();                                                       
    uint16_t getFwVersion();                                                  
    bool setI2Caddress(uint8_t newAddress);                                      
    bool CheckMotorError(void);

    /* Functions for data manipulation (create and send packet data) */
    void MotorDrive(uint8_t motorID, int32_t dutyCycleData, bool directionData);
    bool StepDrive(bool in1A, bool in1B, bool in2A, bool in2B);
    bool PwmConfig(uint32_t freq);
    bool StandbyMode(bool status);
    void SelectModeDC(void);
    void SelectModeSTEP(void);
    void SelectMotorType(void);

    bool _stepMotorSelected;
    uint8_t i2cData2;
    uint8_t i2cData1;

  private:
    TwoWire* _i2cPort;                // Port selection (0 or 1)
    uint8_t _i2cAddress;              // Device I2C address
    uint8_t _dutyCycleData1;
    uint8_t _dutyCycleData2;
    bool _forward1;
    bool _reverse1;
    bool _forward2;
    bool _reverse2;
    DualMotorDriver_DataPacket_TypeDef _dataPacket;   // Struct to transfer data over I2C interface

    bool SelectMode(bool driveMode);
    void ResetMotorParameters(void);

    /* DC motor drive functions */
    bool Motor1Drive(uint8_t dutyCycleData, uint8_t directionData);
    bool Motor2Drive(uint8_t dutyCycleData, uint8_t directionData);
    
    /* I2C data transaction functions */
    uint8_t I2C_ReadData8bit(DualMotorDriver_DataPacket_TypeDef* dataPacket);
    uint16_t I2C_ReadData16bit(DualMotorDriver_DataPacket_TypeDef* dataPacket);
    bool I2C_SendDataPacket(DualMotorDriver_DataPacket_TypeDef* dataPacket);
    uint16_t I2C_ReadFirmwareData16bit(DualMotorDriver_DataPacket_TypeDef *dataPacket);
};

class Stepper : public DualMotorDriver {
  public:
    Stepper(int number_of_steps);
    void setSpeed(long whatSpeed);  // speed setter method
    void step(int number_of_steps); // mover method

  private:
    void stepMotor(int this_step);

    int direction;            // Direction of rotation
    unsigned long step_delay; // delay between steps, in ms, based on speed
    int number_of_steps;      // total number of steps this motor can take
    int step_number;          // which step the motor is on

    unsigned long last_step_time; // time stamp in us of when the last step was taken
};

#endif /* Deneyap_CiftKanalliMotorSurucu_H */
