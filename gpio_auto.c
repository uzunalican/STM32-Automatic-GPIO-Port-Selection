#include "gpio_auto.h"


// Structure to hold unique ports
typedef struct
{
    GPIO_TypeDef *PORT;
} UniquePort_t;

UniquePort_t uniquePorts[6];   // Max 6 ports (A-F)
uint32_t uniqueCount = 0;      // Number of unique ports found

void GPIO_AutoInit(GPIO_Config_t *cfg, uint32_t count)
{
    
    // Identify unique ports in the configuration array
    for(uint32_t i = 0; i < count; i++)
    {
        uint8_t found = 0;  // Flag to check if port is already recorded
        for(uint32_t j = 0; j < uniqueCount; j++)
        {
            if(uniquePorts[j].PORT == cfg[i].PORT)
            {
                found = 1;  // Port already recorded
                break;
            }
        }
        // If port not found, add it to the unique ports array
        if(!found)
        {
            uniquePorts[uniqueCount].PORT = cfg[i].PORT;
            uniqueCount++;
        }
    }

    // Enable clocks for all unique ports
    for(uint32_t i = 0; i < uniqueCount; i++)
    {
        if(uniquePorts[i].PORT == GPIOA) __HAL_RCC_GPIOA_CLK_ENABLE();
        else if(uniquePorts[i].PORT == GPIOB) __HAL_RCC_GPIOB_CLK_ENABLE();
        else if(uniquePorts[i].PORT == GPIOC) __HAL_RCC_GPIOC_CLK_ENABLE();
        else if(uniquePorts[i].PORT == GPIOD) __HAL_RCC_GPIOD_CLK_ENABLE();
        else if(uniquePorts[i].PORT == GPIOE) __HAL_RCC_GPIOE_CLK_ENABLE();
        else if(uniquePorts[i].PORT == GPIOF) __HAL_RCC_GPIOF_CLK_ENABLE();
        }


}
