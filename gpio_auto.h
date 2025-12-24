#ifndef GPIO_AUTO_H
#define GPIO_AUTO_H

#include "stm32c0xx_hal.h"

// Shortcut defines for ports
#define PA GPIOA
#define PB GPIOB
#define PC GPIOC
#define PD GPIOD
#define PE GPIOE
#define PF GPIOF

// Shortcut defines for pin numbers
#define P0  GPIO_PIN_0
#define P1  GPIO_PIN_1
#define P2  GPIO_PIN_2
#define P3  GPIO_PIN_3
#define P4  GPIO_PIN_4
#define P5  GPIO_PIN_5
#define P6  GPIO_PIN_6
#define P7  GPIO_PIN_7
#define P8  GPIO_PIN_8
#define P9  GPIO_PIN_9
#define P10 GPIO_PIN_10
#define P11 GPIO_PIN_11
#define P12 GPIO_PIN_12
#define P13 GPIO_PIN_13
#define P14 GPIO_PIN_14
#define P15 GPIO_PIN_15,

// Shortcut defines for modes, pulls, speeds
#define OUTPUT   GPIO_MODE_OUTPUT_PP
#define INPUT    GPIO_MODE_INPUT
#define ANALOG   GPIO_MODE_ANALOG
#define ALT      GPIO_MODE_AF_PP

// Shortcut defines for pull-up/pull-down and speed
#define NP      GPIO_NOPULL
#define PU      GPIO_PULLUP
#define PD      GPIO_PULLDOWN

// Shortcut defines for speeds
#define LOW_SPEED     GPIO_SPEED_FREQ_LOW
#define MED_SPEED     GPIO_SPEED_FREQ_MEDIUM
#define HIGH_SPEED    GPIO_SPEED_FREQ_HIGH
#define MAX_SPEED     GPIO_SPEED_FREQ_VERY_HIGH

typedef struct
{
    GPIO_TypeDef *PORT;    // GPIOA, GPIOB, GPIOC ...
    uint16_t PIN;          // GPIO_PIN_0 ... GPIO_PIN_15
    uint32_t MODE;         // GPIO_MODE_OUTPUT_PP, INPUT, AF, ANALOG
    uint32_t PULL;         // GPIO_NOPULL, GPIO_PULLUP, GPIO_PULLDOWN
    uint32_t SPEED;        // GPIO_SPEED_FREQ_LOW, MEDIUM, HIGH, VERY_HIGH
} GPIO_Config_t; 


void GPIO_AutoInit(GPIO_Config_t *cfg, uint32_t count);


#endif
