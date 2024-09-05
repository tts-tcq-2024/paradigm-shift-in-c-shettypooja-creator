#include <stdio.h>
#include <assert.h>

int checkRange(float value, float min, float max, const char* message) 
{
    if(value < min || value > max) 
    {
        printf("%s out of range!\n", message);
        return 0;
    }
    return 1;
}

int batteryIsOk(float temperature, float soc, float chargeRate) 
{
    int returnVal = 1;
    returnVal &= checkRange(temperature, 0, 45, "Temperature");
    returnVal &= checkRange(soc, 20, 80, "State of Charge");
    returnVal &= checkRange(chargeRate, 0, 0.8, "Charge Rate");
    return returnVal;
}

int main() 
{
    assert(batteryIsOk(25, 70, 0.7));  
    assert(batteryIsOk(50, 85, 0));   
}
