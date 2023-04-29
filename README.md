# ofxAutomobile

ofxAutomobile is an openFrameworks add-on for communicating with vehicles using the OBD2 (On-Board Diagnostics) protocol. It provides a simple interface for connecting to OBD2 adapters (such as ELM327) over a serial connection and sending OBD2 commands to query various vehicle parameters, such as engine speed, coolant temperature, and throttle position.


## Usage

| Method                                                             | Description                                                                                                                          |
| ------------------------------------------------------------------ | ------------------------------------------------------------------------------------------------------------------------------------ |
| `bool setup(const std::string& port_name, int baud_rate = 115200)` | Initializes the OBD2 connection with the specified serial port and optional baud rate. Returns `true` on success, `false` otherwise. |
| `bool query(const std::string& command, std::string& response)`    | Sends an OBD2 command and reads the response. Returns `true` on success, `false` otherwise.                                          |


## Simulate your application

`tools/obd2_simulator.py` simulates an OBD2 adapter using the ELM327 command set. It listens for OBD2 commands on a specified serial port and sends random responses for a few common OBD2 PIDs.

### Requirements

- Python 3.6 or higher
- pyserial

### Installation

1. Install the required `pyserial` library:

```sh
$ pip install pyserial
```

### Usage

Run the OBD2 simulator by specifying the port and baud rate as command-line arguments:

```sh
$ python tools/obd2_simulator.py --port /dev/ttyVUSB2 --baudrate 115200
```


Replace `/dev/ttyVUSB2` with the desired virtual serial port and `115200` with the desired baud rate.

### Command-line Arguments

- `-p, --port`: Required. Serial port for the OBD2 simulator.
- `-b, --baudrate`: Optional. Baud rate for the OBD2 simulator (default: 115200).

### Supported OBD2 Commands

The simulator currently supports the following OBD2 commands:

- `ATZ`: Reset command
- `0105`: Engine Coolant Temperature
- `010C`: Engine RPM
- `010D`: Vehicle Speed
- `0111`: Throttle Position

You can expand the `handle_command` method in the `obd2_simulator.py` script to support more OBD2 commands as needed.