/*
*******************************************************************************************
@file         Deneyap_CiftKanalliMotorSurucu.cpp
@mainpage     Deneyap Dual Channel Motor Driver Arduino library source file
@maintainer   RFtek Electronics <techsupport@rftek.com.tr>
@version      v1.1.1
@date         December 19, 2022
@brief        Includes functions to control Deneyap Dual Channel Motor Driver
              Arduino library

Library includes:
--> Configuration functions
--> Data manipulation functions
--> I2C communication functions
*******************************************************************************************
*/
#include "Deneyap_CiftKanalliMotorSurucu.h"

/* Device Status Functions ---------------------------------------------------*/

/**
* @brief  Configures I2C connection with user defined address and port
* @param  address: I2C address of the device, port: I2C port number (0 or 1)
* @retval connection status (1 --> connected, 0 --> not connected)
*/
bool DualMotorDriver::begin(uint8_t address, uint32_t Freq, TwoWire &port) {
  Wire.begin();
#if defined (ARDUINO_DYM) || defined (ARDUINO_DYMv2)
  Wire.setClock(100000);
#else
  Wire.setClock(50000);
#endif
  _i2cAddress = address;
  _i2cPort = &port;
  _dataPacket = { 0, 0, 0 };

  ResetMotorParameters();
  PwmConfig(Freq);  
  SelectMotorType();
  Motor1Drive(0, 0);
  Motor2Drive(0, 0);
  
  return isConnected();
}

/**
* @brief  Checks whether I2C connection established
* @param  None
* @retval connection status (1 --> connected, 0 --> not connected)
*/
bool DualMotorDriver::isConnected() {
  _i2cPort->beginTransmission(_i2cAddress);

  if (_i2cPort->endTransmission() == 0)
    return true;
  return false;
}

/**
* @brief  Requests firmware version of the device
* @param  None
* @retval Device firmware version
*/
uint16_t DualMotorDriver::getFwVersion() {
  _dataPacket.command = REQUEST_FW_VERSION;
  _dataPacket.dataSize = 0;
  return I2C_ReadFirmwareData16bit(&_dataPacket);
}

/**
* @brief  Sets (changes) I2C address of the device
* @param  address: I2C address to be set
* @retval Transmission status (1 --> No error, Otherwise --> Transmission error)
*/
bool DualMotorDriver::setI2Caddress(uint8_t newAddress) {
  _dataPacket.command = CHANGE_ADDR;
  _dataPacket.dataSize = 1;
  _dataPacket.data[0] = newAddress;

  bool status = I2C_SendDataPacket(&_dataPacket);

  if (status == true) {
    _i2cAddress = newAddress;
    return true;
  } else {
    return false;
  }
}

/* I2C Data Manipulation Functions -------------------------------------------*/

void DualMotorDriver::MotorDrive(uint8_t motorID, int32_t dutyCycleData, bool directionData){
  if (dutyCycleData < 0) dutyCycleData = 0;
  else if (dutyCycleData > 100) dutyCycleData = 100;
  switch(motorID) {
    case MOTOR1:
      switch(directionData) {
        case FORWARD:
          switch(_reverse1) {
            case SET:
              for(uint8_t i = _dutyCycleData1; i > 0; i--) {
                _dutyCycleData1 -= 1;
                Motor1Drive(_dutyCycleData1, !directionData);
                delayMicroseconds(delayus);
  
                if(_dutyCycleData1 == 0) {
                  _reverse1 = RESET;
                  Motor1Drive(_dutyCycleData1, !directionData);
                  delayMicroseconds(delayus);                  
                }
              }
            case RESET:
              _forward1 = SET;
              if(dutyCycleData > _dutyCycleData1) {
                for(uint8_t i = _dutyCycleData1; i < dutyCycleData; i++) {
                  _dutyCycleData1 += 1;
                  Motor1Drive(_dutyCycleData1, directionData);
                  delayMicroseconds(delayus);
                }  
              }
              else if(dutyCycleData < _dutyCycleData1) {
                for(uint8_t i = _dutyCycleData1; i > dutyCycleData; i--) {
                  _dutyCycleData1 -= 1;
                  Motor1Drive(_dutyCycleData1, directionData);
                  delayMicroseconds(delayus);
                }
              }
              else if(dutyCycleData == _dutyCycleData1) {
                _dutyCycleData1 = _dutyCycleData1;
              }
              break;
          }
          break;
          
        case REVERSE:
          switch(_forward1) {
            case SET:
              for(uint8_t i = _dutyCycleData1; i > 0; i--) {
                _dutyCycleData1 -= 1;
                Motor1Drive(_dutyCycleData1, !directionData);
                delayMicroseconds(delayus);
  
                if(_dutyCycleData1 == 0) {
                  _forward1 = RESET;
                  Motor1Drive(_dutyCycleData1, !directionData);
                  delayMicroseconds(delayus);                  
                }
              }
            case RESET:
              _reverse1 = SET;
              if(dutyCycleData > _dutyCycleData1) {
                for(uint8_t i = _dutyCycleData1; i < dutyCycleData; i++) {
                  _dutyCycleData1 += 1;
                  Motor1Drive(_dutyCycleData1, directionData);
                  delayMicroseconds(delayus);
                }  
              }
              else if(dutyCycleData < _dutyCycleData1) {
                for(uint8_t i = _dutyCycleData1; i > dutyCycleData; i--) {
                  _dutyCycleData1 -= 1;
                  Motor1Drive(_dutyCycleData1, directionData);
                  delayMicroseconds(delayus);
                }
              }
              else if(dutyCycleData == _dutyCycleData1) {
                _dutyCycleData1 = _dutyCycleData1;
              }
              break;
          }
          break;
      }  
      break;

    case MOTOR2:
      switch(directionData) {
        case FORWARD:
          switch(_reverse2) {
            case SET:
              for(uint8_t i = _dutyCycleData2; i > 0; i--) {
                _dutyCycleData2 -= 1;
                Motor2Drive(_dutyCycleData2, !directionData);
                delayMicroseconds(delayus);
                if(_dutyCycleData2 == 0) {
                  _reverse2 = RESET;
                  Motor2Drive(_dutyCycleData2, !directionData);
                  delayMicroseconds(delayus);                  
                }
              }
            case RESET:
              _forward2 = SET;
              if(dutyCycleData > _dutyCycleData2) {
                for(uint8_t i = _dutyCycleData2; i < dutyCycleData; i++) {
                  _dutyCycleData2 += 1;
                  Motor2Drive(_dutyCycleData2, directionData);
                  delayMicroseconds(delayus);
                }  
              }
              else if(dutyCycleData < _dutyCycleData2) {
                for(uint8_t i = _dutyCycleData2; i > dutyCycleData; i--) {
                  _dutyCycleData2 -= 1;
                  Motor2Drive(_dutyCycleData2, directionData);
                  delayMicroseconds(delayus);
                }
              }
              else if(dutyCycleData == _dutyCycleData2) {
                _dutyCycleData2 = _dutyCycleData2;
              }
              break;
          }
          break;
          
        case REVERSE:
          switch(_forward2) {
            case SET:
              for(uint8_t i = _dutyCycleData2; i > 0; i--) {
                _dutyCycleData2 -= 1;
                Motor2Drive(_dutyCycleData2, !directionData);
                delayMicroseconds(delayus);
  
                if(_dutyCycleData2 == 0) {
                  _forward2 = RESET;
                  Motor2Drive(_dutyCycleData2, !directionData);
                  delayMicroseconds(delayus);                  
                }
              }
            case RESET:
              _reverse2 = SET;
              if(dutyCycleData > _dutyCycleData2) {
                for(uint8_t i = _dutyCycleData2; i < dutyCycleData; i++) {
                  _dutyCycleData2 += 1;
                  Motor2Drive(_dutyCycleData2, directionData);
                  delayMicroseconds(delayus);
                }  
              }
              else if(dutyCycleData < _dutyCycleData2) {
                for(uint8_t i = _dutyCycleData2; i > dutyCycleData; i--) {
                  _dutyCycleData2 -= 1;
                  Motor2Drive(_dutyCycleData2, directionData);
                  delayMicroseconds(delayus);
                }
              }
              else if(dutyCycleData == _dutyCycleData2) {
                _dutyCycleData2 = _dutyCycleData2;
              }
              break;
          }
          break;
      }
      break;
  }
}

/**
* @brief  Sends motor drive pwm data based on data protocol format
* @param  dutyCycleData: duty cycle data to be sent (0-100)
* @retval Transmission status (1 --> No error, Otherwise --> Transmission error)
*/
bool DualMotorDriver::Motor1Drive(uint8_t dutyCycleData, uint8_t directionData) {
  _dataPacket.command = (uint8_t)DRIVE_MOTOR1;
  _dataPacket.dataSize = (uint8_t)0x02;
  _dataPacket.data[0] = dutyCycleData;
  _dataPacket.data[1] = directionData;

  return I2C_SendDataPacket(&_dataPacket);
}

/**
* @brief 
* @param 
* @retval 
*/
bool DualMotorDriver::Motor2Drive(uint8_t dutyCycleData, uint8_t directionData) {
  _dataPacket.command = (uint8_t)DRIVE_MOTOR2;
  _dataPacket.dataSize = (uint8_t)0x02;

  _dataPacket.data[0] = dutyCycleData;
  _dataPacket.data[1] = directionData;

  return I2C_SendDataPacket(&_dataPacket);
}

/**
* @brief 
* @param  in1A:1 channel phase pin
* @param  in1B:1 channel enable pin
* @param  in2A:2 channel phase pin
* @param  in2B:2 channel enable pin
* @retval 
*/
bool DualMotorDriver::StepDrive(bool in1A, bool in1B, bool in2A, bool in2B) {
  _dataPacket.command = (uint8_t)STEP_MOTOR;
  _dataPacket.dataSize = (uint8_t)0x04;
  _dataPacket.data[0]= in1A;
  _dataPacket.data[1]= in1B;
  _dataPacket.data[2]= in2A;
  _dataPacket.data[3]= in2B;

  return I2C_SendDataPacket(&_dataPacket);
}

/**
* @brief 
* @param 
* @retval 
*/
bool DualMotorDriver::StandbyMode(bool status) {
  _dataPacket.command = STANDBY;
  _dataPacket.dataSize = (uint8_t)0x01;

  switch(status) {
    case DISABLE:
      _dataPacket.data[0] = 0x00;
      break;

    case ENABLE:
      _dataPacket.data[0] = 0x01;
      break;
  }

  return I2C_SendDataPacket(&_dataPacket);
}

/**
* @brief 
* @param 
* @retval 
*/
bool DualMotorDriver::SelectMode(bool driveMode) {
  _dataPacket.command = MODE;
  _dataPacket.dataSize = (uint8_t)0x01;

  switch(driveMode) {
    case STEP:
      _dataPacket.data[0] = 0x00;
      break;

    case DC:
      _dataPacket.data[0] = 0x01;
      break;
  }

  return I2C_SendDataPacket(&_dataPacket);
}

/**
* @brief 
* @param 
* @retval 
*/
bool DualMotorDriver::CheckMotorError() {
  _dataPacket.command = CHECK_MOTOR_ERROR;
  _dataPacket.dataSize = 0;
  return I2C_ReadData8bit(&_dataPacket);
}

/**
* @brief 
* @param 
* @retval 
*/
void DualMotorDriver::SelectModeDC(void){
  /* Mode selection is set up by the input state 
     of the MODE pin after releasing standby mode,
     at least 1us setup time needed */
  StandbyMode(DISABLE);
  delay(1);
  SelectMode(DC);
  delay(1);
  StandbyMode(ENABLE);
}

/**
* @brief 
* @param 
* @retval 
*/
void DualMotorDriver::SelectModeSTEP(void){
  /* Mode selection is set up by the input state 
     of the MODE pin after releasing standby mode,
     at least 1us setup time needed */
  StandbyMode(DISABLE);
  delay(1);
  SelectMode(STEP);
  delay(1);
  StandbyMode(ENABLE);
}

/**
* @brief 
* @param 
* @retval 
*/
void DualMotorDriver::SelectMotorType(void){
  if(_stepMotorSelected) {
    SelectModeSTEP();
    _stepMotorSelected = 0;
  } else {
    SelectModeDC();
  }
}
/**
* @brief 
* @param 
* @retval 
*/
bool DualMotorDriver::PwmConfig(uint32_t freq) {
  uint8_t freq1 = (uint8_t)freq;
  uint8_t freq2 = (uint8_t)(freq >> 8);
  uint8_t freq3 = (uint8_t)(freq >> 16);
  uint8_t freq4 = (uint8_t)(freq >> 24);

  _dataPacket.command = (uint8_t)MOTOR_PWM_SETTING;
  _dataPacket.dataSize = (uint8_t)0x04;
  _dataPacket.data[0] = freq1;
  _dataPacket.data[1] = freq2;
  _dataPacket.data[2] = freq3;
  _dataPacket.data[3] = freq4;

  return I2C_SendDataPacket(&_dataPacket);
}

/**
* @brief 
* @param 
* @retval 
*/
void DualMotorDriver::ResetMotorParameters(void) {
  _dutyCycleData1 = 0;
  _dutyCycleData2 = 0;
  _forward1 = 0;
  _reverse1 = 0;
  _forward2 = 0;
  _reverse2 = 0;
}

/**
* @brief 
* @param 
* @retval 
*/
Stepper::Stepper(int number_of_steps) {
  this->step_number = 0;                    // which step the motor is on
  this->direction = 0;                      // motor direction
  this->last_step_time = 0;                 // time stamp in us of the last step taken
  this->number_of_steps = number_of_steps;  // total number of steps for this motor
  _stepMotorSelected = 1;
}

/**
* @brief  Sets the speed in revs per minute
* @param 
* @retval 
*/
void Stepper::setSpeed(long whatSpeed) {
  this->step_delay = 60L * 1000L * 1000L / this->number_of_steps / whatSpeed;
}

/**
* @brief  Moves the motor steps_to_move steps.  If the number is negative, the motor moves in the reverse direction.
* @param 
* @retval 
*/
void Stepper::step(int steps_to_move) {
  int steps_left = abs(steps_to_move);  // how many steps to take

  // determine direction based on whether steps_to_mode is + or -:
  if (steps_to_move > 0) { this->direction = 1; }
  if (steps_to_move < 0) { this->direction = 0; }


  // decrement the number of steps, moving one step each time:
  while (steps_left > 0) {
    unsigned long now = micros();
    // move only if the appropriate delay has passed:
    if (now - this->last_step_time >= this->step_delay) {
      // get the timeStamp of when you stepped:
      this->last_step_time = now;
      // increment or decrement the step number,
      // depending on direction:
      if (this->direction == 1) {
        this->step_number++;
        if (this->step_number == this->number_of_steps) {
          this->step_number = 0;
        }
      } else {
        if (this->step_number == 0) {
          this->step_number = this->number_of_steps;
        }
        this->step_number--;
      }
      // decrement the steps left:
      steps_left--;
      // step the motor to step number 0, 1, ..., {3 or 10}
      stepMotor(this->step_number % 8);
    }
  }
}

/**
* @brief  Moves the motor forward or backwards.
* @param  thisStep: step of the motor
* @retval 
*/
void Stepper::stepMotor(int thisStep) {
  switch (thisStep) {
    case 0:
      StepDrive(1,0,0,0);
      break;
    case 1: 
      StepDrive(1,1,0,0);
      break;
    case 2:
      StepDrive(0,1,0,0);
      break;
    case 3:
      StepDrive(0,1,1,0);
      break;
    case 4:
      StepDrive(0,0,1,0);
      break;
    case 5:
      StepDrive(0,0,1,1);
      break;
    case 6:
      StepDrive(0,0,0,1);
      break;
    case 7:
      StepDrive(1,0,0,1);
      break;
  }
}

/* I2C Data Transaction Funstions --------------------------------------------*/

/**
* @brief  Reads 8bit data from I2C interface
* @param  dataPacket: includes protocol to request data
* @retval I2C 8bit data
*/
uint8_t DualMotorDriver::I2C_ReadData8bit(DualMotorDriver_DataPacket_TypeDef *dataPacket) {
  _i2cPort->beginTransmission(_i2cAddress);
  _i2cPort->write(dataPacket->command);
  _i2cPort->endTransmission();

  if (_i2cPort->requestFrom(_i2cAddress, static_cast<uint8_t>(1)) != 0)
    return _i2cPort->read();
  return false;
}

/**
 * @brief  Reads 16bit data from I2C interface
 * @param  dataPacket: includes protocol to request data
 * @retval I2C 16bit data
 */
uint16_t DualMotorDriver::I2C_ReadFirmwareData16bit(DualMotorDriver_DataPacket_TypeDef *dataPacket) {
  _i2cPort->beginTransmission(_i2cAddress);
  _i2cPort->write(dataPacket->command);
  _i2cPort->endTransmission();

  if (_i2cPort->requestFrom(_i2cAddress, static_cast<uint8_t>(2)) != 0) {
    i2cData2 = _i2cPort->read();
    i2cData1 = _i2cPort->read();
    Serial.print("v"); Serial.print(i2cData1); Serial.print("."); Serial.println(i2cData2);
  }
  return false;
}

/**
 * @brief  Sends data packet based on a custom defined protocol
 * @param  dataPacket: includes all related data
 * @retval Transmission status (1 --> No error, Otherwise --> Transmission error)
 */
bool DualMotorDriver::I2C_SendDataPacket(DualMotorDriver_DataPacket_TypeDef *dataPacket) {
  _i2cPort->beginTransmission(_i2cAddress);
  _i2cPort->write(dataPacket->command);
  _i2cPort->write(dataPacket->dataSize);

  for (uint8_t i = 0; i < _dataPacket.dataSize; i++)
    _i2cPort->write(_dataPacket.data[i]);

  if (_i2cPort->endTransmission() == 0)
    return true;
  return false;
}
