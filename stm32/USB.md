# USB

USB and be used to send information back and forth between a connected computer 
and the stm32 microcontroller. This is useful for debugging and for sending data.

The on-board USB you connect to must be connected to d+ and d- pins on the stm32. It cannot 
just be a power delivery USB port. The d+ and d- pins are connected to the PA11 and PA12 pins and used to
transmit data. 

## Setup 

### Extremely helpful video
https://www.youtube.com/watch?v=92A98iEFmaA&t=182s&ab_channel=ControllersTech

### Enabling USB on the IOC configuration

1. Open the .ioc file in the project explorer
2. Under **connectivity** enable **USB** by checking the box **Device (FS)**
3. Under **Middleware and Software Packs** enable **USB_DEVICE** by selecting the **Class for FS IP**
dropdown and selecting **Communication Device Class (Virtual Port Com)**

### Fixing the clock speed

USB requires a 48MHz clock speed. By default, the clock speed is set to 8MHz. To fix this,
we need to change the clock speed to 48MHz.

1. Enable your clock source. For example, I enabled the HSE clock source in **System Core | RCC**
2. Go to **Clock Configuration** and change the **PLL Source Mux** to the clock source you enabled.
3. Mess with the other settings until you get a 48MHz clock speed.

### Adding code

At the top of your `main.c`, you'll need to include the `usbd_cdc_if.h` header file. Along with 
some other header files for building and writing cstrings. 

```c
/* USER CODE BEGIN Includes */

#include "stdio.h"
#include "usbd_cdc_if.h" 
#include "string.h"

/* USER CODE END Includes */
```

#### Sending data

Sending data is as simple as calling the `CDC_Transmit_FS` function. This function takes in a pointer to a
cstring and the length of the cstring. 

```c
char *message = "Hello World!\n";
CDC_Transmit_FS((uint8_t *)message, strlen(message));
```

It has to be cast to a `uint8_t` pointer.

If you open a serial viewer like putty, you should see the message printed to the console. If you
listen to the correct COM port. 


#### Receiving data

Not yet explored fully.
The video above does a good job of explaining how to receive data.