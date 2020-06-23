//
//  OBD2PIDs.h
//  ofxAutomobile
//
//  Created by 原田誠史 on 2020/02/16.
//

#ifndef OBD2PIDs_h
#define OBD2PIDs_h

#define CRLF                              "\r\n"

#define PID_FUEL_SYSTEM_STATUS            "01 03" CRLF// Bit Encoded
#define PID_CALCULATED_ENGINE_LOAD        "01 04" CRLF// A*100/255
#define PID_COOLANT_TEMP                  "01 05" CRLF// Implemented
#define PID_SHORTTERM_FUEL_TRIM_1         "01 06" CRLF// (A-128) * 100/128
#define PID_LONGTERM_FUEL_TRIM_1          "01 07" CRLF// (A-128) * 100/128
#define PID_SHORTTERM_FUEL_TRIM_2         "01 08" CRLF// (A-128) * 100/128
#define PID_LONGTERM_FUEL_TRIM_2          "01 09" CRLF// (A-128) * 100/128
#define PID_FUEL_PRESSURE                 "01 0A" CRLF// A*3
#define PID_INTAKE_MANIFOLD_ABS_PRESSURE  "01 0B" CRLF// A
#define PID_RPM                           "01 0C" CRLF// Implemented
#define PID_SPEED                         "01 0D" CRLF// Implemented
#define PID_TIMING_ADVANCE                "01 0E" CRLF// (A-128)/2
#define PID_IAT_TEMP                      "01 0F" CRLF// Implemented
#define PID_AIR_FLOW_RATE                 "01 10" CRLF// Implemented
#define PID_THROTTLE                      "01 11" CRLF// Implemented
#define PID_COMMANDED_SECONDARY_AIR       "01 12" CRLF// Bit Encoded

// These are a special case. A contains oxygen sensor, B contains fuel trim.
#define PID_OXYGEN_SENSOR_VOLTAGE_B1_S1   "01 14" CRLF// A/200
#define PID_OXYGEN_SENSOR_VOLTAGE_B1_S2   "01 15" CRLF// A/200
#define PID_OXYGEN_SENSOR_VOLTAGE_B1_S3   "01 16" CRLF// A/200
#define PID_OXYGEN_SENSOR_VOLTAGE_B1_S4   "01 17" CRLF// A/200
#define PID_OXYGEN_SENSOR_VOLTAGE_B2_S1   "01 18" CRLF// A/200
#define PID_OXYGEN_SENSOR_VOLTAGE_B2_S2   "01 19" CRLF// A/200
#define PID_OXYGEN_SENSOR_VOLTAGE_B2_S3   "01 1A" CRLF// A/200
#define PID_OXYGEN_SENSOR_VOLTAGE_B2_S4   "01 1B" CRLF// A/200

#define PID_AUX_INPUT_STATUS              "01 1E" // "A0 == Power Take Off (PTO) status (1 == active) [A1..A7] not used"
#define PID_RUNTIME_SINCE_ENGINE_START    "01 1F" // (A*256)+B

#define PID_DISTANCE_TRAVELED_WITH_CEL    "01 21" // (A*256)+B
#define PID_FUEL_RAIL_PRESSURE_VACUUM     "01 22" // ((A*256)+B) * 0.079
#define PID_FUEL_RAIL_PRESSURE_DIRECT     "01 23" // ((A*256)+B) * 10

// 24 to 2B  (Lambda Sensors) are a special case that need expanded once implemented.

#define PID_COMMANDED_EGR                 "01 2C" // A*100/255
#define PID_EGR_ERROR                     "01 2D" // (A-128) * 100/128
#define PID_COMMANDED_EVAPORATIVE_PURGE   "01 2E" // A*100/255
#define PID_FUEL_LEVEL_INPUT              "01 2F" // A*100/255
#define PID_WARMUPS_SINCE_CODES_CLEARED   "01 30" // A
#define PID_DISTANCE_SINCE_CODES_CLEARED  "01 31" // (A*256)+B
#define PID_EVAP_SYSTEM_VAPOR_PRESSURE    "01 32" // ((A*256)+B)/4 (A and B are two's complementsigned)
#define PID_BAROMETRIC_PRESSURE           "01 33" // Implemented
#define PID_AMBIENT_TEMP                  "01 46" // Implemented

#define PID_MONITOR_STATUS_THIS_DRIVE_CYCLE       "01 41" // Bit encoded. See below
#define PID_CONTROL_MODULE_VOLTAGE                "01 42" // ((A*256)+B)/1000
#define PID_ABSOLUTE_LOAD_VALUE                   "01 43" // ((A*256)+B)*100/255
#define PID_FUEL_AIR_COMMANDED_EQUIVALENCE_RATIO  "01 44" // ((A*256)+B)/32768
#define PID_RELATIVE_THROTTLE_POSITION            "01 45" // A*100/255
#define PID_AMBIENT_AIR_TEMP                      "01 46" // A-40
#define PID_ABSOLUTE_THROTTLE_POSITION_B          "01 47" // A*100/255
#define PID_ABSOLUTE_THROTTLE_POSITION_C          "01 48" // A*100/255
#define PID_ACCELERATOR_PEDAL_POSITION_D          "01 49" // A*100/255
#define PID_ACCELERATOR_PEDAL_POSITION_E          "01 4A" // A*100/255
#define PID_ACCELERATOR_PEDAL_POSITION_F          "01 4B" // A*100/255
#define PID_COMMANDED_THROTTLE_ACTUATOR           "01 4C" // A*100/255
#define PID_TIME_RUN_WITH_MIL_ON                  "01 4D" // (A*256)+B
#define PID_TIME_SINCE_TROUBLE_CODES_CLEARED      "01 4E" // (A*256)+B

// This is a special case that needs expanded once implemented.
#define PID_MAXIMUM_VALUE_FOR_EQUIVALENCE_RATIO   "01 4F" // _OXYGEN_SENSOR_VOLTAGE,_OXYGEN_SENSOR_CURRENT,_AND_INTAKE_MANIFOLD_ABSOLUTE_PRESSURE "01 4F" // A, B, C, D*10

#define PID_MAXIMUM_VALUE_FOR_AIR_FLOW_RATE_FROM_MASS_AIR_FLOW_SENSOR "01 50" // A*10, B, C, and D are reserved for future use
#define PID_FUEL_TYPE                                                "01 51" // From fuel type table see below
#define PID_ETHANOL_FUEL_PERCENTAGE                                  "01 52" // A*100/255
#define PID_ABSOLUTE_EVAP_SYSTEM_VAPOR_PRESSURE                      "01 53" // ((A*256)+B)/200
#define PID_EVAP_SYSTEM_VAPOR_PRESSURE                               "01 54" // ((A*256)+B)-32767
#define PID_SHORTTERM_SECONDARY_OXYGEN_SENSOR_TRIM_BANK_1_AND_BANK_3 "01 55" // (A-128)*100/128 (B-128)*100/128
#define PID_LONGTERM_SECONDARY_OXYGEN_SENSOR_TRIM_BANK_1_AND_BANK_3  "01 56" // (A-128)*100/128 (B-128)*100/128
#define PID_SHORTTERM_SECONDARY_OXYGEN_SENSOR_TRIM_BANK_2_AND_BANK_4 "01 57" // (A-128)*100/128 (B-128)*100/128
#define PID_LONGTERM_SECONDARY_OXYGEN_SENSOR_TRIM_BANK_2_AND_BANK_4  "01 58" // (A-128)*100/128 (B-128)*100/128
#define PID_FUEL_RAIL_PRESSURE_ABSOLUTE                              "01 59" // ((A*256)+B) * 10
#define PID_RELATIVE_ACCELERATOR_PEDAL_POSITION                      "01 5A" // A*100/255
#define PID_HYBRID_BATTERY_PACK_REMAINING_LIFE                       "01 5B" // A*100/255
#define PID_ENGINE_OIL_TEMP                                          "01 5C" // A - 40
#define PID_FUEL_INJECTION_TIMING                                    "01 5D" // (((A*256)+B)-26,880)/128
#define PID_ENGINE_FUEL_RATE                                         "01 5E" // ((A*256)+B)*0.05
#define PID_EMISSION_REQUIREMENTS_TO_WHICH_VEHICLE_IS_DESIGNED       "01 5F" // Bit Encoded
#define PID_DEMAND_ENGINE_PERCENT_TORQUE                             "01 61" // A-125
#define PID_ACTUAL_ENGINE_PERCENT_TORQUE                             "01 62" // A-125
#define PID_ENGINE_REFERENCE_TORQUE                                  "01 63" // A*256+B
#define PID_ENGINE_PERCENT_TORQUE_DATA                               "01 64" // A-125 Idle B-125 Engine point 1 C-125 Engine point 2 D-125 Engine point 3 E-125 Engine point 4"
#define PID_AUXILIARY_IO_SUPPORTED                                   "01 65" // Bit Encoded
#define PID_MASS_AIR_FLOW_SENSOR                                     "01 66" //
#define PID_ENGINE_COOLANT_TEMP                                      "01 67" //
#define PID_INTAKE_AIR_TEMP_SENSOR                                   "01 68" //
#define PID_COMMANDED_EGR_AND_EGR_ERROR                              "01 69" //
#define PID_COMMANDED_DIESEL_INTAKE_AIR_FLOW_CONTROL_AND_RELATIVE_INTAKE_AIR_FLOW_POSITION "01 6A" //
#define PID_EXHAUST_GAS_RECIRCULATION_TEMP                           "01 6B" //
#define PID_COMMANDED_THROTTLE_ACTUATOR_CONTROL_AND_RELATIVE_THROTTLE_POSITION "01 6C" //
#define PID_FUEL_PRESSURE_CONTROL_SYSTEM                             "01 6D" //
#define PID_INJECTION_PRESSURE_CONTROL_SYSTEM                        "01 6E" //
#define PID_TURBOCHARGER_COMPRESSOR_INLET_PRESSURE                   "01 6F" //
#define PID_BOOST_PRESSURE_CONTROL                                   "01 70" //
#define PID_VARIABLE_GEOMETRY_TURBO_CONTROL                          "01 71" //
#define PID_WASTEGATE_CONTROL                                        "01 72" //
#define PID_EXHAUST_PRESSURE                                         "01 73" //
#define PID_TURBOCHARGER_RPM                                         "01 74" //
#define PID_TURBOCHARGER_TEMP                                        "01 75" //
#define PID_TURBOCHARGER_TEMP                                        "01 76" //
#define PID_CHARGE_AIR_COOLER_TEMP                                   "01 77" //
#define PID_EXHAUST_GAS_TEMP_BANK_1                                  "01 78" // Special PID. See below
#define PID_EXHAUST_GAS_TEMP_BANK_2                                  "01 79" // Special PID. See below
#define PID_DIESEL_PARTICULATE_FILTER                                "01 7A" //
#define PID_DIESEL_PARTICULATE_FILTER                                "01 7B" //
#define PID_DIESEL_PARTICULATE_FILTER_TEMP                           "01 7C" //
#define PID_NOX_NTE_CONTROL_AREA_STATUS                              "01 7D" //
#define PID_PM_NTE_CONTROL_AREA_STATUS                               "01 7E" //
#define PID_ENGINE_RUN_TIME                                          "01 7F" //

#define PID_ENGINE_RUN_TIME_FOR_AUXILIARY_EMISSIONS_CONTROL_DEVICE   "01 81" //
#define PID_ENGINE_RUN_TIME_FOR_AUXILIARY_EMISSIONS_CONTROL_DEVICE   "01 82" //
#define PID_NOX_SENSOR                                               "01 83" //
#define PID_MANIFOLD_SURFACE_TEMP                                    "01 84" //
#define PID_NOX_REAGENT_SYSTEM                                       "01 85" //
#define PID_PARTICULATE_MATTER_SENSOR                                "01 86" //
#define PID_INTAKE_MANIFOLD_ABSOLUTE_PRESSURE                        "01 87" //

#endif /* OBD2PIDs_h */
