#ifndef DALICOMMANDPARCER_H
#define DALICOMMANDPARCER_H

#include <QMainWindow>

#ifndef bitRead
#define bitRead(value, bit) (((value) >> (bit)) & 0x01)
#endif

#define TYPE_BROADCAST          0
#define TYPE_GROUP              1
#define TYPE_ADDRESS            2
#define TYPE_BROADCAST_UNADDR   3

#define DALIREG_STATUS_BALLAST           0
#define DALIREG_STATUS_LAMP_FAILURE      1
#define DALIREG_STATUS_LAMP_ARC_POWER_ON 2
#define DALIREG_STATUS_LIMIT_ERROR       3
#define DALIREG_STATUS_FADE_READY        4
#define DALIREG_STATUS_RESET_STATE       5
#define DALIREG_STATUS_MISSING_SHORT     6
#define DALIREG_STATUS_POWER_FAILURE     7

//Some Standart Commands Opcodes
#define OFF_OPCODE                          0
#define RESET_OPCODE                        32
#define SAVE_PERSISTENT_VARIABLES           0x22
#define SET_FADE_TIME_OPCODE                0x2E
#define SET_FADE_RATE_OPCODE                0x2F
#define SET_EXTENDED_FADE_TIME_OPCODE       0x30
#define QUERY_VERSION_NUMBER                0x97
#define QUERY_DEVICE_TYPE                   0x99
#define ENABLE_WRITE_MEMORY                 129
#define QUERY_STATUS                        144
#define QUERY_CONTENT_DTR0                  152
#define QUERY_ACTUAL_LEVEL                  160
#define QUERY_POWER_ON_LEVEL                163
#define QUERY_SYSTEM_FAILURE_LEVEL          164
#define QUERY_FADE_TIME_RATE                165
#define QUERY_SCENE_LEVEL_0                 176
#define QUERY_SCENE_LEVEL_15                191
#define QUERY_RANDOM_ADDR_H                 194
#define QUERY_RANDOM_ADDR_M                 195
#define QUERY_RANDOM_ADDR_L                 196
#define READ_MEMORY_LOCATION                197

#define SPEC_202_REST                               224
#define SPEC_202_INHIBIT                            225
#define SPEC_202_RE_LIGHT_RESET_INHIBIT             226
#define SPEC_202_REQUEST_FUNCTION_TEST              227
#define SPEC_202_REQUEST_DURATION_TEST              228
#define SPEC_202_STOP_TEST                          229
#define SPEC_202_RESET_FUNCTION_TEST_DONE_FLAG      230
#define SPEC_202_RESET_DURATION_TEST_DONE_FLAG      231
#define SPEC_202_RESET_LAMP_TIME                    232
#define SPEC_202_STORE_DTR_AS_EMERGENCY_LEVEL       233
#define SPEC_202_STORE_TEST_DELAY_TIME_HIGH_BYTE    234
#define SPEC_202_STORE_TEST_DELAY_TIME_LOW_BYTE     235
#define SPEC_202_STORE_FUNCTION_TEST_INTERVAL       236
#define SPEC_202_STORE_DURATION_TEST_INTERVAL       237
#define SPEC_202_STORE_TEST_EXECUTION_TIMEOUT       238
#define SPEC_202_STORE_PROLONG_TIME                 239
#define SPEC_202_START_IDENTIFICATION               240
#define SPEC_202_QUERY_BATTERY_CHARGE               241
#define SPEC_202_QUERY_SELECTED_VARIABLE            242
#define SPEC_202_QUERY_DURATION_TEST_RESULT         243
#define SPEC_202_QUERY_LAMP_EMERGENCY_TIME          244
#define SPEC_202_QUERY_LAMP_TOTAL_OPERATION_TIME    245
#define SPEC_202_QUERY_EMERGENCY_LEVEL              246
#define SPEC_202_QUERY_EMERGENCY_PHYS_MIN_LEVEL     247
#define SPEC_202_QUERY_EMERGENCY_PHYS_MAX_LEVEL     248
#define SPEC_202_QUERY_RATED_DURATION               249
#define SPEC_202_QUERY_EMERGENCY_MODE               250
#define SPEC_202_QUERY_FEATURES                     251
#define SPEC_202_QUERY_FAILURE_STATUS               252
#define SPEC_202_QUERY_EMERGENCY_STATUS             253
#define SPEC_202_PEFORM_DTR_SELECTED_FUNCTION       254
#define SPEC_202_QUERY_EXTENDED_VERSION_NUMBER      255

#define SPEC_207_REFERENCE_SYSTEM_POWER              224
#define SPEC_207_ENABLE_CURRENT_PROTECTOR            225
#define SPEC_207_DISABLE_CURRENT_PROTECTOR           226
#define SPEC_207_SELECT_DIMMING_CURVE                227
#define SPEC_207_SET_FAST_FADE_TIME                  228
#define SPEC_207_QUERY_GEAR_TYPE                     237
#define SPEC_207_QUERY_DIMMING_CURVE                 238
#define SPEC_207_QUERY_POSSIBLE_OPERATING_MODES      239
#define SPEC_207_QUERY_FEATURES                      240
#define SPEC_207_QUERY_FAILURE_STATUS                241
#define SPEC_207_QUERY_SHORT_CIRCUIT                 242
#define SPEC_207_QUERY_OPEN_CIRCUIT                  243
#define SPEC_207_QUERY_LOAD_DECREASE                 244
#define SPEC_207_QUERY_LOAD_INREASE                  245
#define SPEC_207_QUERY_CURRENT_PROTECTOR_ACTIVE      246
#define SPEC_207_QUERY_THERMAL_SHUTDOWN              247
#define SPEC_207_QUERY_THERMAL_OVERLOAD              248
#define SPEC_207_QUERY_REFERENCE_RUNNING             249
#define SPEC_207_QUERY_REFERENCE_MEASUREMENT_FAILED  250
#define SPEC_207_QUERY_CURRENT_PROTECTOR_ENABLED     251
#define SPEC_207_QUERY_OPERATING_MODE                252
#define SPEC_207_QUERY_FAST_FADE_TIME                253
#define SPEC_207_QUERY_MIN_FAST_FADE_TIME            254

#define SPEC_205_REFERENCE_SYSTEM_POWER                 224
#define SPEC_205_SELECT_DIMMING_CURVE                   225
#define SPEC_205_QUERY_DIMMING_CURVE                    238
#define SPEC_205_QUERY_DIMMER_STATUS                    239
#define SPEC_205_QUERY_FEATURES                         240
#define SPEC_205_QUERY_FAILURE_STATUS                   241
#define SPEC_205_QUERY_DIMMER_TEMPERATURE               242
#define SPEC_205_QUERY_RMS_SUPPLY_VOLTAGE               243
#define SPEC_205_QUERY_SUPPLY_FREQUENCY                 244
#define SPEC_205_QUERY_RMS_LOAD_VOLTAGE                 245
#define SPEC_205_QUERY_RMS_LOAD_CURRENT                 246
#define SPEC_205_QUERY_REAL_LOAD_POWER                  247
#define SPEC_205_QUERY_LOAD_RATING                      248
#define SPEC_205_QUERY_REFERENCE_RUNNING                249
#define SPEC_205_QUERY_REFERENCE_MEASUREMENT_FAILED     250
#define SPEC_205_QUERY_EXTENDED_VERSION_NUMBER          255

#define SPEC_209_SET_TEMPORARY_X_COORDINATE             224
#define SPEC_209_SET_TEMPORARY_Y_COORDINATE             225
#define SPEC_209_ACTIVATE                               226
#define SPEC_209_X_COORDINATE_STEP_UP                   227
#define SPEC_209_X_COORDINATE_STEP_DOWN                 228
#define SPEC_209_Y_COORDINATE_STEP_UP                   229
#define SPEC_209_Y_COORDINATE_STEP_DOWN                 230
#define SPEC_209_SET_TEMP_COLOUR_TEMPERATURE_TC         231
#define SPEC_209_COLOUR_TEMP_TC_STEP_COOLER             232
#define SPEC_209_COLOUR_TEMP_TC_STEP_WARMER             233
#define SPEC_209_SET_TEMP_PRIMARY_N_DIMLEVEL            234
#define SPEC_209_SET_TEMP_RGB_DIMLEVEL                  235
#define SPEC_209_SET_TEMP_WAF_DIMLEVEL                  236
#define SPEC_209_SET_TEMP_RGBWAF_CONTROL                237
#define SPEC_209_COPY_REPORT_TO_TEMPORARY               238
#define SPEC_209_STORE_TY_PRIMARY_N                     240
#define SPEC_209_STORE_XY_COORD_PRIMARY_N               241
#define SPEC_209_STORE_COLOUR_TEMPERATURE_TC_LIMIT      242
#define SPEC_209_STORE_GEAR_FEATURES_STATUS             243
#define SPEC_209_ASSIGN_COLOUR_TO_LINKED_CHANNEL        245
#define SPEC_209_START_AUTO_CALIBRATION                 246
#define SPEC_209_QUERY_GEAR_FEATURES_STATUS             247
#define SPEC_209_QUERY_COLOUR_STATUS                    248
#define SPEC_209_QUERY_COLOUR_TYPE_FEATURES             249
#define SPEC_209_QUERY_COLOUR_VALUE                     250
#define SPEC_209_QUERY_RGBWAF_CONTROL                   251
#define SPEC_209_QUERY_ASSIGNED_COLOUR                  252
#define SPEC_209_QUERY_EXTENDED_VERSION                 255

#define ENABLE_DEVICE_TYPE_OPCODE           0xC1
#define SET_DTR1_OPCODE                     0xC3

#define SPEC_LED_LAMP                               207
#define SPEC_SELF_CONTAINED_EMERGENCY_LIGHTNING     202
#define SPEC_INCANDESCENT_LAMP                      205
#define SPEC_COLOUR_CONTROL                         209

class daliCommandParcer
{
public:
    daliCommandParcer();

    quint8 getSpecialCmdAddrByteFromNumber(int number);
    quint8 getStandartCmdAddrByte(quint8 cmd_type, quint8 destination, bool is_dapc);
    quint8 getSpecialCmdOpcodeByte(quint16 cmdId, quint8 data);
    bool checkCmdIssueTwice(quint16 cmdId, quint8 specification);
    bool checkCmdNeedAnswer(quint16 cmdId, quint8 specification);
    bool checkCmdSpecial(quint16 cmdId);
    void explainStatus(quint8 status, QString* statusStr);
    void explainReply(uint16_t commandId, uint8_t reply, QString* resStr);
    void explainExtReply(uint16_t commandId, uint8_t reply, QString* resStr,quint8 spec);
private:
    void parseStatus(uint8_t status, QString* resStr);
    void parseFadeTimeRate(uint8_t time_rate, QString* resStr);
    void parseDeviceType(uint8_t devType, QString* resStr);
    void spec207ParseOperatMode(uint8_t reply, QString* resStr);
    void explainLedLampRpl(uint16_t commandId, uint8_t reply, QString* resStr);
    void explainIncandescentLampRpl(uint16_t commandId, uint8_t reply, QString* resStr);
    void spec209ParseFeaturesStatus(uint16_t reply, QString* resStr);
    void spec209ParseColourStatus(uint16_t reply, QString* resStr);
    void spec209ParseColourTypeFeatures(uint16_t reply, QString* resStr);
    void spec209ParseRGBWAFControl(uint16_t reply, QString* resStr);
    void spec209ParseColourValue(uint16_t reply, QString* resStr);
    void explainColourControlRpl(uint16_t commandId, uint8_t reply, QString* resStr);
    void spec202ParseSelectedVariable(uint16_t reply, QString* resStr);
    void spec202ParseEmergencyStatus(uint16_t reply, QString* resStr);
    void spec202ParseEmergencyMode(uint16_t reply, QString* resStr);
    void spec202ParseFeatures(uint16_t reply, QString* resStr);
    void spec202ParseFailureStatus(uint16_t reply, QString* resStr);
    void explainEmergLightningRpl(uint16_t commandId, uint8_t reply, QString* resStr);
    struct
    {
       int cmdNum;
       bool dtr0;
       bool dtr1;
       bool dtr2;
       bool answer;
       bool sendTwice;
    }standartCmdsConvTab[154] =
    {
        {OFF_OPCODE, false, false, false, false, false},    //OFF
        {1, false, false, false, false, false},    //UP
        {2, false, false, false, false, false},    //DOWN
        {3, false, false, false, false, false},    //STEP UP
        {4, false, false, false, false, false},    //STEP DOWN
        {5, false, false, false, false, false},    //RECALL MAX LEVEL
        {6, false, false, false, false, false},    //RECALL MIN LEVEL
        {7, false, false, false, false, false},    //STEP DOWN AND OFF
        {8, false, false, false, false, false},    //ON AND STEP UP
        {9, false, false, false, false, false},    //ENABLE DAPC SEQUENCE
        {10, false, false, false, false, false},    //GO TO LAST ACTIVE LEVEL
        {16, false, false, false, false, false},    //GO TO SCENE 0
        {17, false, false, false, false, false},    //
        {18, false, false, false, false, false},    //
        {19, false, false, false, false, false},    //GO TO SCENE 3
        {20, false, false, false, false, false},    //
        {21, false, false, false, false, false},    //
        {22, false, false, false, false, false},    //GO TO SCENE 6
        {23, false, false, false, false, false},    //
        {24, false, false, false, false, false},    //
        {25, false, false, false, false, false},    //GO TO SCENE 9
        {26, false, false, false, false, false},    //
        {27, false, false, false, false, false},    //
        {28, false, false, false, false, false},    //GO TO SCENE 12
        {29, false, false, false, false, false},    //
        {30, false, false, false, false, false},    //
        {31, false, false, false, false, false},    //GO TO SCENE 15
        {RESET_OPCODE, false, false, false, false, true},     //RESET
        {33, true, false, false, false, true},      //STORE ACTUAL LEVEL IN DTR0
        {SAVE_PERSISTENT_VARIABLES, false, false, false, false, true},     //SAVE PERSISTENT VARIABLES
        {35, true, false, false, false, true},      //SET OPERATING MODE (DTR0)
        {36, true, false, false, false, true},      //RESET MEMORY BANK (DTR0)
        {37, false, false, false, false, true},     //IDENTIFY DEVICE
        {42, true, false, false, false, true},     //SET MAX LEVEL (DTR0)
        {43, true, false, false, false, true},     //SET MIN LEVEL (DTR0)
        {44, true, false, false, false, true},     //SET SYSTEM FAILURE LEVEL (DTR0)
        {45, true, false, false, false, true},     //SET POWER ON LEVEL (DTR0)
        {SET_FADE_TIME_OPCODE, true, false, false, false, true},     //SET FADE TIME (DTR0)
        {SET_FADE_RATE_OPCODE, true, false, false, false, true},     //SET FADE RATE (DTR0)
        {SET_EXTENDED_FADE_TIME_OPCODE, true, false, false, false, true},     //SET EXTENDED FADE TIME (DTR0)
        {64, true, false, false, false, true},     //SET SCENE 0
        {65, true, false, false, false, true},     //
        {66, true, false, false, false, true},     //
        {67, true, false, false, false, true},     //SET SCENE 3
        {68, true, false, false, false, true},     //
        {69, true, false, false, false, true},     //
        {70, true, false, false, false, true},     //SET SCENE 6
        {71, true, false, false, false, true},     //
        {72, true, false, false, false, true},     //
        {73, true, false, false, false, true},     //SET SCENE 9
        {74, true, false, false, false, true},     //
        {75, true, false, false, false, true},     //
        {76, true, false, false, false, true},     //SET SCENE 12
        {77, true, false, false, false, true},
        {78, true, false, false, false, true},
        {79, true, false, false, false, true},     //SET SCENE 15
        {80, false, false, false, false, true},    //REMOVE FROM SCENE 0
        {81, false, false, false, false, true},    //
        {82, false, false, false, false, true},    //
        {83, false, false, false, false, true},    //REMOVE FROM SCENE 3
        {84, false, false, false, false, true},    //
        {85, false, false, false, false, true},    //
        {86, false, false, false, false, true},    //REMOVE FROM SCENE 6
        {87, false, false, false, false, true},    //
        {88, false, false, false, false, true},    //
        {89, false, false, false, false, true},    //REMOVE FROM SCENE 9
        {90, false, false, false, false, true},    //
        {91, false, false, false, false, true},    //
        {92, false, false, false, false, true},    //REMOVE FROM SCENE 12
        {93, false, false, false, false, true},    //
        {94, false, false, false, false, true},    //
        {95, false, false, false, false, true},    //REMOVE FROM SCENE 15
        {96, false, false, false, false, true},    //ADD TO GROUP 0
        {97, false, false, false, false, true},    //
        {98, false, false, false, false, true},    //
        {99, false, false, false, false, true},    //ADD TO GROUP 3
        {100, false, false, false, false, true},   //
        {101, false, false, false, false, true},   //
        {102, false, false, false, false, true},   //ADD TO GROUP 6
        {103, false, false, false, false, true},   //
        {104, false, false, false, false, true},   //
        {105, false, false, false, false, true},   //ADD TO GROUP 9
        {106, false, false, false, false, true},   //
        {107, false, false, false, false, true},   //
        {108, false, false, false, false, true},   //ADD TO GROUP 12
        {109, false, false, false, false, true},   //
        {110, false, false, false, false, true},   //
        {111, false, false, false, false, true},   //ADD TO GROUP 15
        {112, false, false, false, false, true},   //REMOVE FROM GROUP 0
        {113, false, false, false, false, true},   //
        {114, false, false, false, false, true},   //
        {115, false, false, false, false, true},   //REMOVE FROM GROUP 3
        {116, false, false, false, false, true},   //
        {117, false, false, false, false, true},   //
        {118, false, false, false, false, true},   //REMOVE FROM GROUP 6
        {119, false, false, false, false, true},   //
        {120, false, false, false, false, true},   //
        {121, false, false, false, false, true},   //REMOVE FROM GROUP 9
        {122, false, false, false, false, true},   //
        {123, false, false, false, false, true},   //
        {124, false, false, false, false, true},   //REMOVE FROM GROUP 12
        {125, false, false, false, false, true},   //
        {126, false, false, false, false, true},   //
        {127, false, false, false, false, true},   //REMOVE FROM GROUP 15
        {128, true, false, false, false, true},    //SET SHORT ADDRESS (DTR0)
        {ENABLE_WRITE_MEMORY, false, false, false, false, true},   //ENABLE WRITE MEMORY
        {QUERY_STATUS, false, false, false, true, false},   //QUERY STATUS
        {145, false, false, false, true, false},   //QUERY CONTROL GEAR PRESENT
        {146, false, false, false, true, false},   //QUERY LAMP FAILURE
        {147, false, false, false, true, false},   //QUERY LAMP POWER ON
        {148, false, false, false, true, false},   //QUERY LIMIT ERROR
        {149, false, false, false, true, false},   //QUERY RESET STATE
        {150, false, false, false, true, false},   //QUERY MISSING SHORT ADDRESS
        {QUERY_VERSION_NUMBER, false, false, false, true, false},   //0x97  151
        {QUERY_CONTENT_DTR0, true, false, false, true, false},    //152 QUERY CONTENT DTR0
        {QUERY_DEVICE_TYPE, false, false, false, true, false},   //0x99   153
        {154, false, false, false, true, false},   //QUERY PHYSICAL MINIMUM
        {155, false, false, false, true, false},   //QUERY POWER FAILURE
        {156, false, true, false, true, false},    //QUERY CONTENT DTR1
        {157, false, false, true, true, false},    //QUERY CONTENT DTR2
        {158, false, false, false, true, false},   //QUERY OPERATING MODE
        {159, false, false, false, true, false},   //QUERY LIGHT SOURCE TYPE
        {QUERY_ACTUAL_LEVEL, false, false, false, true, false},   //QUERY ACTUAL LEVEL
        {161, false, false, false, true, false},   //QUERY MAX LEVEL
        {162, false, false, false, true, false},   //QUERY MIN LEVEL
        {QUERY_POWER_ON_LEVEL, false, false, false, true, false},   //QUERY POWER ON LEVEL
        {QUERY_SYSTEM_FAILURE_LEVEL, false, false, false, true, false},   //QUERY SYSTEM FAILURE LEVEL
        {QUERY_FADE_TIME_RATE, false, false, false, true, false},   //QUERY FADE TIME/FADE RATE
        {166, false, false, false, true, false},   //QUERY MANUFACTURER SPECIFIC MODE
        {167, false, false, false, true, false},   //QUERY NEXT DEVICE TYPE
        {168, false, false, false, true, false},   //QUERY EXTENDED FADE TIME
        {169, false, false, false, true, false},   //QUERY CONTROL GEAR FAILURE
        {QUERY_SCENE_LEVEL_0, false, false, false, true, false},   //QUERY SCENE LEVEL 0
        {177, false, false, false, true, false},   //QUERY SCENE LEVEL 1
        {178, false, false, false, true, false},   //QUERY SCENE LEVEL 2
        {179, false, false, false, true, false},   //QUERY SCENE LEVEL 3
        {180, false, false, false, true, false},   //QUERY SCENE LEVEL 4
        {181, false, false, false, true, false},   //QUERY SCENE LEVEL 5
        {182, false, false, false, true, false},   //QUERY SCENE LEVEL 6
        {183, false, false, false, true, false},   //QUERY SCENE LEVEL 7
        {184, false, false, false, true, false},   //QUERY SCENE LEVEL 8
        {185, false, false, false, true, false},   //QUERY SCENE LEVEL 9
        {186, false, false, false, true, false},   //QUERY SCENE LEVEL 10
        {187, false, false, false, true, false},   //QUERY SCENE LEVEL 11
        {188, false, false, false, true, false},   //QUERY SCENE LEVEL 12
        {189, false, false, false, true, false},   //QUERY SCENE LEVEL 13
        {190, false, false, false, true, false},   //QUERY SCENE LEVEL 14
        {QUERY_SCENE_LEVEL_15, false, false, false, true, false},   //QUERY SCENE LEVEL 15
        {192, false, false, false, true, false},   //QUERY GROUPS 0-7
        {193, false, false, false, true, false},   //QUERY GROUPS 8-15
        {QUERY_RANDOM_ADDR_H, false, false, false, true, false},   //QUERY RANDOM ADDRESS (H)
        {QUERY_RANDOM_ADDR_M, false, false, false, true, false},   //QUERY RANDOM ADDRESS (M)
        {QUERY_RANDOM_ADDR_L, false, false, false, true, false},   //QUERY RANDOM ADDRESS (L)
        {READ_MEMORY_LOCATION, true, true, false, true, false},     //READ MEMORY LOCATION (DTR1, DTR0)
    };
    //Application specific commands (SPEC. 202)
struct
    {
        int cmdNum;
        bool dtr0;
        bool dtr1;
        bool dtr2;
        bool answer;
        bool sendTwice;
    }extendedCmdsSpec202ConvTab[32] =
    {
        {SPEC_202_REST, false, false, false, false, true},                              //224
        {SPEC_202_INHIBIT, false, false, false, false, true},                           //225
        {SPEC_202_RE_LIGHT_RESET_INHIBIT, false, false, false, false, true},            //226
        {SPEC_202_REQUEST_FUNCTION_TEST, false, false, false, false, true},             //227
        {SPEC_202_REQUEST_DURATION_TEST, false, false, false, false, true},             //228
        {SPEC_202_STOP_TEST, false, false, false, false, true},                         //229
        {SPEC_202_RESET_FUNCTION_TEST_DONE_FLAG, false, false, false, false, true},     //230
        {SPEC_202_RESET_DURATION_TEST_DONE_FLAG, false, false, false, false, true},     //231
        {SPEC_202_RESET_LAMP_TIME, false, false, false, false, true},                   //232
        {SPEC_202_STORE_DTR_AS_EMERGENCY_LEVEL, false, false, false, false, true},      //233
        {SPEC_202_STORE_TEST_DELAY_TIME_HIGH_BYTE, false, false, false, false, true},   //234
        {SPEC_202_STORE_TEST_DELAY_TIME_LOW_BYTE, false, false, false, false, true},    //235
        {SPEC_202_STORE_FUNCTION_TEST_INTERVAL, false, false, false, false, true},      //236
        {SPEC_202_STORE_DURATION_TEST_INTERVAL, false, false, false, false, true},      //237
        {SPEC_202_STORE_TEST_EXECUTION_TIMEOUT, false, false, false, false, true},      //238
        {SPEC_202_STORE_PROLONG_TIME, false, false, false, false, true},                //239
        {SPEC_202_START_IDENTIFICATION, false, false, false, false, false},             //240
        {SPEC_202_QUERY_BATTERY_CHARGE, false, false, false, true, false},              //241
        {SPEC_202_QUERY_SELECTED_VARIABLE, false, false, false, true, false},           //242
        {SPEC_202_QUERY_DURATION_TEST_RESULT, false, false, false, true, false},        //243
        {SPEC_202_QUERY_LAMP_EMERGENCY_TIME, false, false, false, true, false},         //244
        {SPEC_202_QUERY_LAMP_TOTAL_OPERATION_TIME, false, false, false, true, false},   //245
        {SPEC_202_QUERY_EMERGENCY_LEVEL, false, false, false, true, false},             //246
        {SPEC_202_QUERY_EMERGENCY_PHYS_MIN_LEVEL, false, false, false, true, false},    //247
        {SPEC_202_QUERY_EMERGENCY_PHYS_MAX_LEVEL, false, false, false, true, false},    //248
        {SPEC_202_QUERY_RATED_DURATION, false, false, false, true, false},              //249
        {SPEC_202_QUERY_EMERGENCY_MODE, false, false, false, true, false},              //250
        {SPEC_202_QUERY_FEATURES, false, false, false, true, false},                    //251
        {SPEC_202_QUERY_FAILURE_STATUS, false, false, false, true, false},              //252
        {SPEC_202_QUERY_EMERGENCY_STATUS, false, false, false, true, false},            //253
        {SPEC_202_PEFORM_DTR_SELECTED_FUNCTION, false, false, false, true, false},      //254
        {SPEC_202_QUERY_EXTENDED_VERSION_NUMBER, false, false, false, true, false},     //255
    };
        //Application specific commands (SPEC. 207)
        //Every configuration command (224 to 228) shall be received a second time within 100 ms before it is executed
        //Command 272 shall be sent before the two instances of the respective configuration command, but not repeated between them
    struct
    {
        int cmdNum;
        bool dtr0;
        bool dtr1;
        bool dtr2;
        bool answer;
        bool sendTwice;
    }extendedCmdsSpec207ConvTab[24] =
    {
        {SPEC_207_REFERENCE_SYSTEM_POWER, false, false, false, false, true},//224
        {SPEC_207_ENABLE_CURRENT_PROTECTOR, false, false, false, false, true},//225
        {SPEC_207_DISABLE_CURRENT_PROTECTOR, false, false, false, false, true},//226
        {SPEC_207_SELECT_DIMMING_CURVE, true, false, false, false, true},//227
        {SPEC_207_SET_FAST_FADE_TIME, true, false, false, false, true},    //228 STORE DTR AS FAST FADE TIME
        {SPEC_207_QUERY_GEAR_TYPE, false, false, false, true, false},//QUERY_GEAR_TYPE
        {SPEC_207_QUERY_DIMMING_CURVE, false, false, false, true, false},//QUERY_DIMMING_CURVE
        {SPEC_207_QUERY_POSSIBLE_OPERATING_MODES, false, false, false, true, false},//QUERY_POSSIBLE_OPERATING_MODES
        {SPEC_207_QUERY_FEATURES, false, false, false, true, false},//QUERY_FEATURES
        {SPEC_207_QUERY_FAILURE_STATUS, false, false, false, true, false},//QUERY_FAILURE_STATUS
        {SPEC_207_QUERY_SHORT_CIRCUIT, false, false, false, true, false},//QUERY_SHORT_CIRCUIT
        {SPEC_207_QUERY_OPEN_CIRCUIT, false, false, false, true, false},//QUERY_OPEN_CIRCUIT
        {SPEC_207_QUERY_LOAD_DECREASE, false, false, false, true, false},//QUERY_LOAD_DECREASE
        {SPEC_207_QUERY_LOAD_INREASE, false, false, false, true, false},//QUERY_LOAD_INREASE
        {SPEC_207_QUERY_CURRENT_PROTECTOR_ACTIVE, false, false, false, true, false},//QUERY_CURRENT_PROTECTOR_ACTIVE
        {SPEC_207_QUERY_THERMAL_SHUTDOWN, false, false, false, true, false},//QUERY_THERMAL_SHUTDOWN
        {SPEC_207_QUERY_THERMAL_OVERLOAD, false, false, false, true, false},//QUERY_THERMAL_OVERLOAD
        {SPEC_207_QUERY_REFERENCE_RUNNING, false, false, false, true, false},//QUERY_REFERENCE_RUNNING
        {SPEC_207_QUERY_REFERENCE_MEASUREMENT_FAILED, false, false, false, true, false},//QUERY_REFERENCE_MEASUREMENT_FAILED
        {SPEC_207_QUERY_CURRENT_PROTECTOR_ENABLED, false, false, false, true, false},//QUERY_CURRENT_PROTECTOR_ENABLED
        {SPEC_207_QUERY_OPERATING_MODE, false, false, false, true, false},//QUERY_OPERATING_MODE
        {SPEC_207_QUERY_FAST_FADE_TIME, false, false, false, true, false},//QUERY_FAST_FADE_TIME
        {SPEC_207_QUERY_MIN_FAST_FADE_TIME, false, false, false, true, false},//QUERY_MIN_FAST_FADE_TIME
        {255, false, false, false, true, false},   //QUERY EXTENDED VERSION NUMBER
    };

    struct
    {
        int cmdNum;
        bool dtr0;
        bool dtr1;
        bool dtr2;
        bool answer;
        bool sendTwice;
    }extendedCmdsSpec205ConvTab[16] =
    {
        {SPEC_205_REFERENCE_SYSTEM_POWER, false, false, false, false, true},
        {SPEC_205_SELECT_DIMMING_CURVE, false, false, false, false, true},
        {SPEC_205_QUERY_DIMMING_CURVE, false, false, false, true, false},
        {SPEC_205_QUERY_DIMMER_STATUS, false, false, false, true, false},
        {SPEC_205_QUERY_FEATURES, false, false, false, true, false},
        {SPEC_205_QUERY_FAILURE_STATUS, false, false, false, true, false},
        {SPEC_205_QUERY_DIMMER_TEMPERATURE, false, false, false, true, false},
        {SPEC_205_QUERY_RMS_SUPPLY_VOLTAGE, false, false, false, true, false},
        {SPEC_205_QUERY_SUPPLY_FREQUENCY, false, false, false, true, false},
        {SPEC_205_QUERY_RMS_LOAD_VOLTAGE, false, false, false, true, false},
        {SPEC_205_QUERY_RMS_LOAD_CURRENT, false, false, false, true, false},
        {SPEC_205_QUERY_REAL_LOAD_POWER, false, false, false, true, false},
        {SPEC_205_QUERY_LOAD_RATING, false, false, false, true, false},
        {SPEC_205_QUERY_REFERENCE_RUNNING, false, false, false, true, false},
        {SPEC_205_QUERY_REFERENCE_MEASUREMENT_FAILED, false, false, false, true, false},
        {SPEC_205_QUERY_EXTENDED_VERSION_NUMBER, false, false, false, true, false},
    };

    struct
    {
        int cmdNum;
        bool dtr0;
        bool dtr1;
        bool dtr2;
        bool answer;
        bool sendTwice;
    }extendedCmdsSpec209ConvTab[28] =
    {
        {SPEC_209_SET_TEMPORARY_X_COORDINATE, true, true, false, false, false},
        {SPEC_209_SET_TEMPORARY_Y_COORDINATE, false, false, false, false, true},
        {SPEC_209_ACTIVATE, false, false, false, false, false},
        {SPEC_209_X_COORDINATE_STEP_UP, false, false, false, false, false},
        {SPEC_209_X_COORDINATE_STEP_DOWN, false, false, false, false, false},
        {SPEC_209_Y_COORDINATE_STEP_UP, false, false, false, false, false},
        {SPEC_209_Y_COORDINATE_STEP_DOWN, false, false, false, false, false},
        {SPEC_209_SET_TEMP_COLOUR_TEMPERATURE_TC, true, true, false, false, false},
        {SPEC_209_COLOUR_TEMP_TC_STEP_COOLER, false, false, false, false, false},
        {SPEC_209_COLOUR_TEMP_TC_STEP_WARMER, false, false, false, false, false},
        {SPEC_209_SET_TEMP_PRIMARY_N_DIMLEVEL, true, true, true, false, false},
        {SPEC_209_SET_TEMP_RGB_DIMLEVEL, true, true, true, false, false},
        {SPEC_209_SET_TEMP_WAF_DIMLEVEL, true, true, true, false, false},
        {SPEC_209_SET_TEMP_RGBWAF_CONTROL, true, false, false, false, false},
        {SPEC_209_COPY_REPORT_TO_TEMPORARY, false, false, false, false, false},
        {SPEC_209_STORE_TY_PRIMARY_N, true, true, true, false, false},
        {SPEC_209_STORE_XY_COORD_PRIMARY_N, false, false, true, false, false},
        {SPEC_209_STORE_COLOUR_TEMPERATURE_TC_LIMIT, true, true, true, false, false},
        {SPEC_209_STORE_GEAR_FEATURES_STATUS, true, false, false, false, false},
        {SPEC_209_ASSIGN_COLOUR_TO_LINKED_CHANNEL, true, false, false, false, false},
        {SPEC_209_START_AUTO_CALIBRATION, false, false, false, false, false},
        {SPEC_209_QUERY_GEAR_FEATURES_STATUS, false, false, false, true, false},
        {SPEC_209_QUERY_COLOUR_STATUS, false, false, false, true, false},
        {SPEC_209_QUERY_COLOUR_TYPE_FEATURES, false, false, false, true, false},
        {SPEC_209_QUERY_COLOUR_VALUE, false, false, false, true, false},
        {SPEC_209_QUERY_RGBWAF_CONTROL, false, false, false, true, false},
        {SPEC_209_QUERY_ASSIGNED_COLOUR, false, false, false, true, false},
        {SPEC_209_QUERY_EXTENDED_VERSION, false, false, false, true, false},
    };
    struct
    {
        quint8 addressByte;
        int cmdNum;
        bool opcodeNotNull;
        bool sendTwice;
        bool answer;
    }specCmdsConvTab[18] =
    {
        {0xA1, 256, false, false, false},  //TERMINATE
        {0xA3, 257, true, false, false},   //DTR0
        {0xA5, 258, true, true, false},    //INITIALISE
        {0xA7, 259, false, true, false},   //RANDOMISE
        {0xA9, 260, false, false, true},   //COMPARE
        {0xAB, 261, false, false, false},  //WITHDRAW
        {0xAD, 262, false, false, false},  //PING
        {0xB1, 264, true, false, false},   //SEARCHADDRH
        {0xB3, 265, true, false, false},   //SEARCHADDRM
        {0xB5, 266, true, false, false},   //SEARCHADDRL
        {0xB7, 267, true, false, false},   //PROGRAM SHORT ADDRESS
        {0xB9, 268, true, false, true},    //VERIFY SHORT ADDRESS
        {0xBB, 269, false, false, true},   //QUERY SHORT ADDRESS
        {ENABLE_DEVICE_TYPE_OPCODE, 272, true, false, false},    //ENABLE DEVICE TYPE
        {SET_DTR1_OPCODE, 273, true, false, false},    //DTR1
        {0xC5, 274, true, false, false},    //DTR2
        {0xC7, 275, true, false, true},     //WRITE MEMORY LOCATION
        {0xC9, 276, true, false, false},    //WRITE MEMORY LOCATION - NO REPLY

    };
};

#endif // DALICOMMANDPARCER_H
