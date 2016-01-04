#ifndef __CONSTANTS_H
#define __CONSTANTS_H



#define HEX	16
#define DEC	10

//=======================================================================================================
// VBE

#define VBE_INTERRUPT		0x10
#define VBE_FUNCTION		0x4F
#define RETURN_MODE_INFO	0x1
#define SET_VIDEO_MODE		0x02
#define LINEAR_MODEL_BIT	14
#define SET_TEXT_FUNCTION	0x0
#define RETURN_DATA			0x0

#define D0	BIT(0)
#define D1	BIT(1)
#define D2	BIT(2)

#define PB2BASE(x) (((x) >> 4) & 0x0F000)
#define PB2OFF(x) ((x) & 0x0FFFF)



/* Constants for VBE 0x105 mode */
#define VBE_105_MODE	0x105
#define VRAM_PHYS_ADDR	0xF0000000
#define H_RES           1024
#define V_RES		  	768
#define BITS_PER_PIXEL	8
#define TEXT_MODE		0x03 	/* 80x25 text mode*/


#define BLACK	0
#define PLATFORM_COLOR_1 57
#define PLATFORM_COLOR_2 8

//=======================================================================================================
// TIMER

#define TIMER_FREQ  1193182    /**< @brief clock frequency for timer in PC and AT */
#define TIMER_DEFAULT_FREQ	60
#define SECOND	60

#define BIT(n) (0x01<<(n))

#define TIMER0_IRQ	        0    /**< @brief Timer 0 IRQ line */
#define TIMER_HOOK_BIT		0

/* I/O port addresses */

#define TIMER_0			0x40 /**< @brief Timer 0 count register */
#define TIMER_1			0x41 /**< @brief Timer 1 count register */
#define TIMER_2			0x42 /**< @brief Timer 2 count register */
#define TIMER_CTRL		0x43 /**< @brief Control register */

#define SPEAKER_CTRL		0x61 /**< @brief Register for speaker control  */

/* Timer control */

/* Timer selection: bits 7 and 6 */

#define TIMER_SEL0		0x00     /**< @brief Control Word for Timer 0 */
#define TIMER_SEL1		BIT(6)   /**< @brief Control Word for Timer 1 */
#define TIMER_SEL2		BIT(7)   /**< @brief Control Word for Timer 2 */
#define TIMER_RB_CMD		(BIT(7)|BIT(6))  /**< @brief Read Back Command */

/* Register selection: bits 5 and 4 */

#define TIMER_LSB		BIT(4)  /**< @brief Initialize Counter LSB only */
#define TIMER_MSB		BIT(5)  /**< @brief Initialize Counter MSB only */
#define TIMER_LSB_MSB		(TIMER_LSB | TIMER_MSB) /**< @brief Initialize LSB first and MSB afterwards */

/* Operating mode: bits 3, 2 and 1 */

#define TIMER_SQR_WAVE		(BIT(2)|BIT(1)) /**< @brief Mode 3: square wave generator */
#define TIMER_RATE_GEN		BIT(2)          /**< @brief Mode 2: rate generator */

/* Counting mode: bit 0 */

#define TIMER_BCD			0x01   /**< @brief Count in BCD */
#define TIMER_BIN			0x00   /**< @brief Count in binary */

/* READ-BACK COMMAND FORMAT */

#define TIMER_RB_COUNT_         BIT(5)
#define TIMER_RB_STATUS_        BIT(4)
#define TIMER_RB_SEL(n)         BIT((n)+1)

/* BITS */

#define BIT_7 					BIT(7)
#define BIT_6					BIT(6)
#define BIT_5 					BIT(5)
#define BIT_4 					BIT(4)
#define BIT_3 					BIT(3)
#define BIT_2 					BIT(2)
#define BIT_1 					BIT(1)
#define BIT_0 					BIT(0)

//=======================================================================================================
// KEYBOARD

#define KBD_IRQ			1
#define KBD_HOOK_BIT	1

#define STAT_REG		0x64
#define OUT_BUFF		0x60

#define TOGGLE_LEDS		0xED

#define BREAKCODE		0x80

#define ESC			0x81
#define KEY_A		0x1e
#define BREAK_A		0x9e
#define KEY_D		0x20
#define BREAK_D		0xa0
#define KEY_Q		0x10
#define KEY_W		0x11
#define KEY_E		0x12
#define KEY_SPACE	0x39
#define KEY_I		0x17
#define BREAK_I		0x97
#define KEY_J		0x24
#define	BREAK_J		0xa4
#define KEY_L		0x26
#define BREAK_L		0xa6


#define SCROLL_LOCK		BIT(0)
#define NUM_LOCK		BIT(1)
#define CAPS_LOCK		BIT(2)


//=======================================================================================================
// MOUSE

#define MOUSE_HOOK_BIT	2
#define MOUSE_IRQ	12

#define MOUSE_FIRST_BYTE	BIT(3)

#define WRITE_TO_MOUSE	0xD4
#define SET_STREAM_MODE	0xEA
#define DATA_STREAM_ON	0xF4
#define STATUS_REQUEST 0xE9

#define ACK  0xFA

#define OUT_BUFF	0x60
#define STAT_REG	0x64

#define IBF	BIT(1)
#define OBF BIT(0)

#define LB BIT(0)
#define RB BIT(1)
#define MB BIT(2)
#define XSIGN BIT(4)
#define YSIGN BIT(5)
#define XOV BIT(6)
#define YOV BIT(7)

#define REMOTE BIT(6)
#define ENABLE BIT(5)
#define SCALING BIT(4)
#define LEFT BIT(2)
#define MIDDLE BIT(1)
#define RIGHT BIT(0)

#define WAIT_KBC 2000


#endif
