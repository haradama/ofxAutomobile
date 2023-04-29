import argparse
import random
from serial import Serial, SerialException


def parse_arguments():
    parser = argparse.ArgumentParser(description="OBD2 Simulator")
    parser.add_argument(
        "-p", "--port", required=True, help="Serial port for the OBD2 simulator"
    )
    parser.add_argument(
        "-b",
        "--baudrate",
        type=int,
        default=115200,
        help="Baud rate for the OBD2 simulator (default: 115200)",
    )
    return parser.parse_args()


class OBD2Simulator:
    def __init__(self, port, baud_rate):
        try:
            self.serial = Serial(port, baud_rate, timeout=0.1)
        except SerialException as e:
            print(f"Error opening serial port: {e}")
            raise

    def run(self):
        while True:
            if self.serial.in_waiting > 0:
                command = self.serial.readline().decode().strip()
                response = self.handle_command(command)
                if response:
                    self.serial.write((response + '\r\n').encode())

    def handle_command(self, command):
        if command == "ATZ":  # Reset command
            return "ELM327 v1.5"
        elif command == "0105":  # Engine Coolant Temperature
            temp = random.randint(80, 120)
            return f"41 05 {temp:02X}"
        elif command == "010C":  # Engine RPM
            rpm = random.randint(800, 4000)
            return f"41 0C {rpm:04X}"
        elif command == "010D":  # Vehicle Speed
            speed = random.randint(0, 120)
            return f"41 0D {speed:02X}"
        elif command == "0111":  # Throttle Position
            throttle = random.randint(15, 80)
            return f"41 11 {throttle:02X}"
        else:
            return None


if __name__ == "__main__":
    args = parse_arguments()
    try:
        simulator = OBD2Simulator(args.port, args.baudrate)
        simulator.run()
    except KeyboardInterrupt:
        print("Exiting...")
