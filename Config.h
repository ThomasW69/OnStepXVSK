#include <functional>
/* ---------------------------------------------------------------------------------------------------------------------------------
 * Configuration for OnStepX
 *
 *          For more information on setting OnStep up see http://www.stellarjourney.com/index.php?r=site/equipment_onstep 
 *                      and join the OnStep Groups.io at https://groups.io/g/onstep
 * 
 *           *** Read the compiler warnings and errors, they are there to help guard against invalid configurations ***
 *
 * ---------------------------------------------------------------------------------------------------------------------------------
 * ADJUST THE FOLLOWING TO CONFIGURE YOUR CONTROLLER FEATURES ----------------------------------------------------------------------
 * <-Req'd = always must set, <-Often = usually must set, Option = optional, Adjust = adjust as req'd, Infreq = infrequently changed
*/
//      Parameter Name              Value   Default  Notes                                                                      Hint

// =================================================================================================================================

# define CONFIG_MODE M30er      //MDefault, M30er, MKuppel Welche Konfiguration soll geladen werden

// CONTROLLER ======================================================================================================================
// für den Experimentellen Modus des Ethernets
#define OPERATIONAL_MODE ETHERNET_TEENSY41
#define STA_ENABLED                true                   //       false, Wifi Station Enabled.                                               Adjust
#define STA_DHCP_ENABLED           false                    //       false, Wifi Station DHCP Enabled.                                          Adjust
#define STA_IP_ADDR    {192,168,178,160}                     // ..168,1,55}, Wifi Station/Ethernet IP Address.                                   Adjust
#define STA_GW_ADDR      {192,168,178,1}                    // ..,168,1,1}, Wifi Station/Ethernet GATEWAY Address.                              Adjust
#define STA_SN_MASK      {255,255,255,0}                    // ..55,255,0}, Wifi Station/Ethernet SUBNET Mask.                                  Adjust
#define STA1_HOST_NAME   "OnStep"
#define STA1_TARGET_IP_ADDR {192,168,178,160}


// PINMAP ------------------------------------------------- see https://onstep.groups.io/g/main/wiki/Configuration_Controller#PINMAP
#define PINMAP                     MaxPCB4// for Teensy4.1 w/TMC2209 support //    OFF, Choose from: MiniPCB, MiniPCB2, MaxPCB2, MaxESP3, CNC3, STM32Blue,      <-Req'd
                                          //         MaxSTM3, FYSETC_S6_2, etc.  Other boards and more info. in ~/src/Constants.h
// SERIAL PORT COMMAND CHANNELS --------------------- see https://onstep.groups.io/g/main/wiki/Configuration_Controller#SERIAL_PORTS
#define SERIAL_A_BAUD_DEFAULT       57600 //   9600, n. Where n=9600,19200,57600,115200,230400,460800 (common baud rates.)    Infreq
#define SERIAL_B_BAUD_DEFAULT       57600 //   9600, n. Baud rate as above. See (src/pinmaps/) for Serial port assignments.   Infreq
#define SERIAL_B_ESP_FLASHING         OFF //    OFF, ON Upload ESP8266 WiFi firmware through SERIAL_B with :ESPFLASH# cmd.    Option
#define SERIAL_C_BAUD_DEFAULT       57600 //    OFF, n. Baud rate as above. See (src/pinmaps/) for Serial port assignments.   Infreq
//#define SERIAL_D_BAUD_DEFAULT         OFF //    OFF, n. Baud rate as above. See (src/pinmaps/) for Serial port assignments.   Infreq
//#define SERIAL_E_BAUD_DEFAULT         OFF //    OFF, n. Baud rate as above. See (src/pinmaps/) for Serial port assignments.   Infreq
#define SERIAL_RADIO                  OFF //    OFF, Use BLUETOOTH or WIFI_ACCESS_POINT or WIFI_STATION (ESP32 only.)         Option

// STATUS --------------------------------------------- see https://onstep.groups.io/g/main/wiki/Configuration_Controller#STATUS_LED
#define STATUS_LED                    ON //    OFF, Steady illumination if no error, blinks w/error code otherwise.          Option

// RETICLE CONTROL ------------------------------- see https://onstep.groups.io/g/main/wiki/Configuration_Controller#RETICLE_CONTROL
#define RETICLE_LED_DEFAULT           OFF //    OFF, n. Where n=0..255 (0..100%) activates feature sets default brightness.   Option
#define RETICLE_LED_MEMORY            OFF //    OFF, ON Remember reticle brightness across power cycles.                      Option
#define RETICLE_LED_INVERT            OFF //    OFF, ON Inverts control for cases where 0V is max brightness.                 Option

// WEATHER SENSOR --------------------------------- see https://onstep.groups.io/g/main/wiki/Configuration_Controller#WEATHER_SENSOR
#define WEATHER                       BME280_0x76 //    OFF, BME280 (I2C 0x77,) BME280_0x76, BME280_SPI (see pinmap for CS.)          Option
                                          //         BMP280 (I2C 0x77,) BMP280_0x76, BMP280_SPI (see pinmap for CS.)
                                          //         BME280 or BMP280 for temperature, pressure.  BME280 for humidity also.

// SIGNALING ------------------------------------------- see https://onstep.groups.io/g/main/wiki/Configuration_Controller#SIGNALING
#define STEP_WAVE_FORM             SQUARE // SQUARE, PULSE Step signal wave form faster rates. SQUARE best signal integrity.  Adjust
                                          //         Applies to all axes.

// NON-VOLATILE MEMORY ---------------------------------------- see https://onstep.groups.io/g/main/wiki/Configuration_Controller#NV
#define NV_DRIVER              NV_DEF // NV_DEF, Use platforms default non-volatile device to remember runtime settings.  Option


//Hier die entsprechenden konfigurationen für die Hardware laden
#if CONFIG_MODE == MKuppel
  #include "ConfigKuppel.h"
#elif CONFIG_MODE == M30er
  #include "Config30er.h"
#else CONFIG_MODE == MDefault
  #include "ConfigDefault.h"     
#endif



//Allgemeine Einstellungen
// 
// TIME AND LOCATION ---------------------------------------------- see https://onstep.groups.io/g/main/wiki/Configuration_Mount#TLS
#define TIME_LOCATION_SOURCE          GPS //    OFF, DS3231 (I2C,) SD3031 (I2C,) TEENSY (T3.2 etc,) GPS, or NTP source.       Option
                                          //         Provides Date/Time, and if available, PPS & Lat/Long also.
#define TIME_LOCATION_PPS_SENSE       OFF //    OFF, HIGH senses PPS (pulse per second,) signal rising edge, or use LOW for   Option
                                          //         falling edge, or use BOTH for rising and falling edges.
#define TIME_LOCATION_SOURCE_FALLBACK  TEENSY

#define SERIAL_GPS Serial5
#define SERIAL_GPS_BAUD 9600
#define GPS_MIN_WAIT_MINUTES 0;

// NON-VOLATILE MEMORY --------------------------------------------- see https://onstep.groups.io/g/main/wiki/Configuration_Mount#NV

 
// STATUS ------------------------------------------------------ see https://onstep.groups.io/g/main/wiki/Configuration_Mount#STATUS
#define STATUS_MOUNT_LED              ON //    OFF, ON Flashes proportional to rate of movement or solid on for slews.       Option
#define STATUS_BUZZER                 2500 //    OFF, ON, n. Where n=100..6000 (Hz freq.) for speaker. ON for piezo buzzer.    Option
#define STATUS_BUZZER_DEFAULT         ON //    OFF, ON default starts w/buzzer enabled.                                      Option
#define STATUS_BUZZER_MEMORY          ON //    OFF, ON to remember buzzer setting across power cycles.                       Option

// ST4 INTERFACE -------------------------------------------------- see https://onstep.groups.io/g/main/wiki/Configuration_Mount#ST4
// *** It is up to you to verify the interface meets the electrical specifications of any connected device, use at your own risk ***
#define ST4_INTERFACE                 OFF //    OFF, ON enables interface. <= 1X guides unless hand control mode.             Option
                                          //         During goto btn press: aborts slew or continue meridian flip pause home
#define ST4_HAND_CONTROL               OFF //     ON, ON for hand controller special features and SHC support.                 Option
                                          //         Hold [E]+[W] btns >2s: Guide rate   [E]-  [W]+  [N] trk on/off [S] sync
                                          //         Hold [N]+[S] btns >2s: Usr cat item [E]-  [W]+  [N] goto [S] snd on/off
#define ST4_HAND_CONTROL_FOCUSER       OFF //     ON, ON alternate to above: Focuser move [E]f1 [W]f2 [N]-     [S]+            Option

// GUIDING BEHAVIOUR ------------------------------------------ see https://onstep.groups.io/g/main/wiki/Configuration_Mount#GUIDING
#define GUIDE_TIME_LIMIT               120 //     10, n. Time limit n=0..120 seconds. Use 0 to disable.                        Adjust
#define GUIDE_DISABLE_BACKLASH        ON //    OFF, Disable backlash takeup during guiding at <= 1X.                         Option

// LIMITS ------------------------------------------------------ see https://onstep.groups.io/g/main/wiki/Configuration_Mount#LIMITS
#define LIMIT_SENSE                   OFF //    OFF, HIGH or LOW state on limit sense switch stops movement.                  Option
#define LIMIT_STRICT                  ON //    OFF, disables limits until unpark goto or sync. ON enables limits at startup. Option
                                          //         note that ON also disables all motion until date/time are set.

// PARKING ---------------------------------------------------- see https://onstep.groups.io/g/main/wiki/Configuration_Mount#PARKING
#define PARK_SENSE                    OFF //    OFF, HIGH or LOW state indicates mount is in the park orientation.            Option
#define PARK_SIGNAL                   OFF //    OFF, HIGH or LOW state park input signal triggers parking.                    Option
#define PARK_STATUS                   OFF //    OFF, signals with a HIGH or LOW state when successfully parked.               Option 
#define PARK_STRICT                   OFF //    OFF, ON Un-parking is only allowed if successfully parked.                    Option




// =================================================================================================================================
// AUXILIARY FEATURES ==============================================================================================================

// FEATURES ------------------------------------------------------------- see https://onstep.groups.io/g/main/wiki/Configuration_Aux
// Note: Temporarily set DEBUG mode to VERBOSE and use "FEATURE1_TEMP DS1820" to list the DS18B20 device serial numbers.

#define FEATURE1_PURPOSE              OFF //    OFF, SWITCH, MOMENTARY_SWITCH, ANALOG_OUT, DEW_HEATER, INTERVALOMETER.        Option
#define FEATURE1_NAME          "FEATURE1" // "FE..", Name of feature being controlled.                                        Adjust
#define FEATURE1_TEMP                 OFF //    OFF, THERMISTOR or n. Where n is the ds18b20 s/n. For DEW_HEATER temperature. Adjust
#define FEATURE1_PIN                  OFF //    OFF, AUX for auxiliary pin, n. Where n is the pin#.                           Adjust
#define FEATURE1_VALUE_DEFAULT        OFF //    OFF, ON, n. Where n=0..255 for ANALOG_OUT purpose.                            Adjust
#define FEATURE1_VALUE_MEMORY         OFF //    OFF, ON remembers SWITCH, ANALOG_OUT, DEW_HEATER state across power cycles.   Adjust
#define FEATURE1_ON_STATE            HIGH //   HIGH, LOW to invert so "ON" is 0V and "OFF" is Vcc (3.3V usually.)             Adjust

#define FEATURE2_PURPOSE              OFF //    OFF, SWITCH, MOMENTARY_SWITCH, ANALOG_OUT, DEW_HEATER, INTERVALOMETER.        Option
#define FEATURE2_NAME          "FEATURE2" // "FE..", Name of feature being controlled.                                        Adjust
#define FEATURE2_TEMP                 OFF //    OFF, THERMISTOR or n. Where n is the ds18b20 s/n. For DEW_HEATER temperature. Adjust
#define FEATURE2_PIN                  OFF //    OFF, AUX for auxiliary pin, n. Where n is the pin#.                           Adjust
#define FEATURE2_VALUE_DEFAULT        OFF //    OFF, ON, n. Where n=0..255 for ANALOG_OUT purpose.                            Adjust
#define FEATURE2_VALUE_MEMORY         OFF //    OFF, ON remembers SWITCH, ANALOG_OUT, DEW_HEATER state across power cycles.   Adjust
#define FEATURE2_ON_STATE            HIGH //   HIGH, LOW to invert so "ON" is 0V and "OFF" is Vcc (3.3V usually.)             Adjust

#define FEATURE3_PURPOSE              OFF //    OFF, SWITCH, MOMENTARY_SWITCH, ANALOG_OUT, DEW_HEATER, INTERVALOMETER.        Option
#define FEATURE3_NAME          "FEATURE3" // "FE..", Name of feature being controlled.                                        Adjust
#define FEATURE3_TEMP                 OFF //    OFF, THERMISTOR or n. Where n is the ds18b20 s/n. For DEW_HEATER temperature. Adjust
#define FEATURE3_PIN                  OFF //    OFF, AUX for auxiliary pin, n. Where n is the pin#.                           Adjust
#define FEATURE3_VALUE_DEFAULT        OFF //    OFF, ON, n. Where n=0..255 for ANALOG_OUT purpose.                            Adjust
#define FEATURE3_VALUE_MEMORY         OFF //    OFF, ON remembers SWITCH, ANALOG_OUT, DEW_HEATER state across power cycles.   Adjust
#define FEATURE3_ON_STATE            HIGH //   HIGH, LOW to invert so "ON" is 0V and "OFF" is Vcc (3.3V usually.)             Adjust

#define FEATURE4_PURPOSE              OFF //    OFF, SWITCH, MOMENTARY_SWITCH, ANALOG_OUT, DEW_HEATER, INTERVALOMETER.        Option
#define FEATURE4_NAME          "FEATURE4" // "FE..", Name of feature being controlled.                                        Adjust
#define FEATURE4_TEMP                 OFF //    OFF, THERMISTOR or n. Where n is the ds18b20 s/n. For DEW_HEATER temperature. Adjust
#define FEATURE4_PIN                  OFF //    OFF, AUX for auxiliary pin, n. Where n is the pin#.                           Adjust
#define FEATURE4_VALUE_DEFAULT        OFF //    OFF, ON, n. Where n=0..255 for ANALOG_OUT purpose.                            Adjust
#define FEATURE4_VALUE_MEMORY         OFF //    OFF, ON remembers SWITCH, ANALOG_OUT, DEW_HEATER state across power cycles.   Adjust
#define FEATURE4_ON_STATE            HIGH //   HIGH, LOW to invert so "ON" is 0V and "OFF" is Vcc (3.3V usually.)             Adjust

#define FEATURE5_PURPOSE              OFF //    OFF, SWITCH, MOMENTARY_SWITCH, ANALOG_OUT, DEW_HEATER, INTERVALOMETER.        Option
#define FEATURE5_NAME          "FEATURE5" // "FE..", Name of feature being controlled.                                        Adjust
#define FEATURE5_TEMP                 OFF //    OFF, THERMISTOR or n. Where n is the ds18b20 s/n. For DEW_HEATER temperature. Adjust
#define FEATURE5_PIN                  OFF //    OFF, AUX for auxiliary pin, n. Where n is the pin#.                           Adjust
#define FEATURE5_VALUE_DEFAULT        OFF //    OFF, ON, n. Where n=0..255 for ANALOG_OUT purpose.                            Adjust
#define FEATURE5_VALUE_MEMORY         OFF //    OFF, ON remembers SWITCH, ANALOG_OUT, DEW_HEATER state across power cycles.   Adjust
#define FEATURE5_ON_STATE            HIGH //   HIGH, LOW to invert so "ON" is 0V and "OFF" is Vcc (3.3V usually.)             Adjust

#define FEATURE6_PURPOSE              OFF //    OFF, SWITCH, MOMENTARY_SWITCH, ANALOG_OUT, DEW_HEATER, INTERVALOMETER.        Option
#define FEATURE6_NAME          "FEATURE6" // "FE..", Name of feature being controlled.                                        Adjust
#define FEATURE6_TEMP                 OFF //    OFF, THERMISTOR or n. Where n is the ds18b20 s/n. For DEW_HEATER temperature. Adjust
#define FEATURE6_PIN                  OFF //    OFF, AUX for auxiliary pin, n. Where n is the pin#.                           Adjust
#define FEATURE6_VALUE_DEFAULT        OFF //    OFF, ON, n. Where n=0..255 for ANALOG_OUT purpose.                            Adjust
#define FEATURE6_VALUE_MEMORY         OFF //    OFF, ON remembers SWITCH, ANALOG_OUT, DEW_HEATER state across power cycles.   Adjust
#define FEATURE6_ON_STATE            HIGH //   HIGH, LOW to invert so "ON" is 0V and "OFF" is Vcc (3.3V usually.)             Adjust

#define FEATURE7_PURPOSE              OFF //    OFF, SWITCH, MOMENTARY_SWITCH, ANALOG_OUT, DEW_HEATER, INTERVALOMETER.        Option
#define FEATURE7_NAME          "FEATURE7" // "FE..", Name of feature being controlled.                                        Adjust
#define FEATURE7_TEMP                 OFF //    OFF, THERMISTOR or n. Where n is the ds18b20 s/n. For DEW_HEATER temperature. Adjust
#define FEATURE7_PIN                  OFF //    OFF, AUX for auxiliary pin, n. Where n is the pin#.                           Adjust
#define FEATURE7_VALUE_DEFAULT        OFF //    OFF, ON, n. Where n=0..255 for ANALOG_OUT purpose.                            Adjust
#define FEATURE7_VALUE_MEMORY         OFF //    OFF, ON remembers SWITCH, ANALOG_OUT, DEW_HEATER state across power cycles.   Adjust
#define FEATURE7_ON_STATE            HIGH //   HIGH, LOW to invert so "ON" is 0V and "OFF" is Vcc (3.3V usually.)             Adjust

#define FEATURE8_PURPOSE              OFF //    OFF, SWITCH, MOMENTARY_SWITCH, ANALOG_OUT, DEW_HEATER, INTERVALOMETER.        Option
#define FEATURE8_NAME          "FEATURE8" // "FE..", Name of feature being controlled.                                        Adjust
#define FEATURE8_TEMP                 OFF //    OFF, THERMISTOR or n. Where n is the ds18b20 s/n. For DEW_HEATER temperature. Adjust
#define FEATURE8_PIN                  OFF //    OFF, AUX for auxiliary pin, n. Where n is the pin#.                           Adjust
#define FEATURE8_VALUE_DEFAULT        OFF //    OFF, ON, n. Where n=0..255 for ANALOG_OUT purpose.                            Adjust
#define FEATURE8_VALUE_MEMORY         OFF //    OFF, ON remembers SWITCH, ANALOG_OUT, DEW_HEATER state across power cycles.   Adjust
#define FEATURE8_ON_STATE            HIGH //   HIGH, LOW to invert so "ON" is 0V and "OFF" is Vcc (3.3V usually.)             Adjust

// ---------------------------------------------------------------------------------------------------------------------------------
#define FileVersionConfig 6
#include "Extended.config.h"
