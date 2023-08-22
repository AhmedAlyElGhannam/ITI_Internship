#ifndef LCD_CFG_H_
#define LCD_CFG_H_

/** MAKE SURE TO INCLUDE LCD_Private first in LC_Prog */

/**Options: LCD_8BIT_MODE || LCD_4BIT_MODE*/
#define LCD_MODE_OF_OPERATION LCD_8BIT_MODE

/**Options: LCD_1LINE_MODE || LCD_2LINE_MODE*/
#define LCD_LINE_MODE LCD_2LINE_MODE

#if (LCD_MODE_OF_OPERATION == LCD_8BIT_MODE)
	
	#define LCD_DATA_PORT DIO_PORTA
	#define LCD_CTRL_PORT DIO_PORTB
	#define LCD_CTRL_RS DIO_PIN0
	#define LCD_CTRL_RW DIO_PIN1
	#define LCD_CTRL_EN DIO_PIN2
	
#elif (LCD_MODE_OF_OPERATION == LCD_4BIT_MODE)
	
	#define LCD_DATA_PORT DIO_PORTA
	#define LCD_CTRL_PORT DIO_PORTA
	#define LCD_CTRL_RS DIO_PIN0
	#define LCD_CTRL_RW DIO_PIN1
	#define LCD_CTRL_EN DIO_PIN2
	#define LCD_DATA_PIN0 DIO_PIN3
	#define LCD_DATA_PIN1 DIO_PIN4
	#define LCD_DATA_PIN2 DIO_PIN5
	#define LCD_DATA_PIN3 DIO_PIN6

#endif

#define LCD_SET_FLAG 1
#define LCD_RESET_FLAG 0

#endif