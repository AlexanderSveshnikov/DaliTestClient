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

//status byte flags explanation
void daliCommandParcer::explainStatus(quint8 status, QString* statusStr)
{
    *statusStr = "BALLAST [";
    if (bitRead(status, DALIREG_STATUS_BALLAST) == 1) {
        *statusStr += "x";
    } else {
        *statusStr += " ";
    }
    *statusStr += "] LAMP FAIL [";
    if (bitRead(status, DALIREG_STATUS_LAMP_FAILURE) == 1) {
        *statusStr += "x";
    } else {
        *statusStr += " ";
    }
    *statusStr += "] LAMP ARC PWR ON [";
    if (bitRead(status, DALIREG_STATUS_LAMP_ARC_POWER_ON) == 1) {
        *statusStr += "x";
    } else {
       *statusStr += " ";
    }
    *statusStr += "] LIMIT ERR [";
    if (bitRead(status, DALIREG_STATUS_LIMIT_ERROR) == 1) {
        *statusStr += "x";
    } else {
        *statusStr += " ";
    }
    *statusStr += "] FADE RDY [";
    if (bitRead(status, DALIREG_STATUS_FADE_READY) == 1) {
        *statusStr += "x";
    } else {
        *statusStr += " ";
    }
    *statusStr += "] RST STATE [";
    if (bitRead(status, DALIREG_STATUS_RESET_STATE) == 1) {
        *statusStr += "x";
    } else {
        *statusStr += " ";
    }
    *statusStr += "] MISSING SHORT[";
    if (bitRead(status, DALIREG_STATUS_MISSING_SHORT) == 1) {
        *statusStr += "x";
    } else {
        *statusStr += " ";
    }
   *statusStr += "] POWER FAIL[";
    if (bitRead(status, DALIREG_STATUS_POWER_FAILURE) == 1) {
        *statusStr += "x";
    } else {
        *statusStr += " ";
    }
    *statusStr += "]";
}
