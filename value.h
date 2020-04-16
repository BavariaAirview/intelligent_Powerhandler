#define NUM_FILTER 40
#define NUM_LEDS 4

#define debug 1

uint16_t temp_scaler = 100;
int temp_offset = 1;
float soll_temp = 18.5;
uint8_t delay_printer = 10;    // Minuten
uint8_t delay_PC = 1;          // Minuten


//_________________________________________________________________ no change below this line nessasary

#define COLOR_ORDER RGB
#define CHIPSET     WS2811
#define BRIGHTNESS  200
#define FRAMES_PER_SECOND 10

#define Relais1_pin 2
#define Relais2_pin 3
#define Relais3_pin 4
#define Relais4_pin 5
#define Relais5_pin 6
#define Relais6_pin 7
#define Relais7_pin 8
#define Relais8_pin 9

#define LED_PIN 10
#define NTC_pin A0
#define Printer_Bed_pin A7
#define Taster1_pin A6
#define Taster2_pin A3
#define Taster3_pin A2
#define Taster4_pin A1
#define Taster_enco_pin 13
#define encoder0PinA 11
#define encoder0PinB 12

uint8_t LED1_r = 0;
uint8_t LED2_r = 0;
uint8_t LED3_r = 0;
uint8_t LED4_r = 0;
uint8_t LED1_g = 0;
uint8_t LED2_g = 0;
uint8_t LED3_g = 0;
uint8_t LED4_g = 0;
uint8_t LED1_b = 0;
uint8_t LED2_b = 0;
uint8_t LED3_b = 0;
uint8_t LED4_b = 0;

int encoderPinALast = LOW;
int rotation = LOW;
volatile unsigned int encoderPos = 0;

bool Relais1 = false;   // Netzteil
bool Relais2 = false;   // Heizung
bool Relais3 = false;   //  = Relais2
bool Relais4 = false;   // 3D Drucker
bool Relais5 = false;   // Licht
bool Relais6 = false;   // Tools
bool Relais7 = false;   // PC
bool Relais8 = false;   // Netzwerk

uint8_t courser_pos = 1;         // 1 = Hauptmenüpunkt, 2 = Value1, 3 = Value2
uint8_t nMainMenu = 0;
uint8_t nMainMenu_alt = 0;
uint8_t nValue1 = 0;
uint8_t nValue2 = 0;
float numValue2 = 0;
char MainMenu = "";
char Value1 = "";
char Value2 = "";
int waittime = 0;

float NTC = 0;
float temp = 0;
float NTC_lowpass[NUM_FILTER];

uint8_t i = 1;

bool drucker = false;
bool licht = true;
bool tools = false;
bool PC = false;
bool Heizung = true;

bool Taster1 = false;         // 3D Drucker
bool Taster2 = false;         // Licht
bool Taster3 = false;         // Tools
bool Taster4 = false;         // PC
bool Taster_enco = false;
bool Printer_done = false;

bool Taster1_alt = false;
bool Taster2_alt = false;
bool Taster3_alt = false;
bool Taster4_alt = false;
bool Taster_enco_alt = false;
bool Printer_done_alt = false;

const char *M_Menu[] = {"3Dprint", "Licht", "Tools", "PC", "Heater", "Info"};
const char *v1_Menu[] = {"ON", "OFF"};
const char *v2_Menu[] = {"temp", "delay"};
