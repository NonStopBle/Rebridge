# Rebridge: Communication Protocol Adapter for Old PLCs

## Overview

Rebridge simplifies communication with old programmable logic controllers (PLCs) that require expensive communication cards. Using a 3-wire connection, Rebridge establishes a link between the microcontroller and the PLC. The 3 wires are designated for Clock, Data, and Enable functionalities.

## Features

- **Cost-Effective Communication:** Replace expensive communication cards with Rebridge for a budget-friendly solution.

- **3-Wire Connection:** Connect Clock, Data, and Enable wires for streamlined integration.
  
  - **Clock Wire:** Used for synchronization in data transmission.
  
  - **Data Wire:** Transmits data from the PLC to the microcontroller using a MOV command to convert decimal to binary.
  
  - **Enable Wire:** Controls the transmission, enabling and disabling the communication for precise control.

- **Compatibility:** Rebridge works with various old PLC models, making it versatile for legacy systems.

## Usage

1. Connect Clock, Data, and Enable wires from the microcontroller to the corresponding pins on the PLC.
   
2. Implement Rebridge protocol in your microcontroller firmware.

```c
#include <Rebridge.h>

void setup() {
  Rebridge.begin();
}

void loop() {
  // Your main loop code here
}
