# Photoresistive night light
Our project is a photoresistive light sensor circuit that powers multiple LEDs when in darkness. Two voltages are compared using a TI LM311p differential comparator with one voltage being applied through a voltage divider that inclues a photoresistor and the other directly to the input pin. As light fades, the photoresistor's resistance increases and causes a voltage difference to occur on the comparator's inputs. Once this occurs, an output voltage is input into the TI MSP432 MCU which then turns multiple LEDs on until enough light hits the photoresistor to switch off the comparator's output. This switch off is also read by the MSP432 and the LEDs are turned off.

# How to use the codebase
The codebase includes a main file which:
* initializes the GPIO inputs & outputs
* Initializes the timer
* Enables timer interrupts and the NVIC

Once initialization is complete, an inifite while loop checks for scheduled events.

The code base is written as an interrupt driven event scheduler. Whenever the timer overflows, the interrupt handler will check for a signal on one of the GPIO pins and schedule an event based on whether that signal is low or high:
* A low signal will schedule a call to turn off the onboard LEDs and drive an output pins low. 
* A high signal will schedule a call to turn on the onboard LEDs and drive and drive the output pins high.

# Incremental build
To design our PCB we first built our circuit using a breadboard. We used an oscilloscope to debug our circuit in order to ensure the TI LM311p differential comparator was working as intended. We utilized the MSP432P4111's external header pins to interface with our PCB. We then finalized our design using Altium PCB design software. For the codebase, we repurposed the timer code from our Ultrasonic sensor lab assignment and utilized Code Composer Studio's built-in debugger to ensure the code operated as expected. Once we confirmed the timer and interrupts were working, we decided to make the code a tab more interesting by implementing a crude software delay and XOR'd our external GPIO pins in order to achieve a more interesting "light-show".