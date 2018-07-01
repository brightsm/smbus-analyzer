#ifndef COMMANDS_DESC_H
#define COMMANDS_DESC_H

struct CommandDesc
{
	int				id;
	const char*		name;
	int				data_length;			// -1 for variable
	ParamDirection	direction;

	SMBusFrameType	databyte_param_type;	// in case of single byte params
};

const CommandDesc& GetPMBusCommandDesc(U64 id);
const CommandDesc& GetSmartBatteryCommandDesc(U64 id);

enum PMBusCommandID {
PAGE						= 0x00,
OPERATION					= 0x01,
ON_OFF_CONFIG				= 0x02,
CLEAR_FAULTS				= 0x03,
PHASE						= 0x04,
WRITE_PROTECT				= 0x10,
STORE_DEFAULT_ALL			= 0x11,
RESTORE_DEFAULT_ALL			= 0x12,
STORE_DEFAULT_CODE			= 0x13,
RESTORE_DEFAULT_CODE		= 0x14,
STORE_USER_ALL				= 0x15,
RESTORE_USER_ALL			= 0x16,
STORE_USER_CODE				= 0x17,
RESTORE_USER_CODE			= 0x18,
CAPABILITY					= 0x19,
QUERY						= 0x1A,
VOUT_MODE					= 0x20,
VOUT_COMMAND				= 0x21,
VOUT_TRIM					= 0x22,
VOUT_CAL_OFFSET				= 0x23,
VOUT_MAX					= 0x24,
VOUT_MARGIN_HIGH			= 0x25,
VOUT_MARGIN_LOW				= 0x26,
VOUT_TRANSITION_RATE		= 0x27,
VOUT_DROOP					= 0x28,
VOUT_SCALE_LOOP				= 0x29,
VOUT_SCALE_MONITOR			= 0x2A,
COEFFICIENTS				= 0x30,
POUT_MAX					= 0x31,
MAX_DUTY					= 0x32,
FREQUENCY_SWITCH			= 0x33,
VIN_ON						= 0x35,
VIN_OFF						= 0x36,
INTERLEAVE					= 0x37,
IOUT_CAL_GAIN				= 0x38,
IOUT_CAL_OFFSET				= 0x39,
FAN_CONFIG_1_2				= 0x3A,
FAN_COMMAND_1				= 0x3B,
FAN_COMMAND_2				= 0x3C,
FAN_CONFIG_3_4				= 0x3D,
FAN_COMMAND_3				= 0x3E,
FAN_COMMAND_4				= 0x3F,
VOUT_OV_FAULT_LIMIT			= 0x40,
VOUT_OV_FAULT_RESPONSE		= 0x41,
VOUT_OV_WARN_LIMIT			= 0x42,
VOUT_UV_WARN_LIMIT			= 0x43,
VOUT_UV_FAULT_LIMIT			= 0x44,
VOUT_UV_FAULT_RESPONSE		= 0x45,
IOUT_OC_FAULT_LIMIT			= 0x46,
IOUT_OC_FAULT_RESPONSE		= 0x47,
IOUT_OC_LV_FAULT_LIMIT		= 0x48,
IOUT_OC_LV_FAULT_RESPONSE	= 0x49,
IOUT_OC_WARN_LIMIT			= 0x4A,
IOUT_UC_FAULT_LIMIT			= 0x4B,
IOUT_UC_FAULT_RESPONSE		= 0x4C,
OT_FAULT_LIMIT				= 0x4F,
OT_FAULT_RESPONSE			= 0x50,
OT_WARN_LIMIT				= 0x51,
UT_WARN_LIMIT				= 0x52,
UT_FAULT_LIMIT				= 0x53,
UT_FAULT_RESPONSE			= 0x54,
VIN_OV_FAULT_LIMIT			= 0x55,
VIN_OV_FAULT_RESPONSE		= 0x56,
VIN_OV_WARN_LIMIT			= 0x57,
VIN_UV_WARN_LIMIT			= 0x58,
VIN_UV_FAULT_LIMIT			= 0x59,
VIN_UV_FAULT_RESPONSE		= 0x5A,
IIN_OC_FAULT_LIMIT			= 0x5B,
IIN_OC_FAULT_RESPONSE		= 0x5C,
IIN_OC_WARN_LIMIT			= 0x5D,
POWER_GOOD_ON				= 0x5E,
POWER_GOOD_OFF				= 0x5F,
TON_DELAY					= 0x60,
TON_RISE					= 0x61,
TON_MAX_FAULT_LIMIT			= 0x62,
TON_MAX_FAULT_RESPONSE		= 0x63,
TOFF_DELAY					= 0x64,
TOFF_FALL					= 0x65,
TOFF_MAX_WARN_LIMIT			= 0x66,
POUT_OP_FAULT_LIMIT			= 0x68,
POUT_OP_FAULT_RESPONSE		= 0x69,
POUT_OP_WARN_LIMIT			= 0x6A,
PIN_OP_WARN_LIMIT			= 0x6B,
STATUS_BYTE					= 0x78,
STATUS_WORD					= 0x79,
STATUS_VOUT					= 0x7A,
STATUS_IOUT					= 0x7B,
STATUS_INPUT				= 0x7C,
STATUS_TEMPERATURE			= 0x7D,
STATUS_CML					= 0x7E,
STATUS_OTHER				= 0x7F,
STATUS_MFR_SPECIFIC			= 0x80,
STATUS_FANS_1_2				= 0x81,
STATUS_FANS_3_4				= 0x82,
READ_VIN					= 0x88,
READ_IIN					= 0x89,
READ_VCAP					= 0x8A,
READ_VOUT					= 0x8B,
READ_IOUT					= 0x8C,
READ_TEMPERATURE_1			= 0x8D,
READ_TEMPERATURE_2			= 0x8E,
READ_TEMPERATURE_3			= 0x8F,
READ_FAN_SPEED_1			= 0x90,
READ_FAN_SPEED_2			= 0x91,
READ_FAN_SPEED_3			= 0x92,
READ_FAN_SPEED_4			= 0x93,
READ_DUTY_CYCLE				= 0x94,
READ_FREQUENCY				= 0x95,
READ_POUT					= 0x96,
READ_PIN					= 0x97,
PMBUS_REVISION				= 0x98,
MFR_ID						= 0x99,
MFR_MODEL					= 0x9A,
MFR_REVISION				= 0x9B,
MFR_LOCATION				= 0x9C,
MFR_DATE					= 0x9D,
MFR_SERIAL					= 0x9E,
MFR_VIN_MIN					= 0xA0,
MFR_VIN_MAX					= 0xA1,
MFR_IIN_MAX					= 0xA2,
MFR_PIN_MAX					= 0xA3,
MFR_VOUT_MIN				= 0xA4,
MFR_VOUT_MAX				= 0xA5,
MFR_IOUT_MAX				= 0xA6,
MFR_POUT_MAX				= 0xA7,
MFR_TAMBIENT_MAX			= 0xA8,
MFR_TAMBIENT_MIN			= 0xA9,
MFR_EFFICIENCY_LL			= 0xAA,
MFR_EFFICIENCY_HL			= 0xAB,
USER_DATA_00				= 0xB0,
USER_DATA_01				= 0xB1,
USER_DATA_02				= 0xB2,
USER_DATA_03				= 0xB3,
USER_DATA_04				= 0xB4,
USER_DATA_05				= 0xB5,
USER_DATA_06				= 0xB6,
USER_DATA_07				= 0xB7,
USER_DATA_08				= 0xB8,
USER_DATA_09				= 0xB9,
USER_DATA_10				= 0xBA,
USER_DATA_11				= 0xBB,
USER_DATA_12				= 0xBC,
USER_DATA_13				= 0xBD,
USER_DATA_14				= 0xBE,
USER_DATA_15				= 0xBF,
MFR_SPECIFIC_00				= 0xD0,
MFR_SPECIFIC_01				= 0xD1,
MFR_SPECIFIC_02				= 0xD2,
MFR_SPECIFIC_03				= 0xD3,
MFR_SPECIFIC_04				= 0xD4,
MFR_SPECIFIC_05				= 0xD5,
MFR_SPECIFIC_06				= 0xD6,
MFR_SPECIFIC_07				= 0xD7,
MFR_SPECIFIC_08				= 0xD8,
MFR_SPECIFIC_09				= 0xD9,
MFR_SPECIFIC_10				= 0xDA,
MFR_SPECIFIC_11				= 0xDB,
MFR_SPECIFIC_13				= 0xDD,
MFR_SPECIFIC_14				= 0xDE,
MFR_SPECIFIC_15				= 0xDF,
MFR_SPECIFIC_16				= 0xE0,
MFR_SPECIFIC_17				= 0xE1,
MFR_SPECIFIC_18				= 0xE2,
MFR_SPECIFIC_19				= 0xE3,
MFR_SPECIFIC_20				= 0xE4,
MFR_SPECIFIC_21				= 0xE5,
MFR_SPECIFIC_22				= 0xE6,
MFR_SPECIFIC_23				= 0xE7,
MFR_SPECIFIC_24				= 0xE8,
MFR_SPECIFIC_25				= 0xE9,
MFR_SPECIFIC_26				= 0xEA,
MFR_SPECIFIC_27				= 0xEB,
MFR_SPECIFIC_28				= 0xEC,
MFR_SPECIFIC_29				= 0xED,
MFR_SPECIFIC_30				= 0xEE,
MFR_SPECIFIC_31				= 0xEF,
MFR_SPECIFIC_32				= 0xF0,
MFR_SPECIFIC_33				= 0xF1,
MFR_SPECIFIC_34				= 0xF2,
MFR_SPECIFIC_35				= 0xF3,
MFR_SPECIFIC_36				= 0xF4,
MFR_SPECIFIC_37				= 0xF5,
MFR_SPECIFIC_38				= 0xF6,
MFR_SPECIFIC_39				= 0xF7,
MFR_SPECIFIC_40				= 0xF8,
MFR_SPECIFIC_41				= 0xF9,
MFR_SPECIFIC_42				= 0xFA,
MFR_SPECIFIC_43				= 0xFB,
MFR_SPECIFIC_44				= 0xFC,
MFR_SPECIFIC_45				= 0xFD,
MFR_SPECIFIC_COMMAND_EXT	= 0xFE,
PMBUS_COMMAND_EXT			= 0xFF,
};

enum SmartBatteryCommandID {
SBC_ManufacturerAccess		= 0x00,
SBC_RemainingCapacityAlarm	= 0x01,
SBC_RemainingTimeAlarm		= 0x02,
SBC_BatteryMode				= 0x03,
SBC_AtRate					= 0x04,
SBC_AtRateTimeToFull		= 0x05,
SBC_AtRateTimeToEmpty		= 0x06,
SBC_AtRateOK				= 0x07,
SBC_Temperature				= 0x08,
SBC_Voltage					= 0x09,
SBC_Current					= 0x0a,
SBC_AverageCurrent			= 0x0b,
SBC_MaxError				= 0x0c,
SBC_RelativeStateOfCharge	= 0x0d,
SBC_AbsoluteStateOfCharge	= 0x0e,
SBC_RemainingCapacity		= 0x0f,
SBC_FullChargeCapacity		= 0x10,
SBC_RunTimeToEmpty			= 0x11,
SBC_AverageTimeToEmpty		= 0x12,
SBC_AverageTimeToFull		= 0x13,
SBC_ChargingCurrent			= 0x14,
SBC_ChargingVoltage			= 0x15,
SBC_BatteryStatus			= 0x16,
SBC_CycleCount				= 0x17,
SBC_DesignCapacity			= 0x18,
SBC_DesignVoltage			= 0x19,
SBC_SpecificationInfo		= 0x1a,
SBC_ManufactureDate			= 0x1b,
SBC_SerialNumber			= 0x1c,
SBC_ManufacturerName		= 0x20,
SBC_DeviceName				= 0x21,
SBC_DeviceChemistry			= 0x22,
SBC_ManufacturerData		= 0x23,
SBC_OptionalMfgFunction5	= 0x2f,
SBC_OptionalMfgFunction4	= 0x3c,
SBC_OptionalMfgFunction3	= 0x3d,
SBC_OptionalMfgFunction2	= 0x3e,
SBC_OptionalMfgFunction1	= 0x3f,
};

#endif	// COMMANDS_DESC_H
