# Rebridge: Communication Protocol Adapter for Old PLCs

## Overview

Rebridge simplifies communication with old programmable logic controllers (PLCs) that require expensive communication cards. Using a 6-pin connection, Rebridge establishes a link between the microcontroller and the PLC with 3 wires from Slot 1 to the microcontroller and 3 wires from the microcontroller to Slot 2.

## Features

- **Cost-Effective Communication:** Replace expensive communication cards with Rebridge for a budget-friendly solution.

- **6-Pin Connection:** Connect 3 wires from Slot 1 to the microcontroller and 3 wires from the microcontroller to Slot 2 for straightforward integration.

- **Compatibility:** Rebridge works with various old PLC models, making it versatile for legacy systems.

## Usage

1. Connect 3 wires from Slot 1 on the PLC to the microcontroller.
2. Connect 3 wires from the microcontroller to Slot 2 on the PLC.
3. Implement Rebridge protocol in your microcontroller firmware.

```c
#include <Rebridge.h>

void setup() {
  Rebridge.begin();
}

void loop() {
  // Your main loop code here
}
