#define NUM_FILTER = 40

uint16_t temp_scaler = 100;
int temp_offset = 1;


//_________________________________________________________________ no change below this line nessasary

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

bool Relais1 = false;
bool Relais2 = false;
bool Relais3 = false;
bool Relais4 = false;
bool Relais5 = false;
bool Relais6 = false;
bool Relais7 = false;
bool Relais8 = false;

String Courser_pos = "menu";

float NTC = 0;
float temp = 0;
float NTC_lowpass[NUM_FILTER];

uint8_t i = 1;

bool Taster1 = false;
bool Taster2 = false;
bool Taster3 = false;
bool Taster4 = false;
bool Taster_enco = false;
