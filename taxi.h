#ifndef TAXI_H
#define TAXI_H

#include "date.h"

class Taxi
{
public:
    Taxi(unsigned int carCode, unsigned int bodyCode, unsigned int engineCode, unsigned int brandCode, unsigned int registerCode, unsigned int driverCode, unsigned int mechanicCode);
    Taxi() = default;
    ~Taxi() = default;

    unsigned int getRegisterCode() const;
    void setRegisterCode(unsigned int code);

    unsigned int getCarCode() const;
    void setCarCode(unsigned int code);

    unsigned int getBrandCode() const;
    void setBrandCode(unsigned int code);

    unsigned int getBodyCode() const;
    void setBodyCode(unsigned int code);

    unsigned int getEngineCode() const;
    void setEngineCode(unsigned int code);

    unsigned int getDriverCode() const;
    void setDriverCode(unsigned int code);

    unsigned int getMechanicCode() const;
    void setMechanicCode(unsigned int code);

    std::string getFullCode();

    unsigned short getProductionYear() const;
    void setProductionYear(unsigned short year);

    unsigned int getMileage() const;
    void setMileage(unsigned int mileage);

    Date getLastInspectionDate() const;
    void setLastInspectionDate(const Date& date);

    bool isActive() const;
    void setActive();
    void setUnactive();

    int calculateEstimatedPrice();

private:
    unsigned int m_CarCode, m_BodyCode, m_EngineCode, m_BrandCode, m_RegisterCode, m_DriverCode, m_MechanicCode;
    unsigned short m_ProductionYear;
    unsigned int m_Mileage;
    Date m_LastInspectionDate;
    bool m_IsActive = false;
};

#endif // TAXI_H
