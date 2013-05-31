/**
 *
 * - Oddjob
 * - http://code.google.com/p/photoduino/
 *
 * This file is part of Oddjob based on the Photoduino project
 *
 * Oddjob is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Oddjob is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Oddjob.  If not, see <http://www.gnu.org/licenses/>.
 */
 
 
// Load the shockTriggerMode from eeprom to ram
void config_loadBackup_shockTriggerMode(){   
  
  shockTriggerMode_shootingMode = EEPROM.read(EE_ADDR_shockTriggerMode_shootingMode);
  shockTriggerMode_sensorLimit = eeprom_readInt(EE_ADDR_shockTriggerMode_sensorLimit);
  shockTriggerMode_autofocusTime = eeprom_readInt(EE_ADDR_shockTriggerMode_autofocusTime);
  shockTriggerMode_shutterLagTime = eeprom_readInt(EE_ADDR_shockTriggerMode_shutterLagTime);
  shockTriggerMode_preCloseTime = eeprom_readInt(EE_ADDR_shockTriggerMode_preCloseTime);
  shockTriggerMode_useFlash1 = EEPROM.read(EE_ADDR_shockTriggerMode_useFlash1);
  shockTriggerMode_preFlash1Time = eeprom_readInt(EE_ADDR_shockTriggerMode_preFlash1Time);
  shockTriggerMode_useFlash2 = EEPROM.read(EE_ADDR_shockTriggerMode_useFlash2);
  shockTriggerMode_preFlash2Time = eeprom_readInt(EE_ADDR_shockTriggerMode_preFlash2Time);
  shockTriggerMode_numCicles =  eeprom_readInt(EE_ADDR_shockTriggerMode_numCicles);
  shockTriggerMode_interCicleTime =  eeprom_readInt(EE_ADDR_shockTriggerMode_interCicleTime);
}

// Load the default shockTriggerMode config to ram
void config_loadDefaults_shockTriggerMode() {
  
  shockTriggerMode_shootingMode =     DEFAULT_shockTriggerMode_shootingMode;
  shockTriggerMode_sensorLimit =      DEFAULT_shockTriggerMode_sensorLimit;
  shockTriggerMode_autofocusTime =    DEFAULT_shockTriggerMode_autofocusTime;
  shockTriggerMode_shutterLagTime =   DEFAULT_shockTriggerMode_shutterLagTime;
  shockTriggerMode_preCloseTime =     DEFAULT_shockTriggerMode_preCloseTime;
  shockTriggerMode_useFlash1 =        DEFAULT_shockTriggerMode_useFlash1;
  shockTriggerMode_preFlash1Time =    DEFAULT_shockTriggerMode_preFlash1Time;
  shockTriggerMode_useFlash2 =        DEFAULT_shockTriggerMode_useFlash2;
  shockTriggerMode_preFlash2Time =    DEFAULT_shockTriggerMode_preFlash2Time;
  shockTriggerMode_numCicles =        DEFAULT_shockTriggerMode_numCicles;
  shockTriggerMode_interCicleTime =   DEFAULT_shockTriggerMode_interCicleTime;

}

// Save the shockTriggerMode from ram to eeprom
void config_saveBackup_shockTriggerMode(){ 
  
  EEPROM.write(EE_ADDR_shockTriggerMode_shootingMode, shockTriggerMode_shootingMode);
  eeprom_writeInt(EE_ADDR_shockTriggerMode_sensorLimit, shockTriggerMode_sensorLimit);
  eeprom_writeInt(EE_ADDR_shockTriggerMode_autofocusTime, shockTriggerMode_autofocusTime);
  eeprom_writeInt(EE_ADDR_shockTriggerMode_shutterLagTime, shockTriggerMode_shutterLagTime);
  eeprom_writeInt(EE_ADDR_shockTriggerMode_preCloseTime, shockTriggerMode_preCloseTime);
  EEPROM.write(EE_ADDR_shockTriggerMode_useFlash1, shockTriggerMode_useFlash1);
  eeprom_writeInt(EE_ADDR_shockTriggerMode_preFlash1Time, shockTriggerMode_preFlash1Time);
  EEPROM.write(EE_ADDR_shockTriggerMode_useFlash2, shockTriggerMode_useFlash2);
  eeprom_writeInt(EE_ADDR_shockTriggerMode_preFlash2Time, shockTriggerMode_preFlash2Time);
  eeprom_writeInt(EE_ADDR_shockTriggerMode_numCicles, shockTriggerMode_numCicles);
  eeprom_writeInt(EE_ADDR_shockTriggerMode_interCicleTime, shockTriggerMode_interCicleTime); 
}

 
int menu_shock()
{
   int res;

  while (true)
  {
  
    res=mode_menu("Mode Shock");
     switch(res)
    {
      case 0: //run
      runAs_shockTrigger();
      break;
      
      case 1: //config
      menu_conf_shock();
      config_saveBackup_shockTriggerMode(); 
      break;
      
      case 2: //home
      return(0);
      break;
    }
  }
}

int menu_conf_shock()
{
 struct list_data list[9];
  
  list[0].description="Sensor Limit";
  list[0].unit=" ";
  list[0].value=shockTriggerMode_sensorLimit;
  list[0].mini=PINS_SENSOR_SHOCK;
  list[0].maxi=PINS_SENSOR_SHOCK;
  list[0].list[0]="";
  list[0].list[1]="";
  list[0].list[3]="";
  list[0].list[4]="Sensor";

  list[1].description="Shooting Mode";
  list[1].unit=" ";
  list[1].value=shockTriggerMode_shootingMode;
  list[1].mini=0;
  list[1].maxi=1;
  list[1].list[0]="Normal";
  list[1].list[1]="Pre-Bulb";
  list[1].list[3]="Mirror Lock-ip";
  list[1].list[4]="Pre Focused";
  
  
  list[2].description="Use Flash1";
  list[2].unit=" ";
  list[2].value=shockTriggerMode_useFlash1;
  list[2].mini=0;
  list[2].maxi=1;
  list[2].list[0]="Actif";
  list[2].list[1]="Inactif";
  list[2].list[3]="";
  list[2].list[4]="";

  list[3].description="PreFlash1Time";
  list[3].unit="ms";
  list[3].value=shockTriggerMode_preFlash1Time;
  list[3].mini=0;
  list[3].maxi=1000;
  list[3].list[0]="";
  list[3].list[1]="";
  list[3].list[2]="";
  list[3].list[3]="";
  list[3].list[4]="";

  list[4].description="Use Flash2";
  list[4].unit=" ";
  list[4].value=shockTriggerMode_useFlash2;
  list[4].mini=0;
  list[4].maxi=1;
  list[4].list[0]="Actif";
  list[4].list[1]="Inactif";
  list[4].list[2]="";
  list[4].list[3]="";
  list[4].list[4]="";

  list[5].description="PreFlash2 Time";
  list[5].unit="ms";
  list[5].value=shockTriggerMode_preFlash2Time;
  list[5].mini=0;
  list[5].maxi=1000;
  list[5].list[0]="";
  list[5].list[1]="";
  list[5].list[2]="";
  list[5].list[3]="";
  list[5].list[4]="";

  list[6].description="PreClose Time";
  list[6].unit="ms";
  list[6].value=shockTriggerMode_preCloseTime;
  list[6].mini=0;
  list[6].maxi=1000;
  list[6].list[0]="";
  list[6].list[1]="";
  list[6].list[2]="";
  list[6].list[3]="";
  list[6].list[4]="";

  list[7].description="Nb Cicles";
  list[7].unit="  ";
  list[7].value=shockTriggerMode_numCicles;
  list[7].mini=0;
  list[7].maxi=10000;
  list[7].list[0]="";
  list[7].list[1]="";
  list[7].list[2]="";
  list[7].list[3]="";
  list[7].list[4]="";

  list[8].description="Interval Time";
  list[8].unit="s ";
  list[8].value=shockTriggerMode_interCicleTime;
  list[8].mini=0;
  list[8].maxi=1000;
  list[8].list[0]="";
  list[8].list[1]="";
  list[8].list[2]="";
  list[8].list[3]="";
  list[8].list[4]="";
  
  
  
  myGLCD.clrScr();
  res=menu_list(9,list);
  shockTriggerMode_sensorLimit=list[0].value;
  shockTriggerMode_shootingMode=list[1].value;
  shockTriggerMode_useFlash1=list[2].value;
  shockTriggerMode_preFlash1Time=list[3].value;
  shockTriggerMode_useFlash2=list[4].value;
  shockTriggerMode_preFlash2Time=list[5].value;
  shockTriggerMode_preCloseTime=list[6].value;
  shockTriggerMode_numCicles=list[7].value;
  shockTriggerMode_interCicleTime=list[8].value;
  return(0);
}

  // Run shock trigger mode
void runAs_shockTrigger() { 

    int dec=20;
    int y=20;
    myGLCD.clrScr(); //clear the screen
    myGLCD.setFont(BigFont);
    myGLCD.setColor(200, 200, 200);
    myGLCD.print(MSG_RUN_SHOCK,10,y);
    y=y+dec;
   cancelFlag=false;
   
   for(unsigned int ciclesCounter = 0; (cancelFlag==false && !(shockTriggerMode_numCicles>0 && ciclesCounter >= shockTriggerMode_numCicles)) ;ciclesCounter++) { 
     myGLCD.print("photo "+ String(ciclesCounter+1)+ "/" + String(intervalMode_numCicles),10,y);
     // Normal shooting mode
     if (shockTriggerMode_shootingMode == 0) {
       
       sensor_waitFor(PINS_SENSOR_SHOCK, SENSOR_MODE_HIGHER, shockTriggerMode_sensorLimit, 0);
       
       if(!cancelFlag) {

         camera_autofocusBegin(shockTriggerMode_autofocusTime); 
         camera_shutterBegin(shockTriggerMode_shutterLagTime); 
          
         if (shockTriggerMode_useFlash1==0) flash_shoot(shockTriggerMode_preFlash1Time, PINS_FLASH1);
         if (shockTriggerMode_useFlash2==0) flash_shoot(shockTriggerMode_preFlash2Time, PINS_FLASH2); 
       }
     } 
     
     // Prebulb shooting mode
     if (shockTriggerMode_shootingMode == 1) {
      
       camera_autofocusBegin(shockTriggerMode_autofocusTime);
       camera_shutterBegin(shockTriggerMode_shutterLagTime); 
       
       sensor_waitFor(PINS_SENSOR_SHOCK, SENSOR_MODE_HIGHER, shockTriggerMode_sensorLimit, 0);
               
       if(!cancelFlag) {
 
         if (shockTriggerMode_useFlash1==0) flash_shoot(shockTriggerMode_preFlash1Time, PINS_FLASH1);
         if (shockTriggerMode_useFlash2==0) flash_shoot(shockTriggerMode_preFlash2Time, PINS_FLASH2); 
       }        
     }  
     
     // Mirror lock-up shooting mode
     if (shockTriggerMode_shootingMode == 3) {
              
       for(boolean result = false; result == false;  ){      
         camera_mirrorLockUp(shockTriggerMode_autofocusTime, shockTriggerMode_shutterLagTime);
         result = sensor_waitFor(PINS_SENSOR_SHOCK, SENSOR_MODE_HIGHER, shockTriggerMode_sensorLimit, DEVICES_CAMERA_MIRROR_LOCKUP_TIMELIMIT);
       }
       camera_shutterBegin(1); 
      
       if(!cancelFlag) {
         
         if (shockTriggerMode_useFlash1==0) flash_shoot(shockTriggerMode_preFlash1Time, PINS_FLASH1);
         if (shockTriggerMode_useFlash2==0) flash_shoot(shockTriggerMode_preFlash2Time, PINS_FLASH2); 
       }          
     }
    
     // Common for all shooting modes
     camera_shutterEnd(shockTriggerMode_preCloseTime); 
     camera_autofocusEnd();
     myGLCD.print("                             ",10,50);
     cancelFlag=myTouch.dataAvailable();
     if(!cancelFlag) delay(shockTriggerMode_interCicleTime);       
   }
     

}
