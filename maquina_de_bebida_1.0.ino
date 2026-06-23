#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

LiquidCrystal_I2C LCD(0x27,16,2);
Servo servo_door;

// =========================
// Input Devices
// =========================
const byte TEMPERATURE_SENSOR = A2;
const byte CUP_SENSOR = 4;

// =========================
// Beverage Valves
// =========================
const byte COFFEE_VALVE = 5;
const byte MILK_VALVE = 6;
const byte CHOCOLATE_VALVE = 7;

// =========================
// User Buttons
// =========================
const byte BTN_COFFEE = 8;
const byte BTN_COFFEE_MILK = 9;
const byte BTN_CHOCOLATE = 10;
const byte BTN_CAPPUCCINO = 11;

// =========================
// Variables
// =========================
String comando;
int temperatura = 0;
bool pronto = false;
float sensor_ad = 0.0;

/**

Opens the cup access door.
*/
void openDoor()
{
servo_door.write(0);
}

/**

Closes the cup access door.
*/
void closeDoor()
{
servo_door.write(180);
}

void brewCoffee()
{
    // =========================
    // Display: Selecting drink
    // =========================
    LCD.setCursor(0,0);
    LCD.print(" BEBIDA:       ");
    LCD.setCursor(0,1);
    LCD.print("           CAFE");

    // Open cup access door
    openDoor();
    delay(3000);

    // Ask user to insert cup
    LCD.setCursor(0,0);
    LCD.print(" COLOQUE O COPO");
    LCD.setCursor(0,1);
    LCD.print("                ");

    // Wait until cup is placed
    while (digitalRead(CUP_SENSOR) == HIGH);

    delay(3000);

    // Close door before dispensing
    closeDoor();
    delay(1000);

    // =========================
    // Brewing process
    // =========================
    LCD.setCursor(0,0);
    LCD.print(" BEBIDA:       ");
    LCD.setCursor(0,1);
    LCD.print("  EM PREPARACAO");

    digitalWrite(COFFEE_VALVE, HIGH); // open coffee valve
    delay(5000);
    digitalWrite(COFFEE_VALVE, LOW);  // close coffee valve

    delay(1000);

    // =========================
    // Finish
    // =========================
    LCD.setCursor(0,0);
    LCD.print(" BEBIDA:       ");
    LCD.setCursor(0,1);
    LCD.print("         PRONTA");

    delay(2000);

    // Open door for removal
    openDoor();

    LCD.setCursor(0,0);
    LCD.print(" RETIRE O COPO ");
    LCD.setCursor(0,1);
    LCD.print("                ");

    // Wait until cup is removed
    while (digitalRead(CUP_SENSOR) == LOW);

    delay(3000);

    // Close system again
    closeDoor();
}

void brewCoffeeWithMilk()
{
    // =========================
    // Display: Selecting drink
    // =========================
    LCD.setCursor(0,0);
    LCD.print(" BEBIDA:       ");
    LCD.setCursor(0,1);
    LCD.print("        CAFE COM LEITE");

    // Open cup access door
    openDoor();
    delay(3000);

    // Ask user to insert cup
    LCD.setCursor(0,0);
    LCD.print(" COLOQUE O COPO");
    LCD.setCursor(0,1);
    LCD.print("                ");

    // Wait until cup is placed
    while (digitalRead(CUP_SENSOR) == HIGH);

    delay(3000);

    // Close door before dispensing
    closeDoor();
    delay(1000);

    // =========================
    // Brewing process
    // =========================
    LCD.setCursor(0,0);
    LCD.print(" BEBIDA:       ");
    LCD.setCursor(0,1);
    LCD.print("  EM PREPARACAO");

    digitalWrite(COFFEE_VALVE, HIGH); // open coffee valve
    delay(5000);
    digitalWrite(COFFEE_VALVE, LOW);  // close coffee valve
    digitalWrite(MILK_VALVE, HIGH);  // open milk valve
    delay(5000);
    digitalWrite(MILK_VALVE, LOW);  // close milk valve
    delay(1000);

    // =========================
    // Finish
    // =========================
    LCD.setCursor(0,0);
    LCD.print(" BEBIDA:       ");
    LCD.setCursor(0,1);
    LCD.print("         PRONTA");

    delay(2000);

    // Open door for removal
    openDoor();

    LCD.setCursor(0,0);
    LCD.print(" RETIRE O COPO ");
    LCD.setCursor(0,1);
    LCD.print("                ");

    // Wait until cup is removed
    while (digitalRead(CUP_SENSOR) == LOW);

    delay(3000);

    // Close system again
    closeDoor();
}

void brewCapuccino()
{
    // =========================
    // Display: Selecting drink
    // =========================
    LCD.setCursor(0,0);
    LCD.print(" BEBIDA:       ");
    LCD.setCursor(0,1);
    LCD.print("        CAPUCCINO");

    // Open cup access door
    openDoor();
    delay(3000);

    // Ask user to insert cup
    LCD.setCursor(0,0);
    LCD.print(" COLOQUE O COPO");
    LCD.setCursor(0,1);
    LCD.print("                ");

    // Wait until cup is placed
    while (digitalRead(CUP_SENSOR) == HIGH);

    delay(3000);

    // Close door before dispensing
    closeDoor();
    delay(1000);

    // =========================
    // Brewing process
    // =========================
    LCD.setCursor(0,0);
    LCD.print(" BEBIDA:       ");
    LCD.setCursor(0,1);
    LCD.print("  EM PREPARACAO");

    digitalWrite(COFFEE_VALVE, HIGH); // open coffee valve
    delay(5000);
    digitalWrite(COFFEE_VALVE, LOW);  // close coffee valve
    digitalWrite(MILK_VALVE, HIGH);  // open milk valve
    delay(5000);
    digitalWrite(MILK_VALVE, LOW);  // close milk valve
    digitalWrite(CHOCOLATE_VALVE, HIGH);  // open chocolate valve
    delay(5000);
    digitalWrite(CHOCOLATE_VALVE, LOW);  // close chocolate valve
    delay(1000);

    // =========================
    // Finish
    // =========================
    LCD.setCursor(0,0);
    LCD.print(" BEBIDA:       ");
    LCD.setCursor(0,1);
    LCD.print("         PRONTA");

    delay(2000);

    // Open door for removal
    openDoor();

    LCD.setCursor(0,0);
    LCD.print(" RETIRE O COPO ");
    LCD.setCursor(0,1);
    LCD.print("                ");

    // Wait until cup is removed
    while (digitalRead(CUP_SENSOR) == LOW);

    delay(3000);

    // Close system again
    closeDoor();
}

void brewChocolate()
{
    // =========================
    // Display: Selecting drink
    // =========================
    LCD.setCursor(0,0);
    LCD.print(" BEBIDA:       ");
    LCD.setCursor(0,1);
    LCD.print("        CHOCOLATE");

    // Open cup access door
    openDoor();
    delay(3000);

    // Ask user to insert cup
    LCD.setCursor(0,0);
    LCD.print(" COLOQUE O COPO");
    LCD.setCursor(0,1);
    LCD.print("                ");

    // Wait until cup is placed
    while (digitalRead(CUP_SENSOR) == HIGH);

    delay(3000);

    // Close door before dispensing
    closeDoor();
    delay(1000);

    // =========================
    // Brewing process
    // =========================
    LCD.setCursor(0,0);
    LCD.print(" BEBIDA:       ");
    LCD.setCursor(0,1);
    LCD.print("  EM PREPARACAO");

    digitalWrite(MILK_VALVE, HIGH);  // open milk valve
    delay(5000);
    digitalWrite(MILK_VALVE, LOW);  // close milk valve
    digitalWrite(CHOCOLATE_VALVE, HIGH);  // open chocolate valve
    delay(5000);
    digitalWrite(CHOCOLATE_VALVE, LOW);  // close chocolate valve
    delay(1000);

    // =========================
    // Finish
    // =========================
    LCD.setCursor(0,0);
    LCD.print(" BEBIDA:       ");
    LCD.setCursor(0,1);
    LCD.print("         PRONTA");

    delay(2000);

    // Open door for removal
    openDoor();

    LCD.setCursor(0,0);
    LCD.print(" RETIRE O COPO ");
    LCD.setCursor(0,1);
    LCD.print("                ");

    // Wait until cup is removed
    while (digitalRead(CUP_SENSOR) == LOW);

    delay(3000);

    // Close system again
    closeDoor();
}

// =========================
// SETUP
// =========================
void setup()
{
    // =========================
    // PIN CONFIGURATION
    // =========================
    pinMode(TEMPERATURE_SENSOR, INPUT);
    pinMode(CUP_SENSOR, INPUT_PULLUP);

    pinMode(COFFEE_VALVE, OUTPUT);
    pinMode(MILK_VALVE, OUTPUT);
    pinMode(CHOCOLATE_VALVE, OUTPUT);

    pinMode(BTN_COFFEE, INPUT);
    pinMode(BTN_COFFEE_MILK, INPUT);
    pinMode(BTN_CHOCOLATE, INPUT);
    pinMode(BTN_CAPPUCCINO, INPUT);

    // =========================
    // DISPLAY
    // =========================
    LCD.init();
    LCD.backlight();

    // =========================
    // SERVO DOOR
    // =========================
    servo_door.attach(3, 1000, 2000);
    closeDoor();

    // =========================
    // SERIAL
    // =========================
    Serial.begin(9600);
    Serial.setTimeout(10);

    // =========================
    // INITIAL STATE
    // =========================
    pronto = false;
}

// =========================
// LOOP
// =========================
void loop()
{
    // =========================
    // READ TEMPERATURE
    // =========================
    sensor_ad = analogRead(TEMPERATURE_SENSOR);
    temperatura = (sensor_ad * 500) / 1023;

    // =========================
    // HEATING STATE (non-blocking)
    // =========================
    if (temperatura <= 100)
    {
        LCD.setCursor(0, 0);
        LCD.print("Aquecendo      ");

        LCD.setCursor(0, 1);
        LCD.print("Temp: ");
        LCD.print(temperatura);
        LCD.print((char)223);
        LCD.print("C   ");

        delay(400);
        return;
    }

    // =========================
    // MACHINE READY MESSAGE (once)
    // =========================
    if (pronto == false)
    {
        LCD.clear();
        LCD.setCursor(0, 0);
        LCD.print("Maquina Pronta");
        delay(2000);

        pronto = true;
        LCD.clear();
    }

    // =========================
    // MENU
    // =========================
    LCD.setCursor(0, 0);
    LCD.print(" Escolha       ");
    LCD.setCursor(0, 1);
    LCD.print(" Uma Opcao:    ");

    // =========================
    // BUTTON INPUTS
    // =========================
    if (digitalRead(BTN_COFFEE))
        brewCoffee();

    if (digitalRead(BTN_COFFEE_MILK))
        brewCoffeeWithMilk();

    if (digitalRead(BTN_CAPPUCCINO))
        brewCapuccino();

    if (digitalRead(BTN_CHOCOLATE))
        brewChocolate();

    // =========================
    // SERIAL INPUT
    // =========================
    if (Serial.available() > 0)
    {
        comando = Serial.readString();
        comando.trim();

        if (comando == "C")
            brewCoffee();

        if (comando == "L")
            brewCoffeeWithMilk();

        if (comando == "H")
            brewChocolate();

        if (comando == "P")
            brewCapuccino();
    }
}
