#ifndef DIAGNOSTICS_H
#define DIAGNOSTICS_H

#include <QObject>
#include <QWidget>
#include <QTableView>
#include <QStandardItemModel>



class diagnostics
{
public:
    diagnostics();
    void membank_202_init(QTableView* tabView);
    void membank_203_init(QTableView* tabView);
    void membank_204_init(QTableView* tabView);
    void membank_205_init(QTableView* tabView);
    void membank_206_init(QTableView* tabView);
    void membank_207_init(QTableView* tabView);
    void membank_208_init(QTableView* tabView);
    QStandardItemModel* getMembank0Model();
    QStandardItemModel* getMembank1Model();
    QStandardItemModel* getMembank202Model();
    QStandardItemModel* getMembank203Model();
    QStandardItemModel* getMembank204Model();
    QStandardItemModel* getMembank205Model();
    QStandardItemModel* getMembank206Model();
    QStandardItemModel* getMembank207Model();

    QStandardItemModel* fillModel(quint8 memBankId, quint8* pData);
private:
    #define MEM_BANK_0_ROW_COUNT    27
    #define MEM_BANK_1_ROW_COUNT    120
    #define MEM_BANK_202_ROW_COUNT  16
    #define MEM_BANK_203_ROW_COUNT  16
    #define MEM_BANK_204_ROW_COUNT  16
    #define MEM_BANK_205_ROW_COUNT  29
    #define MEM_BANK_206_ROW_COUNT  33
    #define MEM_BANK_207_ROW_COUNT  8
    #define MEM_BANK_208_ROW_COUNT  51

    #define UINT8_TMASK                             0xFE
    #define UINT8_MASK                              0xFF
    #define UINT16_TMASK                            0xFFFE

    #define MBANK_205_OPERATING_TIME_OFFSET         0x04
    #define MBANK_205_START_CNTR_OFFSET             0x08
    #define MBANK_205_OVERAL_FAIL_COND_OFFSET       0x0F
    #define MBANK_205_OVERAL_FAIL_COND_CNTR_OFFSET  0x10
    #define MBANK_205_THERMAL_DERATING_OFFSET       0x17
    #define MBANK_205_THERMAL_DERATING_CNTR_OFFSET  0x18
    #define MBANK_205_THERMAL_SHUTDOWN_OFFSET       0x19
    #define MBANK_205_THERMAL_SHUTDOWN_CNTR_OFFSET  0x1A
    #define MBANK_205_TEMP_VALUE_OFFSET             0x1B
    #define MBANK_205_CURRENT_PERCENT_OFFSET        0x1C

    #define MBANK_206_START_CNTR_RSTABLE_OFFSET     0x04
    #define MBANK_206_START_CNTR_OFFSET             0x07
    #define MBANK_206_ON_TIME_RSTABLE_OFFSET        0x0A
    #define MBANK_206_ON_TIME_OFFSET                0x0E
    #define MBANK_206_OVERALL_FAIL_COND_OFFSET      0x16
    #define MBANK_206_OVERALL_FAIL_COND_CNT_OFFSET  0x17
    #define MBANK_206_THERMAL_DERATING_OFFSET       0x1C
    #define MBANK_206_THERMAL_DERATING_CNTR_OFFSET  0x1D
    #define MBANK_206_THERMAL_SHUTDOWN_OFFSET       0x1E
    #define MBANK_206_THERMAL_SHUTDOWN_CNTR_OFFSET  0x1F
    #define MBANK_206_TEMP_VALUE_OFFSET             0x20

    #define MBANK_207_RATED_MED_USEFUL_LIFE_OFFSET  0x04
    #define MBANK_207_INT_CTRL_GEAR_REF_TEMP_OFFSET 0x05
    #define MBANK_207_RATED_MED_USEFUL_LIT_SRC_STARTS_OFFSET  0x06

    QStandardItemModel memBank0Model;
    QStandardItemModel memBank1Model;
    QStandardItemModel memBank202Model;
    QStandardItemModel memBank203Model;
    QStandardItemModel memBank204Model;
    QStandardItemModel memBank205Model;
    QStandardItemModel memBank206Model;
    QStandardItemModel memBank207Model;
    QStandardItemModel memBank208Model;

    quint32 opTime = 0;
    quint32 startCntr = 0;

    QList<QString>memBank202DescList =
    {
       "Addr of last addressable mem loc", "Indicator byte", "Lock byte",
       "Vers. of the mem. bank", "ScaleFactorForActiveEnergy", "ActiveEnergy(MSB)",
       "ActiveEnergy", "ActiveEnergy", "ActiveEnergy", "ActiveEnergy", "ActiveEnergy(LSB)",
       "ScaleFactorForActivePower", "ActivePower(MSB)", "ActivePower", "ActivePower",
       "ActivePower(LSB)"
    };

    QList<QString>memBank203DescList =
    {
       "Addr of last addressable mem loc", "Indicator byte", "Lock byte",
       "Vers. of the mem. bank", "ScaleFactorForApparentEnergy", "ApparentEnergy(MSB)",
       "ApparentEnergy", "ApparentEnergy", "ApparentEnergy", "ApparentEnergy", "ApparentEnergy(LSB)",
       "ScaleFactorForApparentPower,", "ApparentPower(MSB)", "ApparentPower", "ApparentPower",
       "ApparentPower(LSB)"
    };

    QList<QString>memBank204DescList =
    {
       "Addr of last addressable mem loc", "Indicator byte", "Lock byte",
       "Vers. of the mem. bank", "ScaleFactorForLoadsideEnergy", "LoadsideEnergy(MSB)",
       "LoadsideEnergy", "LoadsideEnergy", "LoadsideEnergy", "LoadsideEnergy", "LoadsideEnergy(LSB)",
       "ScaleFactorForLoadsidePower", "LoadsidePower(MSB)", "LoadsidePower", "LoadsidePower",
       "LoadsidePower(LSB)"
    };

    QList<QString>memBank205DescList =
    {
       "Addr of last addressable mem loc", "Indicator byte", "Lock byte",
       "Vers. of the mem. bank", "OperatingTime (MSB)", "OperatingTime",
       "OperatingTime", "OperatingTime (LSB)", "StartCounter (MSB)",
       "StartCounter", "StartCounter (LSB)", "Ext.SupplyVoltage (MSB)",
       "Ext.SupplyVoltage (LSB)", "Ext.SupplyVoltageFreq", "PowerFactor",
       "OverallFailCond", "OverallFailCondCntr", "Ext.SupplyUnderVoltage",
       "Ext.SupplyUnderVoltCntr", "Ext.SupplyOverVoltage", "Ext.SupplyOverVoltCntr",
       "OutputPwrLimit", "OutputPwrLimitCntr",  "ThermalDerating", "ThermalDeratingCntr",
       "ThermalShutDown", "ThermalShutDownCntr", "Temperature", "OutputCurrentPercent",
    };

    QList<QString>memBank206DescList =
    {
       "Addr of last addressable mem loc", "Indicator byte", "Lock byte",
       "Vers. of the mem. bank", "StartCntrRstAble(MSB)", "StartCntrRstAble",
       "StartCntrRstAble(LSB)", "StartCounter(MSB)", "StartCounter",
       "StartCounter(LSB)", "OnTimeRstable(MSB)", "OnTimeRstable",
       "OnTimeRstable", "OnTimeRstable(LSB)", "OnTime(MSB)",
       "OnTime", "OnTime", "OnTime(LSB)", "Voltage(MSB)", "Voltage(LSB)",
       "Current(MSB)", "Current(LSB)", "OverallFailCond.", "OverallFailCond.Cntr",
       "ShortCircuit", "ShortCircuitCntr", "OpenCircuit", "OpenCircuitCntr",
       "ThermalDerating", "ThermalDeratingCntr",
       "ThermalShutDown", "ThermalShutDownCntr", "Temperature"
    };

    QList<QString>memBank207DescList =
    {
       "Addr of last addressable mem loc", "Indicator byte", "Lock byte",
       "Vers. of the mem. bank", "RatedMedianUsefulLifeOfLuminaire",
       "InternalCtrlGearRefTemperature",
       "RatedMedianUsefulLightSrcStarts(MSB)",
       "RatedMedianUsefulLightSrcStarts(LSB)"
    };

    QList<QString>memBank208DescList =
    {
       "Addr of last addressable mem loc", "Indicator byte", "Lock byte",
       "Vers. of the mem. bank", "Ctrl Gear Max Ref Temperature",
       "Ctrl Gear Temperature", "Min Measured Gear Temperature (Total)",
       "Max Measured Gear Temperature (Total)", "Min Measured Gear Temperature (Curr Battery)",
       "Max Measured Gear Temperature (Curr Battery)", "Average Power During Bat Charging",
       "Average Power During BatCharge Maintenance", "Rated Duration Time",
       "Function test time", "Battery Recharge Time", "Battery Failure Counter",
       "Battery Cut-Off Counter", "Lamp Cut-Off Counter (Total)", "Lamp Cut-Off Counter (Curr Battery)",
       "Lamp Emergency Time (Total) (MSB)", "Lamp Emergency Time (Total) (Mid)", "Lamp Emergency Time (Total) (LSB)",
       "Lamp Emergency Time (Curr Battery) (MSB)", "Lamp Emergency Time (Curr Battery) (Mid)", "Lamp Emergency Time (Curr Battery) (LSB)",
       "Battery Connected Time (Total) (MSB)", "Battery Connected Time (Total) (LSB)",
       "Battery Connected Time (Curr Battery) (MSB)", "Battery Connected Time (Curr Battery) (LSB)",
       "Emergency Control Gear Failure Counter", "Battery Duration Failure Counter",
       "Battery Failure Counter", "Emergency Lamp Failure Counter",
       "Func Test Max Delay Exceeded Counter", "Durat Test Max Delay Exceeded Counter",
       "Func Test Failed Counter (Total) (MSB)", "Func Test Failed Counter (Total) (LSB)",
       "Durat Test Failed Counter (Total) ", "Func Test Failed Counter (Curr Battery) (MSB)",
       "Func Test Failed Counter (Curr Battery) (LSB)", "Duration Test Failed Counter (Current Battery)",
       "Start Function Test Counter (MSB)", "Start Function Test Counter (LSB)",
       "Start Duration Test Counter (Total)", "Start Duration Test Counter (Current Battery)",
       "Rest Mode Counter (MSB)", "Rest Mode Counter (LSB)",
       "Emergency Mode Counter (Total) (MSB)", "Emergency Mode Counter (Total) (LSB)",
       "Emergency Mode Counter (Current Battery) (MSB)", "Emergency Mode Counter (Current Battery) (LSB)",
    };

    void setColumnsWidth(QTableView* tabView);
    void membank_init(QStandardItemModel* model, QTableView* tabView, uint8_t rowCnt);
    void fillBooleanParamData(quint8* pData, QString* cellData);
};

#endif // DIAGNOSTICS_H
