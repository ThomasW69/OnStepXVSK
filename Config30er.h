//######################################################################################################################################
//30er  30er  30er  30er  30er  30er  30er  30er  30er  30er  30er  30er  30er  30er  30er  30er  30er  30er  30er  30er  30er  ########
//######################################################################################################################################

#define  CONFIG_NAME "Steuerung 30er"

// =================================================================================================================================
// MOUNT ===========================================================================================================================

// Driver models (Step/Dir and Servo) many have specific requirements so be sure to follow the link below to help learn about these.
// Typically: A4988, DRV8825, LV8729, S109, TMC2130, TMC5160, TMC2209, etc.


// MOUNT -------------------------------------------------------- see https://onstep.groups.io/g/main/wiki/Configuration_Mount#MOUNT
#define MOUNT_TYPE                GEM_TA //    GEM, GEM         German Equatorial Mount, etc. that need meridian flips.     <-Req'd
										//         GEM_TA      GEM w/tangent arm Declination
										//         GEM_TAC     GEM w/tangent arm Declination and geometry correction
										//         FORK        Fork Mount
										//         FORK_TA     FORK w/tangent arm Declination
										//         FORK_TAC    FORK w/tangent arm Declination and geometry correction
										//         ALTAZM      Altitude/Azimuth Mount, Dobsonians, etc.
										//         ALTAZM_UNL  ALTAZM w/unlimited Azimuth motion


#define MOUNT_COORDS          TOPOCENTRIC // ...RIC, Applies refraction to coordinates to/from OnStep, except exactly         Infreq
										  //              at the poles. Use TOPO_STRICT to apply refraction even in that case.
										  //              Use OBSERVED_PLACE for no refraction.

#define MOUNT_ENABLE_IN_STANDBY       OFF //    OFF, ON Enables mount motor drivers while in standby.                         Infreq



// AXIS1 RA/AZM -------------------------------------------------------- see https://onstep.groups.io/g/main/wiki/Configuration_Axes
#define AXIS1_DRIVER_MODEL        TMC2209 //    OFF, Enter motor driver model (above) in both axes to activate the mount.    <-Often

// If runtime axis settings are enabled changes in the section below may be ignored unless you reset to defaults:
// \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ 
//neue Motor
//Achtung. hier gibt es en MAximum von 
#define AXIS1_STEPS_PER_DEGREE      23000.0 //  12800, n. Number of steps per degree:                                          <-Req'd
										  //         n = (stepper_steps * micro_steps * overall_gear_reduction)/360.0
										  //         n = (200*1*100*414)/360

//Alter Motor
//#define AXIS1_STEPS_PER_DEGREE      46000 //  12800, n. Number of steps per degree:                                          <-Req'd
										  //         n = (stepper_steps * micro_steps * overall_gear_reduction)/360.0
										  //         n = (200*16*12,5*414)/360


#define AXIS1_REVERSE                 OFF //    OFF, ON Reverses movement direction, or reverse wiring instead to correct.   <-Often
#define AXIS1_LIMIT_MIN              -360 //   -180, n. Where n= -90..-360 (degrees.) Minimum "Hour Angle" or Azimuth.        Adjust
#define AXIS1_LIMIT_MAX               360 //    180, n. Where n=  90.. 360 (degrees.) Maximum "Hour Angle" or Azimuth.        Adjust

// 16 Microsteps für alten Motor
// //#define AXIS1_DRIVER_MICROSTEPS       16  //    OFF, n. Microstep mode when tracking.                                        <-Req'd
// Keine Microsteps für neuen Motor
#define AXIS1_DRIVER_MICROSTEPS       OFF  //    OFF, n. Microstep mode when tracking.                                        <-Req'd

#define AXIS1_DRIVER_MICROSTEPS_GOTO  OFF   //    OFF, n. Microstep mode used during slews. OFF uses _DRIVER_MICROSTEPS.        Option
#define MOUNT_COORDS_MEMORY           OFF //    OFF, ON Remembers approximate mount coordinates across power cycles.          Option
									   //         Requires FRAM NV memory and the mount must not move while powered down.

// for TMC2130, TMC5160, TMC2209, TMC2226 STEP/DIR driver models:
#define AXIS1_DRIVER_IHOLD            500 //    OFF, n, (mA.) Current during standstill. OFF uses IRUN/2.0                    Option
#define AXIS1_DRIVER_IRUN             1000 //    OFF, n, (mA.) Current during tracking, appropriate for stepper/driver/etc.    Option
#define AXIS1_DRIVER_IGOTO            1500 //    OFF, n, (mA.) Current during slews. OFF uses IRUN.                            Option
// /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /

#define AXIS1_DRIVER_STATUS           ON //    OFF, ON, HIGH, or LOW.  For driver status info/fault detection.               Option

#define AXIS1_DRIVER_DECAY            STEALTHCHOP //    OFF, Tracking decay mode default override. TMC default is STEALTHCHOP.        Infreq
#define AXIS1_DRIVER_DECAY_GOTO       SPREADCYCLE //    OFF, Decay mode goto default override. TMC default is SPREADCYCLE.            Infreq

#define AXIS1_POWER_DOWN              OFF //    OFF, ON Powers off 30sec after movement stops or 10min after last<=1x guide.  Infreq

#define AXIS1_SENSE_HOME              OFF //    OFF, HIGH or LOW enables & state clockwise home position, as seen from front. Option
#define AXIS1_SENSE_LIMIT_MIN LIMIT_SENSE // ...NSE, HIGH or LOW state on limit sense switch stops movement.                  Option
#define AXIS1_SENSE_LIMIT_MAX LIMIT_SENSE // ...NSE, HIGH or LOW state on limit sense switch stops movement.                  Option
										//         Digital, optionally add: |HYST(n) Where n=0..1023 stability time in ms.
										//         Analog capable sense inputs also allow adding:
										//         |THLD(n) Where n=1..1023 (ADU) for Analog threshold.
										//         |HYST(n) Where n=0..1023 (ADU) for +/- Hystersis range.

// AXIS2 DEC/ALT ------------------------------------------------------- see https://onstep.groups.io/g/main/wiki/Configuration_Axes
#define AXIS2_DRIVER_MODEL            TMC2209 //    OFF, Enter motor driver model (above) in both axes to activate the mount.    <-Often

// If runtime axis settings are enabled changes in the section below may be ignored unless you reset to defaults:
// \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/
#define AXIS2_STEPS_PER_DEGREE      43333.33333 //  12800, n. Number of steps per degree:                                          <-Req'd
// #define AXIS2_STEPS_PER_DEGREE      21666 //  12800, n. Number of steps per degree:                                          <-Req'd
										 //         n = (stepper_steps * micro_steps * overall_gear_reduction)/360.0
#define AXIS2_STEPS_PER_DEGREE2     23555.55556 //  12800, n. Number of steps per degree:                                          <-Req'd
										//         n = (stepper_steps * micro_steps * overall_gear_reduction)/360.0
#define AXIS2_REVERSE                 ON //    OFF, ON Reverses movement direction, or reverse wiring instead to correct.   <-Often
//Limits f�r 30er
#define AXIS2_LIMIT_MIN               -5 //    -90, n. Where n=-90..0 (degrees.) Minimum allowed Declination or Altitude.    Infreq
#define AXIS2_LIMIT_MAX                5 //     90, n. Where n=0..90 (degrees.) Maximum allowed Declination or Altitude.     Infreq
//Limits f�r Schiefspiegler
#define AXIS2_LIMIT_MIN2               -6.5 //    -90, n. Where n=-90..0 (degrees.) Minimum allowed Declination or Altitude.    Infreq
#define AXIS2_LIMIT_MAX2                6.5 //     90, n. Where n=0..90 (degrees.) Maximum allowed Declination or Altitude.     Infreq

#define AXIS2_DRIVER_MICROSTEPS       16 //    OFF, n. Microstep mode when tracking.                                        <-Req'd
#define AXIS2_DRIVER_MICROSTEPS_GOTO  8 //    OFF, n. Microstep mode used during slews. OFF uses _DRIVER_MICROSTEPS.        Option

// for TMC2130, TMC5160, TMC2209, TMC2226 STEP/DIR driver models:
#define AXIS2_DRIVER_IHOLD            500 //    OFF, n, (mA.) Current during standstill. OFF uses IRUN/2.0                    Option
#define AXIS2_DRIVER_IRUN             500 //    OFF, n, (mA.) Current during tracking, appropriate for stepper/driver/etc.    Option
#define AXIS2_DRIVER_IGOTO            1500 //    OFF, n, (mA.) Current during slews. OFF uses IRUN.                            Option
// /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /

#define AXIS2_DRIVER_STATUS           ON //    OFF, ON, HIGH, or LOW.  Polling for driver status info/fault detection.       Option

#define AXIS2_DRIVER_DECAY            STEALTHCHOP //    OFF, Tracking decay mode default override. TMC default is STEALTHCHOP.        Infreq
#define AXIS2_DRIVER_DECAY_GOTO       STEALTHCHOP //    OFF, Decay mode goto default override. TMC default is SPREADCYCLE.            Infreq

#define AXIS2_POWER_DOWN              ON  //    OFF, ON Powers off 30sec after movement stops or 10min after last<=1x guide.  Option

//#define AXIS2_TANGENT_ARM             ON
#define AXIS2_SENSE_HOME              HIGH //    OFF, HIGH or LOW enables & state clockwise home position, as seen from above. Option
#define AXIS2_SENSE_LIMIT_MIN LIMIT_SENSE // ...NSE, HIGH or LOW state on limit sense switch stops movement.                  Option
#define AXIS2_SENSE_LIMIT_MAX LIMIT_SENSE // ...NSE, HIGH or LOW state on limit sense switch stops movement.                  Option
#define AXIS2_HOME_DEFAULT             7  // angle in degrees, for the Dec or Altitude Axis.
#define AXIS2_SENSE_HOME_OFFSET        0   // offset in arc-seconds to home from the sense position
#define AXIS2_SLEW_RATE_PERCENT        1.5F //Axis 2 langsamermachen für Homing


#define SLEW_RATE_BASE_DESIRED        0.5  //    1.0, n. Desired slew rate in deg/sec. Adjustable at run-time from            <-Req'd
											//         1/2 to 2x this rate, and as MCU performace considerations require.
#define SLEW_RATE_MEMORY               ON   //    OFF, ON Remembers rates set across power cycles.                              Option
#define SLEW_ACCELERATION_DIST        5.0   //    5.0, n, (degrees.) Approx. distance for acceleration (and deceleration.)      Adjust
#define SLEW_RAPID_STOP_DIST          0.1   //    2.0, n, (degrees.) Approx. distance required to stop when a slew              Adjust
											//         is aborted or a limit is exceeded.

// PEC ------------------------------------------------------------ see https://onstep.groups.io/g/main/wiki/Configuration_Mount#PEC
//Neuer Motor
#define PEC_STEPS_PER_WORM_ROTATION     20000 	//      0, n. Steps per worm rotation (0 disables else 720 sec buffer allocated.)  <-Req'd
												//              n = (AXIS1_STEPS_PER_DEGREE*360)/reduction_final_stage
//Alter Motor
//#define PEC_STEPS_PER_WORM_ROTATION     40000 	//      0, n. Steps per worm rotation (0 disables else 720 sec buffer allocated.)  <-Req'd
												//              n = (AXIS1_STEPS_PER_DEGREE*360)/reduction_final_stage

#define PEC_SENSE                     LOW 		//    OFF, HIGH. Senses the PEC signal rising edge or use LOW for falling edge.     Option
												//         Ignored in ALTAZM mode.
#define PEC_BUFFER_SIZE_LIMIT         720 		//    720, Seconds of PEC buffer allowed.                                           Infreq




// TRACKING BEHAVIOUR ---------------------------------------- see https://onstep.groups.io/g/main/wiki/Configuration_Mount#TRACKING
#define TRACK_BACKLASH_RATE            20 		 //     20, n. Where n=2..50 (x sidereal rate) during backlash takeup.               Option
												 //         Too fast motors stall/gears slam or too slow and sluggish in backlash.
#define TRACK_AUTOSTART               ON 		 //    OFF, ON Start with tracking enabled.                                          Option
#define TRACK_COMPENSATION_DEFAULT    MODEL_DUAL //    OFF, No compensation or REFRACTION, REFRACTION_DUAL, MODEL, MODEL_DUAL.       Option
#define TRACK_COMPENSATION_MEMORY     ON 		 //    OFF, ON Remembers refraction/pointing model compensated tracking settings.    Option



#define GOTO_FEATURE                   ON //     ON, Use OFF to disable mount Goto features.                                  Infreq
#define GOTO_OFFSET                   0.0 //   0.25, Offset in deg's for goto target unidirectional approach, 0.0 disables    Adjust
#define GOTO_OFFSET_ALIGN             OFF //    OFF, ON skips final phase of goto for align stars so user tends to approach   Option
										  //         from the correct direction when centering.

// PIER SIDE BEHAVIOUR --------------------------------------- see https://onstep.groups.io/g/main/wiki/Configuration_Mount#PIERSIDE
#define MFLIP_SKIP_HOME               ON   //    OFF, ON Goto directly to the destination without visiting home position.      Option
#define MFLIP_AUTOMATIC_DEFAULT       OFF  //    OFF, ON Start with automatic meridian flips enabled.                          Option
#define MFLIP_AUTOMATIC_MEMORY        ON   //    OFF, ON Remember automatic meridian flip setting across power cycles.         Option
#define MFLIP_PAUSE_HOME_DEFAULT      OFF  //    OFF, ON Start with meridian flip pause at home enabed.                        Infreq
#define MFLIP_PAUSE_HOME_MEMORY       OFF  //    OFF, ON Remember meridian flip pause at home setting across power cycles.     Infreq
#define PIER_SIDE_SYNC_CHANGE_SIDES   OFF  //    OFF, ON Allows sync to change pier side, for GEM mounts.                      Option
#define PIER_SIDE_PREFERRED_DEFAULT   BEST //    BEST, BEST Stays on current side if possible. EAST or WEST switch if possible. Option
#define PIER_SIDE_PREFERRED_MEMORY    OFF   //    OFF, ON Remember preferred pier side setting across power cycles.             Option


// ALIGN -------------------------------------------------------- see https://onstep.groups.io/g/main/wiki/Configuration_Mount#ALIGN
#define ALIGN_AUTO_HOME               ON //    OFF, ON uses home switches to find home first when starting an align.         Option
#define ALIGN_MODEL_MEMORY            OFF //    OFF, ON Restores any pointing model saved in NV at startup.                   Option
#define ALIGN_MAX_STARS              AUTO //   AUTO, Uses HAL specified default (either 6 or 9 stars.)                        Infreq
										//         Or use n. Where n=1 (for Sync only) or 3 to 9 (for Goto Assist.)

// =================================================================================================================================
// ROTATOR =========================================================================================================================

// Driver models (Step/Dir and Servo) many have specific requirements so be sure to follow the link below to help learn about these.
// Typically: A4988, DRV8825, LV8729, S109, TMC2130S, etc.

// AXIS3 ROTATOR ---------------------------------------------------- see https://onstep.groups.io/g/main/wiki/Configuration_Rotator
#define AXIS3_DRIVER_MODEL            TMC2209 //    OFF, Enter motor driver model (above) to activate the rotator.                Option
#define AXIS3_SLEW_RATE_BASE_DESIRED  1.0 //    1.0, n. Desired slew rate in deg/sec. Adjustable at run-time from            <-Req'd
										  //         1/2 to 2x this rate, and as performance considerations require.

// If runtime axis settings are enabled changes in the section below may be ignored unless you reset to defaults:
// \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/
#define AXIS3_STEPS_PER_DEGREE       64.0 //   64.0, n. Number of steps per degree for rotator/de-rotator.                    Adjust
										  //         Alt/Az de-rotation: n = (num_circumference_pixels * 2)/360, minimum
#define AXIS3_REVERSE                 OFF //    OFF, ON Reverses movement direction, or reverse wiring instead to correct.    Option
#define AXIS3_LIMIT_MIN                 0 //      0, n. Where n=-360..0 (degrees.) Minimum allowed rotator angle.             Infreq
#define AXIS3_LIMIT_MAX               360 //    360, n. Where n=0..360 (degrees.) Maximum allowed rotator angle.              Infreq

#define AXIS3_DRIVER_MICROSTEPS       OFF //    OFF, n. Microstep mode when tracking.                                         Option
#define AXIS3_DRIVER_MICROSTEPS_GOTO  OFF //    OFF, n. Microstep mode used during slews. OFF uses _DRIVER_MICROSTEPS.        Option

// for TMC2130, TMC5160, TMC2209, TMC2226 STEP/DIR driver models:
#define AXIS3_DRIVER_IHOLD            500 //    OFF, n, (mA.) Current during standstill. OFF uses IRUN/2.0                    Option
#define AXIS3_DRIVER_IRUN             700 //    OFF, n, (mA.) Current during tracking, appropriate for stepper/driver/etc.    Option
#define AXIS3_DRIVER_IGOTO            1000 //    OFF, n, (mA.) Current during slews. OFF uses IRUN.                            Option
// /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /

#define AXIS3_DRIVER_STATUS           OFF //    OFF, ON, HIGH, or LOW.  For driver status info/fault detection.               Option

#define AXIS3_DRIVER_DECAY            STEALTHCHOP //    OFF, Tracking decay mode default override. TMC default is STEALTHCHOP.        Infreq
#define AXIS3_DRIVER_DECAY_GOTO       SPREADCYCLE //    OFF, Decay mode goto default override. TMC default is SPREADCYCLE.            Infreq

#define AXIS3_POWER_DOWN              ON //    OFF, ON Powers off 30 seconds after movement stops.                           Option

#define AXIS3_SENSE_HOME              OFF //    OFF, HIGH or LOW enables & state clockwise home position, as seen from above. Option
#define AXIS3_SENSE_LIMIT_MIN         OFF //    OFF, HIGH or LOW state on limit sense switch stops movement.                  Option
#define AXIS3_SENSE_LIMIT_MAX         OFF //    OFF, HIGH or LOW state on limit sense switch stops movement.                  Option

// =================================================================================================================================
// FOCUSERS ========================================================================================================================

// Driver models (Step/Dir and Servo) many have specific requirements so be sure to follow the link below to help learn about these.
// Typically: A4988, DRV8825, LV8729, S109, TMC2130S, etc.

	// AXIS4 FOCUSER 1 -------------------------------------------------- see https://onstep.groups.io/g/main/wiki/Configuration_Focuser
#define AXIS4_DRIVER_MODEL            TMC2209 //    OFF, Enter motor driver model (above) to activate the focuser.                Option
#define AXIS4_SLEW_RATE_BASE_DESIRED  1000    //    500, n, Where n=200..5000 (um/s.) Adjustable at run-time from                <-Req'd
																	//         1/2 to 2x this rate, and as performance considerations require.
#define AXIS4_SLEW_RATE_MINIMUM        20     //     20, n. Where n=5..200 (um/s.) Minimum microns/second.                        Adjust

// If runtime axis settings are enabled changes in the section below may be ignored unless you reset to defaults:
// \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/ \/
#define AXIS4_STEPS_PER_MICRON        0.55 //    0.5, n. Steps per micrometer. Figure this out by testing or other means.      Adjust
#define AXIS4_REVERSE                 ON   //    OFF, ON Reverses movement direction, or reverse wiring instead to correct.    Option
#define AXIS4_LIMIT_MIN                 0  //      0, n. Where n=0..500 (millimeters.) Minimum allowed position.               Adjust
#define AXIS4_LIMIT_MAX                76  //     50, n. Where n=0..500 (millimeters.) Maximum allowed position.               Adjust

#define AXIS4_DRIVER_MICROSTEPS       16   //    OFF, n. Microstep mode when tracking.                                         Option
#define AXIS4_DRIVER_MICROSTEPS_GOTO  4    //    OFF, n. Microstep mode used during slews. OFF uses _DRIVER_MICROSTEPS.        Option

// for TMC2130, TMC5160, TMC2209, TMC2226 STEP/DIR driver models:
#define AXIS4_DRIVER_IHOLD            500  //    OFF, n, (mA.) Current during standstill. OFF uses IRUN/2.0                    Option
#define AXIS4_DRIVER_IRUN             1200 //    OFF, n, (mA.) Current during tracking, appropriate for stepper/driver/etc.    Option
#define AXIS4_DRIVER_IGOTO            1200 //    OFF, n, (mA.) Current during slews. OFF uses IRUN.                            Option
// /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /\ /

#define AXIS4_DRIVER_STATUS           OFF //    OFF, ON, HIGH, or LOW.  For driver status info/fault detection.               Option

#define AXIS4_DRIVER_DECAY            STEALTHCHOP //    OFF, Tracking decay mode default override. TMC default is STEALTHCHOP.        Infreq
#define AXIS4_DRIVER_DECAY_GOTO       STEALTHCHOP //    OFF, Decay mode goto default override. TMC default is SPREADCYCLE.            Infreq

#define AXIS4_POWER_DOWN              OFF //    OFF, ON Powers off 30 seconds after movement stops.                           Option

#define AXIS4_SENSE_HOME              OFF //    OFF, HIGH or LOW enables & state clockwise home position, as seen from above. Option
#define AXIS4_SENSE_LIMIT_MIN         OFF //    OFF, HIGH or LOW state on limit sense switch stops movement.                  Option
#define AXIS4_SENSE_LIMIT_MAX         OFF //    OFF, HIGH or LOW state on limit sense switch stops movement.                  Option

#define AXIS4_ACCELERATION_TIME       2   
#define AXIS4_RAPID_STOP_TIME         0.3
#define AXIS4 HOME_DEFAULT            MINIMUM

// AXIS5 FOCUSER 2 -----------------------------------------------------------------------------------------------------------------
// Up to 6 focusers can be present (AXIS4 to AXIS9) simply copy the above text for focuser 1 and rename to AXIS5_ for focuser 2, etc

// FOCUSER TEMPERATURE ---------------------------------------------- see https://onstep.groups.io/g/main/wiki/Configuration_Focuser
#define FOCUSER_TEMPERATURE           OFF //    OFF, THERMISTOR or n. Where n is the ds18b20 s/n for focuser temp.            Adjust


//######################################################################################################################################
//30er  30er  30er  30er  30er  30er  30er  30er  30er  30er  30er  30er  30er  30er  30er  30er  30er  30er  30er  30er  30er  ########
//######################################################################################################################################
