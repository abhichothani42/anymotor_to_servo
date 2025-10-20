# anymotor to servo

This project demonstrates how to control any motors position using encoding and PID control. The implementation is step-by-step, with several test files included to ensure functionality along the way. The main code files for the project are attached in this repository.

## Demonstration Video

I have created a YouTube video demonstrating the DC motor control using PID. Watch the video for a detailed explanation and live demonstration of the project.

[Watch on YouTube](https://youtu.be/xedh0_JhtiM)

## Project Overview

The project is designed to control DC motor with precision using PID control. I am planing to add other types of motors in future! The key features include:

- **Position Encoding**: Tracking the position of the motors for accurate control.
- **PID Control**: Implementing PID algorithms to maintain desired motor positions.
- **Step-by-Step Testing**: Various test files are provided to verify each part of the implementation.

## Code Files

The following are the main code files included in this project:

1. **01_Encoder_testing.ino**: Test file for verifying the encoder functionality.
2. **02_dc_motor_with_encoder_test.ino**: Test file for basic DC motor with encoder operations.
3. **03_PID_control_for_DC_motor_using_encoder.ino**: Main implementation file for controlling DC motor using PID control.

## Hardware

1. DC Motor with a position encoder  
   ![image](https://a.pololu-files.com/picture/0J4045.1200.jpg?28764d04f44f69e259218bf608e862b4)

2. Motor Driver  
   ![image](https://cdn-shop.adafruit.com/970x728/3190-09.jpg)

3. Arduino Mega
   ![image](https://m.media-amazon.com/images/I/61sr9f-JppL._AC_UF894,1000_QL80_.jpg)

## Pin Connection

![image](https://github.com/abhichothani42/anymotor_to_servo/blob/main/wiring_diagram/circuit_diagram_bb.jpg)

## PID implementation

![image](https://github.com/abhichothani42/anymotor_to_servo/blob/main/assets/PID_control_details.png)

## Usage

1. Clone the repository to your local machine:
    ```sh
    git clone [https://github.com/abhichothani42/anymotor_to_servo.git]
    ```
2. Open the desired `.ino` file in the Arduino IDE.
3. Upload the code to your Arduino board.
4. Follow the instructions in each test file to verify functionality step by step.


## Contributions

Feel free to contribute to this project by opening issues or submitting pull requests. Any contributions, whether it be improvements, bug fixes, or new features, are welcome.

## License

will be updated

## Acknowledgements

- [Abhishek Chothani](https://github.com/abhismirai10)

## Contact

For any questions or suggestions, please open an issue on the GitHub repository or contact me at (email)(achothani42@gmail.com).

---

Thank you for checking out my project!
