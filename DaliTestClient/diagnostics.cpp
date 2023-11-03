#include "diagnostics.h"

diagnostics::diagnostics()
{

}


void diagnostics::setColumnsWidth(QTableView* tabView)
{
    tabView->setColumnWidth(0,20);
    tabView->setColumnWidth(1,155);
    tabView->setColumnWidth(2,45);
    tabView->setColumnWidth(3,70);
}

void diagnostics::membank_init(QStandardItemModel* model, QTableView* tabView, uint8_t rowCnt)
{
    model->setColumnCount(4);
    model->setRowCount(rowCnt);  //maximal bus nodes
    model->setHeaderData(0, Qt::Horizontal, "Адрес");
    model->setHeaderData(1, Qt::Horizontal, "Описание");
    model->setHeaderData(2, Qt::Horizontal, "Данные");
    model->setHeaderData(3, Qt::Horizontal, "Парам.");
    tabView->setStyleSheet("QHeaderView::section { background-color:lightGray }");
    tabView->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    tabView->setEditTriggers(QAbstractItemView::NoEditTriggers);

}

void diagnostics::membank_202_init(QTableView* tabView)
{
    membank_init(&memBank202Model, tabView, MEM_BANK_202_ROW_COUNT);
    for(int i = 0; i < 16; i++)
    {
        memBank202Model.setData(memBank202Model.index(i, 0, QModelIndex()), QString::number(i));
        memBank202Model.setData(memBank202Model.index(i, 1, QModelIndex()), memBank202DescList.at(i));
    }
    tabView->setModel(&memBank202Model);
    setColumnsWidth(tabView);
}

void diagnostics::membank_203_init(QTableView* tabView)
{
    membank_init(&memBank203Model, tabView, MEM_BANK_203_ROW_COUNT);
    for(int i = 0; i < 16; i++)
    {
        memBank203Model.setData(memBank203Model.index(i, 0, QModelIndex()), QString::number(i));
        memBank203Model.setData(memBank203Model.index(i, 1, QModelIndex()), memBank203DescList.at(i));
    }
    tabView->setModel(&memBank203Model);
    setColumnsWidth(tabView);
}

void diagnostics::membank_204_init(QTableView* tabView)
{
    membank_init(&memBank204Model, tabView, MEM_BANK_204_ROW_COUNT);
    for(int i = 0; i < 16; i++)
    {
        memBank204Model.setData(memBank204Model.index(i, 0, QModelIndex()), QString::number(i));
        memBank204Model.setData(memBank204Model.index(i, 1, QModelIndex()), memBank204DescList.at(i));
    }
    tabView->setModel(&memBank204Model);
    setColumnsWidth(tabView);
}

void diagnostics::membank_205_init(QTableView* tabView)
{
    membank_init(&memBank205Model, tabView, MEM_BANK_205_ROW_COUNT);
    for(int i = 0; i < 29; i++)
    {
        memBank205Model.setData(memBank205Model.index(i, 0, QModelIndex()), QString::number(i));
        memBank205Model.setData(memBank205Model.index(i, 1, QModelIndex()), memBank205DescList.at(i));
    }
    tabView->setModel(&memBank205Model);
    setColumnsWidth(tabView);
}

void diagnostics::membank_206_init(QTableView* tabView)
{
    membank_init(&memBank206Model, tabView, MEM_BANK_206_ROW_COUNT);
    for(int i = 0; i < 33; i++)
    {
        memBank206Model.setData(memBank206Model.index(i, 0, QModelIndex()), QString::number(i));
        memBank206Model.setData(memBank206Model.index(i, 1, QModelIndex()), memBank206DescList.at(i));
    }
    tabView->setModel(&memBank206Model);
    setColumnsWidth(tabView);
}

void diagnostics::membank_207_init(QTableView* tabView)
{
     membank_init(&memBank207Model, tabView, MEM_BANK_207_ROW_COUNT);
     for(int i = 0; i < 8; i++)
     {
         memBank207Model.setData(memBank207Model.index(i, 0, QModelIndex()), QString::number(i));
         memBank207Model.setData(memBank207Model.index(i, 1, QModelIndex()), memBank207DescList.at(i));
     }
     tabView->setModel(&memBank207Model);
     setColumnsWidth(tabView);
}

QStandardItemModel* diagnostics::getMembank0Model()
{
    return &memBank0Model;
}

QStandardItemModel* diagnostics::getMembank1Model()
{
    return &memBank1Model;
}

QStandardItemModel* diagnostics::getMembank202Model()
{
    return &memBank202Model;
}

QStandardItemModel* diagnostics::getMembank203Model()
{
    return &memBank203Model;
}

QStandardItemModel* diagnostics::getMembank204Model()
{
    return &memBank204Model;
}

QStandardItemModel* diagnostics::getMembank205Model()
{
    return &memBank205Model;
}

QStandardItemModel* diagnostics::getMembank206Model()
{
    return &memBank206Model;
}

QStandardItemModel* diagnostics::getMembank207Model()
{
    return &memBank207Model;
}

void diagnostics::fillBooleanParamData(quint8* pData, QString* cellData)
{
    switch(*pData)
    {
        case 0:
            *cellData = "OK";
            break;
        case 1:
            *cellData = "ERROR";
            break;
        case UINT8_TMASK:
            *cellData = "tempor. unavail.";
            break;
        case UINT8_MASK:
            *cellData = "unavail.";
            break;
        default:
            *cellData = "Unknown Value";
            break;
    }
}

QStandardItemModel* diagnostics::fillModel( quint8 memBankId, quint8* pData)
{
    quint8* pStart = pData;
    QString cellData = "";
    QStandardItemModel* mdl = NULL;
    switch(memBankId)
    {
        case 0:
            mdl = &memBank0Model;
            for(quint8 i = 0; i < MEM_BANK_0_ROW_COUNT; i++)  //TODO Fill with real vals
            {
                memBank0Model.setData(memBank0Model.index(i, 2, QModelIndex()), "0x" + QString("%1").arg(*pData, 2, 16, QLatin1Char('0'))); //Address
                pData++;
            }
            break;
        case 1:
            mdl = &memBank1Model;
            for(quint8 i = 0; i < MEM_BANK_1_ROW_COUNT; i++)  //TODO Fill with real vals
            {
                memBank1Model.setData(memBank1Model.index(i, 2, QModelIndex()), "0x" + QString("%1").arg(*pData, 2, 16, QLatin1Char('0'))); //Address
                pData++;
            }
            break;
        case 202:
            mdl = &memBank202Model;
            for(quint8 i = 0; i < MEM_BANK_202_ROW_COUNT; i++)
            {
                memBank202Model.setData(memBank202Model.index(i, 2, QModelIndex()), "0x" + QString("%1").arg(*pData, 2, 16, QLatin1Char('0'))); //Address
                pData++;
            }
            break;
        case 203:
            mdl = &memBank203Model;
            for(quint8 i = 0; i < MEM_BANK_203_ROW_COUNT; i++)
            {
                memBank203Model.setData(memBank203Model.index(i, 2, QModelIndex()), "0x" + QString("%1").arg(*pData, 2, 16, QLatin1Char('0'))); //Address
                pData++;
            }
            break;
        case 204:
            mdl = &memBank204Model;
            for(quint8 i = 0; i < MEM_BANK_204_ROW_COUNT; i++)
            {
                memBank204Model.setData(memBank204Model.index(i, 2, QModelIndex()), "0x" + QString("%1").arg(*pData, 2, 16, QLatin1Char('0'))); //Address
                pData++;
            }
            break;
        case 205:
            mdl = &memBank205Model;
            for(quint8 i = 0; i < MEM_BANK_205_ROW_COUNT; i++)
            {
                memBank205Model.setData(memBank205Model.index(i, 2, QModelIndex()), "0x" + QString("%1").arg(*pData, 2, 16, QLatin1Char('0'))); //Address
                cellData = "";
                quint8 offset = (quint8)(pData - pStart);
                if(offset == MBANK_205_OPERATING_TIME_OFFSET)
                {
                    opTime = ((uint32_t)(*pData)) << 24;
                }
                else if(offset == (MBANK_205_OPERATING_TIME_OFFSET+1))
                {
                    opTime |= ((uint32_t)(*pData)) << 16;
                }
                else if(offset == (MBANK_205_OPERATING_TIME_OFFSET+2))
                {
                    opTime |= ((uint32_t)(*pData)) << 8;
                }
                else if(offset == MBANK_205_OPERATING_TIME_OFFSET+3)
                {
                    opTime |= (uint32_t)(*pData);
                    cellData = QString::number(opTime) + " Sec";
                }
                else if(offset == MBANK_205_START_CNTR_OFFSET)
                {
                    startCntr = ((uint32_t)(*pData)) << 16;
                }
                else if(offset == (MBANK_205_START_CNTR_OFFSET+1))
                {
                    startCntr |= ((uint32_t)(*pData)) << 8;
                }
                else if(offset == (MBANK_205_START_CNTR_OFFSET+2))
                {
                    startCntr |= (uint32_t)(*pData);
                    cellData = QString::number(startCntr) + " counts";
                }
                else if((offset == MBANK_205_OVERAL_FAIL_COND_OFFSET) || (offset == MBANK_205_THERMAL_DERATING_OFFSET) ||\
                        (offset == MBANK_205_THERMAL_SHUTDOWN_OFFSET))
                {
                     fillBooleanParamData(pData, &cellData);
                }
                else if((offset == MBANK_205_OVERAL_FAIL_COND_CNTR_OFFSET) || (offset == MBANK_205_THERMAL_DERATING_CNTR_OFFSET) ||\
                        (offset == MBANK_205_THERMAL_SHUTDOWN_CNTR_OFFSET))
                {
                    if(*pData < UINT8_TMASK)
                        cellData = QString::number(*pData) + " counts";
                    else if(*pData == UINT8_TMASK)
                        cellData = "UnAvail";
                }
                else if(offset == MBANK_205_TEMP_VALUE_OFFSET)
                {
                    qint8 temp = *pData - 60; //A value of 60 means 0 °C, a value of 0 means – 60 °C.
                    cellData = QString::number(temp) + "°C";
                }
                else
                {
                    cellData = "NotDef";
                }
                memBank205Model.setData(memBank205Model.index(i, 3, QModelIndex()), cellData); //
                pData++;
            }
            break;
        case 206:
            mdl = &memBank206Model;
            for(quint8 i = 0; i < MEM_BANK_206_ROW_COUNT; i++)
            {
                memBank206Model.setData(memBank206Model.index(i, 2, QModelIndex()), "0x" + QString("%1").arg(*pData, 2, 16, QLatin1Char('0'))); //Address
                cellData = "";
                quint8 offset = (quint8)(pData - pStart);
                if((offset == MBANK_206_START_CNTR_RSTABLE_OFFSET) || (offset == MBANK_206_START_CNTR_OFFSET))
                {
                    startCntr = ((uint32_t)(*pData)) << 16;
                }
                else if((offset == MBANK_206_START_CNTR_RSTABLE_OFFSET+1) || (offset == MBANK_206_START_CNTR_OFFSET+1))
                {
                    startCntr |= ((uint32_t)(*pData)) << 8;
                }
                else if((offset == MBANK_206_START_CNTR_RSTABLE_OFFSET+2) || (offset == MBANK_206_START_CNTR_OFFSET+2))
                {
                    startCntr |= (uint32_t)(*pData);
                    cellData = QString::number(startCntr) + " counts";
                }

                else if((offset == MBANK_206_ON_TIME_RSTABLE_OFFSET) || (offset == MBANK_206_ON_TIME_OFFSET))
                {
                    opTime = ((uint32_t)(*pData)) << 24;
                }
                else if((offset == MBANK_206_ON_TIME_RSTABLE_OFFSET+1) || (offset == MBANK_206_ON_TIME_OFFSET+1))
                {
                    opTime |= ((uint32_t)(*pData)) << 16;
                }
                else if((offset == MBANK_206_ON_TIME_RSTABLE_OFFSET+2) || (offset == MBANK_206_ON_TIME_OFFSET+2))
                {
                    opTime |= ((uint32_t)(*pData)) << 8;
                }
                else if((offset == MBANK_206_ON_TIME_RSTABLE_OFFSET+3) || (offset == MBANK_206_ON_TIME_OFFSET+3))
                {
                    opTime |= (uint32_t)(*pData);
                    cellData = QString::number(opTime) + " Sec";
                }
                else if((offset == MBANK_206_THERMAL_DERATING_OFFSET) || (offset == MBANK_206_THERMAL_SHUTDOWN_OFFSET) ||\
                        (offset == MBANK_206_OVERALL_FAIL_COND_OFFSET))
                {
                    fillBooleanParamData(pData, &cellData);
                }
                else if((offset == MBANK_206_THERMAL_DERATING_CNTR_OFFSET) || (offset == MBANK_206_THERMAL_SHUTDOWN_CNTR_OFFSET) ||\
                        (offset == MBANK_206_OVERALL_FAIL_COND_CNT_OFFSET))
                {
                    if(*pData < UINT8_TMASK)
                        cellData = QString::number(*pData) + " counts";
                    else if(*pData == UINT8_TMASK)
                        cellData = "UnAvail";

                }
                else if(offset == MBANK_206_TEMP_VALUE_OFFSET)  //temperature
                {
                   qint8 temp = *pData - 60; //A value of 60 means 0 °C, a value of 0 menas – 60 °C.
                   cellData = QString::number(temp) + "°C";
                }
                else
                {
                    cellData = "NotDef";
                }
                memBank206Model.setData(memBank206Model.index(i, 3, QModelIndex()), cellData); //
                pData++;
            }
            break;
        case 207:
            mdl = &memBank207Model;
            for(quint8 i = 0; i < MEM_BANK_207_ROW_COUNT; i++)
            {
                memBank207Model.setData(memBank207Model.index(i, 2, QModelIndex()), "0x" + QString("%1").arg(*pData, 2, 16, QLatin1Char('0'))); //Address
                cellData = "";
                quint8 offset = (quint8)(pData - pStart);
                if(offset == MBANK_207_RATED_MED_USEFUL_LIFE_OFFSET)
                {
                    if(*pData < UINT8_TMASK)
                    {
                        cellData = QString::number(*pData) + "*10**3 Hrs";
                    }
                    else
                    {
                        cellData = "UnAvail";
                    }
                }
                else if(offset == MBANK_207_INT_CTRL_GEAR_REF_TEMP_OFFSET)
                {
                    if(*pData < UINT8_TMASK)
                    {
                        cellData = QString::number(*pData - 60) + "°C";
                    }
                    else
                    {
                        cellData = "UnAvail";
                    }
                }
                else if(offset == MBANK_207_RATED_MED_USEFUL_LIT_SRC_STARTS_OFFSET)
                {
                    startCntr = ((uint16_t)(*pData)) << 8;
                }
                else if(offset == MBANK_207_RATED_MED_USEFUL_LIT_SRC_STARTS_OFFSET+1)
                {
                    startCntr |= (uint16_t)(*pData);
                    if(startCntr == UINT16_TMASK)
                        cellData =  "UnAvail";
                    else
                        cellData = QString::number(startCntr) + " starts";
                }
                memBank207Model.setData(memBank207Model.index(i, 3, QModelIndex()), cellData); //
                pData++;
            }
            break;
        default:

            break;
    }
    return mdl;
}
