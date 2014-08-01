/*
 * This file is part of the TREZOR project.
 *
 * Copyright (C) 2014 Pavol Rusnak <stick@satoshilabs.com>
 *
 * Licensed under Microsoft Reference Source License (Ms-RSL)
 */

#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/spi.h>
#include <libopencm3/stm32/f2/rng.h>

void setup(void)
{
	// setup clock
	clock_scale_t clock = hse_8mhz_3v3[CLOCK_3V3_120MHZ];
	rcc_clock_setup_hse_3v3(&clock);

	// enable GPIO clock - A (oled), B(oled), C (buttons)
	rcc_periph_clock_enable(RCC_GPIOA);
	rcc_periph_clock_enable(RCC_GPIOB);
	rcc_periph_clock_enable(RCC_GPIOC);

	// enable SPI clock
	rcc_periph_clock_enable(RCC_SPI1);

	// enable OTG FS clock
	rcc_periph_clock_enable(RCC_OTGFS);

	// enable RNG
	rcc_periph_clock_enable(RCC_RNG);
	RNG_CR |= RNG_CR_IE | RNG_CR_RNGEN;

	// set GPIO for buttons
	gpio_mode_setup(GPIOC, GPIO_MODE_INPUT, GPIO_PUPD_PULLUP, GPIO2 | GPIO5);

	// set GPIO for OLED display
	gpio_mode_setup(GPIOA, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO4);
	gpio_mode_setup(GPIOB, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO0 | GPIO1);

	// enable SPI 1 for OLED display
	gpio_mode_setup(GPIOA, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO5 | GPIO7);
	gpio_set_af(GPIOA, GPIO_AF5, GPIO5 | GPIO7);

//	spi_disable_crc(SPI1);
	spi_init_master(SPI1, SPI_CR1_BAUDRATE_FPCLK_DIV_64, SPI_CR1_CPOL_CLK_TO_0_WHEN_IDLE, SPI_CR1_CPHA_CLK_TRANSITION_1, SPI_CR1_DFF_8BIT, SPI_CR1_MSBFIRST);
	spi_enable_ss_output(SPI1);
//	spi_enable_software_slave_management(SPI1);
//	spi_set_nss_high(SPI1);
//	spi_clear_mode_fault(SPI1);
	spi_enable(SPI1);

	// enable OTG_FS
	gpio_mode_setup(GPIOA, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO11 | GPIO12);
	gpio_set_af(GPIOA, GPIO_AF10, GPIO11 | GPIO12);
}

void setupApp(void)
{
	// hotfix for old bootloader
	gpio_mode_setup(GPIOA, GPIO_MODE_INPUT, GPIO_PUPD_NONE, GPIO9);
}
