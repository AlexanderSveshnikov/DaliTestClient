#include "daliCommandParcer.h"

daliCommandParcer::daliCommandParcer()
{

}

quint8 daliCommandParcer::getSpecialCmdAddrByteFromNumber(int number)
{
    quint8 rval = 0;
    for(quint8 i = 0; i < sizeof(specCmdsConvTab)/sizeof(specCmdsConvTab[0]); i++)
    {
        if(specCmdsConvTab[i].cmdNum == number)
        {
            rval = specCmdsConvTab[i].addressByte;
            break;
        }
    }
    return rval;
}

/**
 * @param cmd_type  broadcast, group or individual
 * @param destination either group address or individual address. Or Null if cmd_type = broadcast
 */
quint8 daliCommandParcer::getStandartCmdAddrByte(quint8 cmd_type, quint8 destination, bool is_dapc)
{
    quint8 addr_byte = 0;
    if(cmd_type == TYPE_BROADCAST)
    {
        addr_byte = 0xFF;
    }
    else if(cmd_type == TYPE_BROADCAST_UNADDR)
    {
        addr_byte = 0xFD;
    }
    else if(cmd_type == TYPE_GROUP)
    {
        addr_byte = destination<<1;
        addr_byte |= 0x81; //Bit 8 =’1’: standard command; bit 15 = 1
        addr_byte &= 0x9F; //Bits 14, 13 = 0
    }
    else if(cmd_type == TYPE_ADDRESS)
    {
        addr_byte = destination<<1;
        addr_byte |= 0x01; //Bit 8 =’1’: standard command;
        addr_byte &= 0x7F; //Bit 15 = 0
    }
    if(is_dapc)
        addr_byte &= 0xFE; //Bit 8 =’0’: direct arc power control (DAPC) command;
    return addr_byte;
}

quint8 daliCommandParcer::getSpecialCmdOpcodeByte(quint16 cmdId, quint8 data)
{
    quint8 opcode = 0;

    if(cmdId == 272) //ROUTH HARDCODING - NO NEED to setup data
    {
        data = 6;
    }

    for(quint8 i = 0; i < sizeof(specCmdsConvTab)/sizeof(specCmdsConvTab[0]); i++)
    {
        if(specCmdsConvTab[i].cmdNum  == cmdId)
        {
            if(specCmdsConvTab[i].opcodeNotNull)
            {
                opcode = data;
                break;
            }
        }
    }
    return opcode;
}

bool daliCommandParcer::checkCmdIssueTwice(quint16 cmdId, quint8 specification)
{
    bool rval = false;
    if(cmdId > 0xFF) //Special commands
    {
        for(quint8 i = 0; i < sizeof(specCmdsConvTab)/sizeof(specCmdsConvTab[0]); i++)
        {
            if(specCmdsConvTab[i].cmdNum  == cmdId)
            {
                rval =  specCmdsConvTab[i].sendTwice;
                break;
            }
        }
    }
    else  //Standart commands
    {
        bool found = false;
        for(quint8 i = 0; i < sizeof(standartCmdsConvTab)/sizeof(standartCmdsConvTab[0]); i++)
        {
            if(standartCmdsConvTab[i].cmdNum  == cmdId)
            {
                rval =  standartCmdsConvTab[i].sendTwice;
                found = true;
                break;
            }
        }
        if(!found)
        {
            if(specification == SPEC_LED_LAMP)
            {
                for(quint8 i = 0; i < sizeof(extendedCmdsSpec207ConvTab)/sizeof(extendedCmdsSpec207ConvTab[0]); i++)
                {
                    if(extendedCmdsSpec207ConvTab[i].cmdNum  == cmdId)
                    {
                        rval =  extendedCmdsSpec207ConvTab[i].sendTwice;
                        found = true;
                        break;
                    }
                }
            }
            else if(specification == SPEC_INCANDESCENT_LAMP)
            {
                for(quint8 i = 0; i < sizeof(extendedCmdsSpec205ConvTab)/sizeof(extendedCmdsSpec205ConvTab[0]); i++)
                {
                    if(extendedCmdsSpec205ConvTab[i].cmdNum  == cmdId)
                    {
                        rval =  extendedCmdsSpec205ConvTab[i].sendTwice;
                        found = true;
                        break;
                    }
                }

            }
            else if(specification == SPEC_COLOUR_CONTROL)
            {
                for(quint8 i = 0; i < sizeof(extendedCmdsSpec209ConvTab)/sizeof(extendedCmdsSpec209ConvTab[0]); i++)
                {
                    if(extendedCmdsSpec209ConvTab[i].cmdNum  == cmdId)
                    {
                        rval =  extendedCmdsSpec209ConvTab[i].sendTwice;
                        found = true;
                        break;
                    }
                }

            }
        }
    }
    return rval;
}

bool daliCommandParcer::checkCmdNeedAnswer(quint16 cmdId, quint8 specification)
{
    bool rval = false;
    if(cmdId > 0xFF) //Special commands
    {
        for(quint8 i = 0; i < sizeof(specCmdsConvTab)/sizeof(specCmdsConvTab[0]); i++)
        {
            if(specCmdsConvTab[i].cmdNum  == cmdId)
            {
                rval =  specCmdsConvTab[i].answer;
            }
        }
    }
    else  //Standart commands
    {
        bool found = false;
        for(quint8 i = 0; i < sizeof(standartCmdsConvTab)/sizeof(standartCmdsConvTab[0]); i++)
        {
            if(standartCmdsConvTab[i].cmdNum  == cmdId)
            {
                rval =  standartCmdsConvTab[i].answer;
                found = true;
                break;
            }
        }
        if(!found)
        {
            if(specification == SPEC_LED_LAMP)
            {
                for(quint8 i = 0; i < sizeof(extendedCmdsSpec207ConvTab)/sizeof(extendedCmdsSpec207ConvTab[0]); i++)
                {
                    if(extendedCmdsSpec207ConvTab[i].cmdNum  == cmdId)
                    {
                        rval =  extendedCmdsSpec207ConvTab[i].answer;
                        found = true;
                        break;
                    }
                }
            }
            else if(specification == SPEC_INCANDESCENT_LAMP)
            {
                for(quint8 i = 0; i < sizeof(extendedCmdsSpec205ConvTab)/sizeof(extendedCmdsSpec205ConvTab[0]); i++)
                {
                    if(extendedCmdsSpec205ConvTab[i].cmdNum  == cmdId)
                    {
                        rval =  extendedCmdsSpec205ConvTab[i].answer;
                        found = true;
                        break;
                    }
                }
            }
            else if(specification == SPEC_COLOUR_CONTROL)
            {
                for(quint8 i = 0; i < sizeof(extendedCmdsSpec209ConvTab)/sizeof(extendedCmdsSpec209ConvTab[0]); i++)
                {
                    if(extendedCmdsSpec209ConvTab[i].cmdNum  == cmdId)
                    {
                        rval =  extendedCmdsSpec209ConvTab[i].answer;
                        found = true;
                        break;
                    }
                }
            }
        }
    }
    return rval;
}

bool daliCommandParcer::checkCmdSpecial(quint16 cmdId)
{
    bool rval = false;
    if(cmdId > 0xFF) //Special commands
    {
       rval = true;
    }
    return rval;
}

void daliCommandParcer::parseStatus(uint8_t status, QString* resStr)
{
    QString statusText = "Status:\r\n";
    if(status & 0x01)
       statusText += "controlGearFailure\r\n";
    if(status & 0x02)
       statusText += "lampFailure\r\n";
    if(status & 0x04)
       statusText += "lampOn\r\n";
    if(status & 0x08)
       statusText += "limitError\r\n";
    if(status & 0x10)
       statusText += "fadeRunning\r\n";
    if(status & 0x20)
       statusText += "resetState\r\n";
    if(status & 0x40)
       statusText += "shortAddress = MASK\r\n";
    if(status & 0x80)
       statusText += "powerCycleSeen\r\n";
    *resStr = statusText;
}

void daliCommandParcer::parseFadeTimeRate(uint8_t time_rate, QString* resStr)
{
    quint8 time = (time_rate>>4) & 0x0F;
    quint8 rate = time_rate & 0x0F;
    QString fadeTimeStr;
    QString fadeRateStr;
    float fade_time_table[] = {0.7, 1.0, 1.4, 2.0, 2.8, 4.0, 5.7, 8.0, 11.3, 16.0, 22.6, 32.0, 45.3, 64.0, 90.5};
    float fade_rate_table[] = {358.0, 253.0, 179.0, 127.0, 89.4, 63.3, 44.7, 31.6, 22.4, 15.8, 11.2, 7.9, 5.6, 4.0, 2.8};
    if(time == 0)
        fadeTimeStr = "Extended fade time";
    else if (time <= sizeof(fade_time_table))
        fadeTimeStr = "fade time = " + QString::number(time) + " (" + QString::number(fade_time_table[time - 1]) + " s), ";
    else
        fadeTimeStr = "Wrong fade time value, ";

    if((rate == 0) || (rate > sizeof(fade_rate_table)))
       fadeRateStr = "Wrong fade rate value";
    else
       fadeRateStr = "fade rate = " + QString::number(rate) + " (" + QString::number(fade_rate_table[rate - 1]) + " steps/s), ";
    *resStr = fadeTimeStr + fadeRateStr;
}

void daliCommandParcer::parseDeviceType(uint8_t devType, QString* resStr)
{
    switch(devType)
    {
        case 254:
            *resStr = "No part 2xx supported";
            break;
        case 255:
            *resStr = "More than one dev. type/feature supported";
            break;
        case 1:
            *resStr = "Self-contained emergency lighting";
        break;
        case 4:
            *resStr = "Uncandescent Lamp";
            break;
        case 6:
            *resStr = "LED Lamp";
            break;
        case 8:
            *resStr = "Colour control";
            break;
    }
}

//status byte flags explanation
void daliCommandParcer::explainReply(uint16_t commandId, uint8_t reply, QString* resStr)
{
    switch(commandId)
    {
        case QUERY_STATUS:
            parseStatus(reply, resStr);
            break;
        case QUERY_FADE_TIME_RATE:
            parseFadeTimeRate(reply, resStr);
            break;
        case QUERY_DEVICE_TYPE:
            parseDeviceType(reply, resStr);
            break;
        case QUERY_POWER_ON_LEVEL:
        case QUERY_SYSTEM_FAILURE_LEVEL:
            if(reply == 0XFF)
                *resStr = "MAX level";
            else
                *resStr = "";
            break;
        default:
            *resStr = "";
            break;
    }
}

void daliCommandParcer::explainLedLampRpl(uint16_t commandId, uint8_t reply, QString* resStr)
{

}

void daliCommandParcer::explainIncandescentLampRpl(uint16_t commandId, uint8_t reply, QString* resStr)
{

}

//spec 209

//bit 0     Automatic Activation;               '0' = No
//bit 1..5  Reserved;                           '0' = default value
//bit 6     Auto calibration supported;         '0' = No
//bit 7     Auto calibration recovery supported '0' = No
void daliCommandParcer::spec209ParseFeaturesStatus(uint16_t status, QString* resStr)
{
    QString statusText = "Features/Status:\r\n";
    statusText += "Automatic Activation: ";
    if(status & 0x01)
       statusText += "Yes\r\n";
    else
      statusText += "No\r\n";
    statusText += "Auto calibration supported: ";
    if(status & 0x40)
       statusText += "Yes\r\n";
    else
      statusText += "No\r\n";
    statusText += "Auto calibration recovery supported: ";
    if(status & 0x80)
       statusText += "Yes\r\n";
    else
      statusText += "No\r\n";
    *resStr = statusText;
}

//bit 0     xy-coordinate colour point out of range;    '0' = No
//bit 1     Colour temperature TC out of range;         '0' = No
//bit 2     Auto calibration running;                   '0' = No
//bit 3     Auto calibration successful;                '0' = No
//bit 4     Colour type xy-coordinate active;           '0' = No
//bit 5     Colour type colour temperature TC active;   '0' = No
//bit 6     Colour type primary N active;               '0' = No
//bit 7     Colour type RGBWAF active;                  '0' = No
void daliCommandParcer::spec209ParseColourStatus(uint16_t reply, QString* resStr)
{
    QString statusText = "Colour Status:\r\n";
    if(reply & 0x01)
       statusText += "xy-coordinate colour point out of range\r\n";
    if(reply & 0x02)
       statusText += "Colour temperature TC out of range\r\n";
    if(reply & 0x04)
       statusText += "Auto calibration running\r\n";
    if(reply & 0x08)
       statusText += "Auto calibration successful\r\n";
    if(reply & 0x10)
       statusText += "Colour type xy-coordinate active\r\n";
    if(reply & 0x20)
       statusText += "Colour type colour temperature TC active\r\n";
    if(reply & 0x40)
       statusText += "Colour type primary N active\r\n";
    if(reply & 0x80)
       statusText += "Colour type RGBWAF active\r\n";
    *resStr = statusText;
}

//bit 0     xy-coordinate capable;          '0' = No
//bit 1     Colour temperature TC capable;  '0' = No
//bit 2..4  Number of primaries;            '0'..'6'
//bit 5..7  Number of RGBWAF channels;      '0'..'6'
void daliCommandParcer::spec209ParseColourTypeFeatures(uint16_t reply, QString* resStr)
{
    QString statusText = "Colour Type Features:\r\n";
    statusText += "xy-coordinate capable: ";
    if(reply & 0x01)
        statusText += "Yes\r\n";
    else
        statusText += "No\r\n";
    statusText += "Colour temperature TC capable: ";
    if(reply & 0x02)
        statusText += "Yes\r\n";
    else
        statusText += "No\r\n";

    uint8_t numPrim = (reply>>2) & 0x07;
    statusText += "Number of primaries: " + QString::number(numPrim) + "\r\n";
    numPrim = (reply>>5) & 0x07;
    statusText += "Number of RGBWAF channels: " + QString::number(numPrim) + "\r\n";
    *resStr = statusText;
}

//bit 0     output channel 0/Red;           '0' = Unlinked, '1' = Linked
//bit 1     output channel 1/Green;         '0' = Unlinked, '1' = Linked
//bit 2     output channel 2/Blue;          '0' = Unlinked, '1' = Linked
//bit 3     output channel 3/White;         '0' = Unlinked, '1' = Linked
//bit 4     output channel 4/Amber;         '0' = Unlinked, '1' = Linked
//bit 5     output channel 5/Freecolour;    '0' = Unlinked, '1' = Linked
//bits 7..6 control type;                   ‘00’ = Channel control
//                                          ‘01’ = Colour control
//                                          ‘10’ = Normalised colour control
//                                          ‘11’ = Reserved
void daliCommandParcer::spec209ParseRGBWAFControl(uint16_t reply, QString* resStr)
{
    QString statusText = "RGBWAF Control:\r\n";
    statusText += "output channel 0/Red: ";
    if(reply & 0x01)
        statusText += "Linked\r\n";
    else
        statusText += "Unlinked\r\n";
    statusText += "output channel 1/Green: ";
    if(reply & 0x02)
        statusText += "Linked\r\n";
    else
        statusText += "Unlinked\r\n";
    statusText += "output channel 2/Blue: ";
    if(reply & 0x04)
        statusText += "Linked\r\n";
    else
        statusText += "Unlinked\r\n";
    statusText += "output channel 3/White: ";
    if(reply & 0x08)
        statusText += "Linked\r\n";
    else
        statusText += "Unlinked\r\n";
    statusText += "output channel 4/Amber ";
    if(reply & 0x10)
        statusText += "Linked\r\n";
    else
        statusText += "Unlinked\r\n";
    statusText += "output channel 5/Freecolour: ";
    if(reply & 0x20)
        statusText += "Linked\r\n";
    else
        statusText += "Unlinked\r\n";
   uint8_t controlType = (reply>>6) & 0x03;
   statusText += "Control Type: ";
   if(controlType == 0)
        statusText += "Channel control\r\n";
   else if(controlType == 1)
        statusText += "Colour control\r\n";
   else if(controlType == 2)
        statusText += "Normalised colour control\r\n";
   else if(controlType == 3)
        statusText += "Reserved\r\n";
    *resStr = statusText;
}


//Reply explanation depends on value saved into DTR0 dev reg!!!
void daliCommandParcer::spec209ParseColourValue(uint16_t reply, QString* resStr)
{
    *resStr = "Colour value = " + QString::number(reply);
}

void daliCommandParcer::explainColourControlRpl(uint16_t commandId, uint8_t reply, QString* resStr)
{
    switch(commandId)
    {
        case SPEC_209_QUERY_GEAR_FEATURES_STATUS:
            spec209ParseFeaturesStatus(reply, resStr);
            break;
        case SPEC_209_QUERY_COLOUR_STATUS:
            spec209ParseColourStatus(reply, resStr);
            break;
        case SPEC_209_QUERY_COLOUR_TYPE_FEATURES:
            spec209ParseColourTypeFeatures(reply, resStr);
            break;
        case SPEC_209_QUERY_RGBWAF_CONTROL:
            spec209ParseRGBWAFControl(reply, resStr);
            break;
        case SPEC_209_QUERY_COLOUR_VALUE:
            spec209ParseColourValue(reply, resStr);
            break;
        default:
            *resStr = "";
            break;
    }
}

void daliCommandParcer::explainEmergLightningRpl(uint16_t commandId, uint8_t reply, QString* resStr)
{
    switch(commandId)
    {
        ///TODO: place individual parsers here
        default:
            *resStr = "spec 202 reply:" + QString::number(reply);
            break;
    }
}

void daliCommandParcer::explainExtReply(uint16_t commandId, uint8_t reply, QString* resStr, quint8 spec)
{
    switch(spec)
    {
        case SPEC_LED_LAMP:
            explainLedLampRpl(commandId, reply, resStr);
            break;
        case SPEC_SELF_CONTAINED_EMERGENCY_LIGHTNING:
            explainEmergLightningRpl(commandId, reply, resStr);
            break;
        case SPEC_INCANDESCENT_LAMP:
            explainIncandescentLampRpl(commandId, reply, resStr);
            break;
        case SPEC_COLOUR_CONTROL:
            explainColourControlRpl(commandId, reply, resStr);
            break;
        default:
            break;
    }
}
