#pragma once

namespace OBD2 {
// OBD2 Service Modes
constexpr const char* MODE_CURRENT_DATA = "01";
constexpr const char* MODE_FREEZE_FRAME = "02";
constexpr const char* MODE_DIAGNOSTIC_TROUBLE_CODES = "03";
constexpr const char* MODE_PENDING_DIAGNOSTIC_TROUBLE_CODES = "07";
constexpr const char* MODE_CLEAR_TROUBLE_CODES = "04";
constexpr const char* MODE_OXYGEN_SENSOR_MONITORING = "05";
constexpr const char* MODE_ONBOARD_MONITORING = "06";
constexpr const char* MODE_VEHICLE_INFORMATION = "09";

// OBD2 PIDs for Mode 01 (Current Data)
constexpr const char* PID_SUPPORTED_PIDS_01_20 = "00";
constexpr const char* PID_ENGINE_COOLANT_TEMPERATURE = "05";
constexpr const char* PID_ENGINE_RPM = "0C";
constexpr const char* PID_VEHICLE_SPEED = "0D";
constexpr const char* PID_THROTTLE_POSITION = "11";
constexpr const char* PID_SUPPORTED_PIDS_21_40 = "20";
constexpr const char* PID_FUEL_LEVEL = "2F";
constexpr const char* PID_SUPPORTED_PIDS_41_60 = "40";

// OBD2 PIDs for Mode 09 (Vehicle Information)
constexpr const char* PID_SUPPORTED_PIDS_01_20_VIN = "00";
constexpr const char* PID_VIN_MESSAGE_COUNT = "01";
constexpr const char* PID_VIN = "02";
}  // namespace OBD2
