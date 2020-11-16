// pohrana podataka u FLASH memoriji

const uint8_t FontA[256][8] PROGMEM = {
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
{0x7E,0x81,0xA5,0x81,0xBD,0x99,0x81,0x7E},
{0x7E,0xFF,0xDB,0xFF,0xC3,0xE7,0xFF,0x7E},
{0x6C,0xFE,0xFE,0xFE,0x7C,0x38,0x10,0x00},
{0x10,0x38,0x7C,0xFE,0x7C,0x38,0x10,0x00},
{0x38,0x7C,0x38,0xFE,0xFE,0x7C,0x38,0x7C},
{0x10,0x10,0x38,0x7C,0xFE,0x7C,0x38,0x7C},
{0x00,0x00,0x18,0x3C,0x3C,0x18,0x00,0x00},
{0xFF,0xFF,0xE7,0xC3,0xC3,0xE7,0xFF,0xFF},
{0x00,0x3C,0x66,0x42,0x42,0x66,0x3C,0x00},
{0xFF,0xC3,0x99,0xBD,0xBD,0x99,0xC3,0xFF},
{0x0F,0x07,0x0F,0x7D,0xCC,0xCC,0xCC,0x78},
{0x3C,0x66,0x66,0x66,0x3C,0x18,0x7E,0x18},
{0x3F,0x33,0x3F,0x30,0x30,0x70,0xF0,0xE0},
{0x7F,0x63,0x7F,0x63,0x63,0x67,0xE6,0xC0},
{0x99,0x5A,0x3C,0xE7,0xE7,0x3C,0x5A,0x99},
{0x80,0xE0,0xF8,0xFE,0xF8,0xE0,0x80,0x00},
{0x02,0x0E,0x3E,0xFE,0x3E,0x0E,0x02,0x00},
{0x18,0x3C,0x7E,0x18,0x18,0x7E,0x3C,0x18},
{0x66,0x66,0x66,0x66,0x66,0x00,0x66,0x00},
{0x7F,0xDB,0xDB,0x7B,0x1B,0x1B,0x1B,0x00},
{0x3E,0x63,0x38,0x6C,0x6C,0x38,0xCC,0x78},
{0x00,0x00,0x00,0x00,0x7E,0x7E,0x7E,0x00},
{0x18,0x3C,0x7E,0x18,0x7E,0x3C,0x18,0xFF},
{0x18,0x3C,0x7E,0x18,0x18,0x18,0x18,0x00},
{0x18,0x18,0x18,0x18,0x7E,0x3C,0x18,0x00},
{0x00,0x18,0x0C,0xFE,0x0C,0x18,0x00,0x00},
{0x00,0x30,0x60,0xFE,0x60,0x30,0x00,0x00},
{0x00,0x00,0xC0,0xC0,0xC0,0xFE,0x00,0x00},
{0x00,0x24,0x66,0xFF,0x66,0x24,0x00,0x00},
{0x00,0x18,0x3C,0x7E,0xFF,0xFF,0x00,0x00},
{0x00,0xFF,0xFF,0x7E,0x3C,0x18,0x00,0x00},
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
{0x30,0x78,0x78,0x30,0x30,0x00,0x30,0x00},
{0x6C,0x6C,0x6C,0x00,0x00,0x00,0x00,0x00},
{0x6C,0x6C,0xFE,0x6C,0xFE,0x6C,0x6C,0x00},
{0x30,0x7C,0xC0,0x78,0x0C,0xF8,0x30,0x00},
{0x00,0xC6,0xCC,0x18,0x30,0x66,0xC6,0x00},
{0x38,0x6C,0x38,0x76,0xDC,0xCC,0x76,0x00},
{0x60,0x60,0xC0,0x00,0x00,0x00,0x00,0x00},
{0x18,0x30,0x60,0x60,0x60,0x30,0x18,0x00},
{0x60,0x30,0x18,0x18,0x18,0x30,0x60,0x00},
{0x00,0x66,0x3C,0xFF,0x3C,0x66,0x00,0x00},
{0x00,0x30,0x30,0xFC,0x30,0x30,0x00,0x00},
{0x00,0x00,0x00,0x00,0x00,0x30,0x30,0x60},
{0x00,0x00,0x00,0xFC,0x00,0x00,0x00,0x00},
{0x00,0x00,0x00,0x00,0x00,0x30,0x30,0x00},
{0x06,0x0C,0x18,0x30,0x60,0xC0,0x80,0x00},
{0x7C,0xC6,0xCE,0xDE,0xF6,0xE6,0x7C,0x00},
{0x30,0x70,0x30,0x30,0x30,0x30,0xFC,0x00},
{0x78,0xCC,0x0C,0x38,0x60,0xCC,0xFC,0x00},
{0x78,0xCC,0x0C,0x38,0x0C,0xCC,0x78,0x00},
{0x1C,0x3C,0x6C,0xCC,0xFE,0x0C,0x1E,0x00},
{0xFC,0xC0,0xF8,0x0C,0x0C,0xCC,0x78,0x00},
{0x38,0x60,0xC0,0xF8,0xCC,0xCC,0x78,0x00},
{0xFC,0xCC,0x0C,0x18,0x30,0x30,0x30,0x00},
{0x78,0xCC,0xCC,0x78,0xCC,0xCC,0x78,0x00},
{0x78,0xCC,0xCC,0x7C,0x0C,0x18,0x70,0x00},
{0x00,0x30,0x30,0x00,0x00,0x30,0x30,0x00},
{0x00,0x30,0x30,0x00,0x00,0x30,0x30,0x60},
{0x18,0x30,0x60,0xC0,0x60,0x30,0x18,0x00},
{0x00,0x00,0xFC,0x00,0x00,0xFC,0x00,0x00},
{0x60,0x30,0x18,0x0C,0x18,0x30,0x60,0x00},
{0x78,0xCC,0x0C,0x18,0x30,0x00,0x30,0x00},
{0x7C,0xC6,0xDE,0xDE,0xDE,0xC0,0x78,0x00},
{0x30,0x78,0xCC,0xCC,0xFC,0xCC,0xCC,0x00},
{0xFC,0x66,0x66,0x7C,0x66,0x66,0xFC,0x00},
{0x3C,0x66,0xC0,0xC0,0xC0,0x66,0x3C,0x00},
{0xF8,0x6C,0x66,0x66,0x66,0x6C,0xF8,0x00},
{0xFE,0x62,0x68,0x78,0x68,0x62,0xFE,0x00},
{0xFE,0x62,0x68,0x78,0x68,0x60,0xF0,0x00},
{0x3C,0x66,0xC0,0xC0,0xCE,0x66,0x3E,0x00},
{0xCC,0xCC,0xCC,0xFC,0xCC,0xCC,0xCC,0x00},
{0x78,0x30,0x30,0x30,0x30,0x30,0x78,0x00},
{0x1E,0x0C,0x0C,0x0C,0xCC,0xCC,0x78,0x00},
{0xE6,0x66,0x6C,0x78,0x6C,0x66,0xE6,0x00},
{0xF0,0x60,0x60,0x60,0x62,0x66,0xFE,0x00},
{0xC6,0xEE,0xFE,0xFE,0xD6,0xC6,0xC6,0x00},
{0xC6,0xE6,0xF6,0xDE,0xCE,0xC6,0xC6,0x00},
{0x38,0x6C,0xC6,0xC6,0xC6,0x6C,0x38,0x00},
{0xFC,0x66,0x66,0x7C,0x60,0x60,0xF0,0x00},
{0x78,0xCC,0xCC,0xCC,0xDC,0x78,0x1C,0x00},
{0xFC,0x66,0x66,0x7C,0x6C,0x66,0xE6,0x00},
{0x78,0xCC,0xE0,0x70,0x1C,0xCC,0x78,0x00},
{0xFC,0xB4,0x30,0x30,0x30,0x30,0x78,0x00},
{0xCC,0xCC,0xCC,0xCC,0xCC,0xCC,0xFC,0x00},
{0xCC,0xCC,0xCC,0xCC,0xCC,0x78,0x30,0x00},
{0xC6,0xC6,0xC6,0xD6,0xFE,0xEE,0xC6,0x00},
{0xC6,0xC6,0x6C,0x38,0x38,0x6C,0xC6,0x00},
{0xCC,0xCC,0xCC,0x78,0x30,0x30,0x78,0x00},
{0xFE,0xC6,0x8C,0x18,0x32,0x66,0xFE,0x00},
{0x78,0x60,0x60,0x60,0x60,0x60,0x78,0x00},
{0xC0,0x60,0x30,0x18,0x0C,0x06,0x02,0x00},
{0x78,0x18,0x18,0x18,0x18,0x18,0x78,0x00},
{0x10,0x38,0x6C,0xC6,0x00,0x00,0x00,0x00},
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF},
{0x30,0x30,0x18,0x00,0x00,0x00,0x00,0x00},
{0x00,0x00,0x78,0x0C,0x7C,0xCC,0x76,0x00},
{0xE0,0x60,0x60,0x7C,0x66,0x66,0xDC,0x00},
{0x00,0x00,0x78,0xCC,0xC0,0xCC,0x78,0x00},
{0x1C,0x0C,0x0C,0x7C,0xCC,0xCC,0x76,0x00},
{0x00,0x00,0x78,0xCC,0xFC,0xC0,0x78,0x00},
{0x38,0x6C,0x60,0xF0,0x60,0x60,0xF0,0x00},
{0x00,0x00,0x76,0xCC,0xCC,0x7C,0x0C,0xF8},
{0xE0,0x60,0x6C,0x76,0x66,0x66,0xE6,0x00},
{0x30,0x00,0x70,0x30,0x30,0x30,0x78,0x00},
{0x0C,0x00,0x0C,0x0C,0x0C,0xCC,0xCC,0x78},
{0xE0,0x60,0x66,0x6C,0x78,0x6C,0xE6,0x00},
{0x70,0x30,0x30,0x30,0x30,0x30,0x78,0x00},
{0x00,0x00,0xCC,0xFE,0xFE,0xD6,0xC6,0x00},
{0x00,0x00,0xF8,0xCC,0xCC,0xCC,0xCC,0x00},
{0x00,0x00,0x78,0xCC,0xCC,0xCC,0x78,0x00},
{0x00,0x00,0xDC,0x66,0x66,0x7C,0x60,0xF0},
{0x00,0x00,0x76,0xCC,0xCC,0x7C,0x0C,0x1E},
{0x00,0x00,0xDC,0x76,0x66,0x60,0xF0,0x00},
{0x00,0x00,0x7C,0xC0,0x78,0x0C,0xF8,0x00},
{0x10,0x30,0x7C,0x30,0x30,0x34,0x18,0x00},
{0x00,0x00,0xCC,0xCC,0xCC,0xCC,0x76,0x00},
{0x00,0x00,0xCC,0xCC,0xCC,0x78,0x30,0x00},
{0x00,0x00,0xC6,0xD6,0xFE,0xFE,0x6C,0x00},
{0x00,0x00,0xC6,0x6C,0x38,0x6C,0xC6,0x00},
{0x00,0x00,0xCC,0xCC,0xCC,0x7C,0x0C,0xF8},
{0x00,0x00,0xFC,0x98,0x30,0x64,0xFC,0x00},
{0x1C,0x30,0x30,0xE0,0x30,0x30,0x1C,0x00},
{0x18,0x18,0x18,0x00,0x18,0x18,0x18,0x00},
{0xE0,0x30,0x30,0x1C,0x30,0x30,0xE0,0x00},
{0x76,0xDC,0x00,0x00,0x00,0x00,0x00,0x00},
{0x00,0x10,0x38,0x6C,0xC6,0xC6,0xFE,0x00},
{0x78,0xCC,0xC0,0xCC,0x78,0x18,0x0C,0x78},
{0x00,0xCC,0x00,0xCC,0xCC,0xCC,0x7E,0x00},
{0x1C,0x00,0x78,0xCC,0xFC,0xC0,0x78,0x00},
{0x7E,0xC3,0x3C,0x06,0x3E,0x66,0x3F,0x00},
{0xCC,0x00,0x78,0x0C,0x7C,0xCC,0x7E,0x00},
{0xE0,0x00,0x78,0x0C,0x7C,0xCC,0x7E,0x00},
{0x30,0x30,0x78,0x0C,0x7C,0xCC,0x7E,0x00},
{0x00,0x00,0x78,0xC0,0xC0,0x78,0x0C,0x38},
{0x7E,0xC3,0x3C,0x66,0x7E,0x60,0x3C,0x00},
{0xCC,0x00,0x78,0xCC,0xFC,0xC0,0x78,0x00},
{0xE0,0x00,0x78,0xCC,0xFC,0xC0,0x78,0x00},
{0xCC,0x00,0x70,0x30,0x30,0x30,0x78,0x00},
{0x7C,0xC6,0x38,0x18,0x18,0x18,0x3C,0x00},
{0xE0,0x00,0x70,0x30,0x30,0x30,0x78,0x00},
{0xC6,0x38,0x6C,0xC6,0xFE,0xC6,0xC6,0x00},
{0x30,0x30,0x00,0x78,0xCC,0xFC,0xCC,0x00},
{0x1C,0x00,0xFC,0x60,0x78,0x60,0xFC,0x00},
{0x00,0x00,0x7F,0x0C,0x7F,0xCC,0x7F,0x00},
{0x3E,0x6C,0xCC,0xFE,0xCC,0xCC,0xCE,0x00},
{0x78,0xCC,0x00,0x78,0xCC,0xCC,0x78,0x00},
{0x00,0xCC,0x00,0x78,0xCC,0xCC,0x78,0x00},
{0x00,0xE0,0x00,0x78,0xCC,0xCC,0x78,0x00},
{0x78,0xCC,0x00,0xCC,0xCC,0xCC,0x7E,0x00},
{0x00,0xE0,0x00,0xCC,0xCC,0xCC,0x7E,0x00},
{0x00,0xCC,0x00,0xCC,0xCC,0x7C,0x0C,0xF8},
{0xC3,0x18,0x3C,0x66,0x66,0x3C,0x18,0x00},
{0xCC,0x00,0xCC,0xCC,0xCC,0xCC,0x78,0x00},
{0x18,0x18,0x7E,0xC0,0xC0,0x7E,0x18,0x18},
{0x38,0x6C,0x64,0xF0,0x60,0xE6,0xFC,0x00},
{0xCC,0xCC,0x78,0xFC,0x30,0xFC,0x30,0x30},
{0xF8,0xCC,0xCC,0xFA,0xC6,0xCF,0xC6,0xC7},
{0x0E,0x1B,0x18,0x3C,0x18,0x18,0xD8,0x70},
{0x1C,0x00,0x78,0x0C,0x7C,0xCC,0x7E,0x00},
{0x38,0x00,0x70,0x30,0x30,0x30,0x78,0x00},
{0x00,0x1C,0x00,0x78,0xCC,0xCC,0x78,0x00},
{0x00,0x1C,0x00,0xCC,0xCC,0xCC,0x7E,0x00},
{0x00,0xF8,0x00,0xF8,0xCC,0xCC,0xCC,0x00},
{0xFC,0x00,0xCC,0xEC,0xFC,0xDC,0xCC,0x00},
{0x3C,0x6C,0x6C,0x3E,0x00,0x7E,0x00,0x00},
{0x38,0x6C,0x6C,0x38,0x00,0x7C,0x00,0x00},
{0x30,0x00,0x30,0x60,0xC0,0xCC,0x78,0x00},
{0x00,0x00,0x00,0xFC,0xC0,0xC0,0x00,0x00},
{0x00,0x00,0x00,0xFC,0x0C,0x0C,0x00,0x00},
{0xC3,0xC6,0xCC,0xDE,0x33,0x66,0xCC,0x0F},
{0xC3,0xC6,0xCC,0xDB,0x37,0x6F,0xCF,0x03},
{0x18,0x18,0x00,0x18,0x18,0x18,0x18,0x00},
{0x00,0x33,0x66,0xCC,0x66,0x33,0x00,0x00},
{0x00,0xCC,0x66,0x33,0x66,0xCC,0x00,0x00},
{0x22,0x88,0x22,0x88,0x22,0x88,0x22,0x88},
{0x55,0xAA,0x55,0xAA,0x55,0xAA,0x55,0xAA},
{0xDB,0x77,0xDB,0xEE,0xDB,0x77,0xDB,0xEE},
{0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18},
{0x18,0x18,0x18,0x18,0xF8,0x18,0x18,0x18},
{0x18,0x18,0xF8,0x18,0xF8,0x18,0x18,0x18},
{0x36,0x36,0x36,0x36,0xF6,0x36,0x36,0x36},
{0x00,0x00,0x00,0x00,0xFE,0x36,0x36,0x36},
{0x00,0x00,0xF8,0x18,0xF8,0x18,0x18,0x18},
{0x36,0x36,0xF6,0x06,0xF6,0x36,0x36,0x36},
{0x36,0x36,0x36,0x36,0x36,0x36,0x36,0x36},
{0x00,0x00,0xFE,0x06,0xF6,0x36,0x36,0x36},
{0x36,0x36,0xF6,0x06,0xFE,0x00,0x00,0x00},
{0x36,0x36,0x36,0x36,0xFE,0x00,0x00,0x00},
{0x18,0x18,0xF8,0x18,0xF8,0x00,0x00,0x00},
{0x00,0x00,0x00,0x00,0xF8,0x18,0x18,0x18},
{0x18,0x18,0x18,0x18,0x1F,0x00,0x00,0x00},
{0x18,0x18,0x18,0x18,0xFF,0x00,0x00,0x00},
{0x00,0x00,0x00,0x00,0xFF,0x18,0x18,0x18},
{0x18,0x18,0x18,0x18,0x1F,0x18,0x18,0x18},
{0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0x00},
{0x18,0x18,0x18,0x18,0xFF,0x18,0x18,0x18},
{0x18,0x18,0x1F,0x18,0x1F,0x18,0x18,0x18},
{0x36,0x36,0x36,0x36,0x37,0x36,0x36,0x36},
{0x36,0x36,0x37,0x30,0x3F,0x00,0x00,0x00},
{0x00,0x00,0x3F,0x30,0x37,0x36,0x36,0x36},
{0x36,0x36,0xF7,0x00,0xFF,0x00,0x00,0x00},
{0x00,0x00,0xFF,0x00,0xF7,0x36,0x36,0x36},
{0x36,0x36,0x37,0x30,0x37,0x36,0x36,0x36},
{0x00,0x00,0xFF,0x00,0xFF,0x00,0x00,0x00},
{0x36,0x36,0xF7,0x00,0xF7,0x36,0x36,0x36},
{0x18,0x18,0xFF,0x00,0xFF,0x00,0x00,0x00},
{0x36,0x36,0x36,0x36,0xFF,0x00,0x00,0x00},
{0x00,0x00,0xFF,0x00,0xFF,0x18,0x18,0x18},
{0x00,0x00,0x00,0x00,0xFF,0x36,0x36,0x36},
{0x36,0x36,0x36,0x36,0x3F,0x00,0x00,0x00},
{0x18,0x18,0x1F,0x18,0x1F,0x00,0x00,0x00},
{0x00,0x00,0x1F,0x18,0x1F,0x18,0x18,0x18},
{0x00,0x00,0x00,0x00,0x3F,0x36,0x36,0x36},
{0x36,0x36,0x36,0x36,0xFF,0x36,0x36,0x36},
{0x18,0x18,0xFF,0x18,0xFF,0x18,0x18,0x18},
{0x18,0x18,0x18,0x18,0xF8,0x00,0x00,0x00},
{0x00,0x00,0x00,0x00,0x1F,0x18,0x18,0x18},
{0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF},
{0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF},
{0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0},
{0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F},
{0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00},
{0x00,0x00,0x76,0xDC,0xC8,0xDC,0x76,0x00},
{0x00,0x78,0xCC,0xF8,0xCC,0xF8,0xC0,0xC0},
{0x00,0xFC,0xCC,0xC0,0xC0,0xC0,0xC0,0x00},
{0x00,0xFE,0x6C,0x6C,0x6C,0x6C,0x6C,0x00},
{0xFC,0xCC,0x60,0x30,0x60,0xCC,0xFC,0x00},
{0x00,0x00,0x7E,0xD8,0xD8,0xD8,0x70,0x00},
{0x00,0x66,0x66,0x66,0x66,0x7C,0x60,0xC0},
{0x00,0x76,0xDC,0x18,0x18,0x18,0x18,0x00},
{0xFC,0x30,0x78,0xCC,0xCC,0x78,0x30,0xFC},
{0x38,0x6C,0xC6,0xFE,0xC6,0x6C,0x38,0x00},
{0x38,0x6C,0xC6,0xC6,0x6C,0x6C,0xEE,0x00},
{0x1C,0x30,0x18,0x7C,0xCC,0xCC,0x78,0x00},
{0x00,0x00,0x7E,0xDB,0xDB,0x7E,0x00,0x00},
{0x06,0x0C,0x7E,0xDB,0xDB,0x7E,0x60,0xC0},
{0x38,0x60,0xC0,0xF8,0xC0,0x60,0x38,0x00},
{0x78,0xCC,0xCC,0xCC,0xCC,0xCC,0xCC,0x00},
{0x00,0xFC,0x00,0xFC,0x00,0xFC,0x00,0x00},
{0x30,0x30,0xFC,0x30,0x30,0x00,0xFC,0x00},
{0x60,0x30,0x18,0x30,0x60,0x00,0xFC,0x00},
{0x18,0x30,0x60,0x30,0x18,0x00,0xFC,0x00},
{0x0E,0x1B,0x1B,0x18,0x18,0x18,0x18,0x18},
{0x18,0x18,0x18,0x18,0x18,0xD8,0xD8,0x70},
{0x30,0x30,0x00,0xFC,0x00,0x30,0x30,0x00},
{0x00,0x76,0xDC,0x00,0x76,0xDC,0x00,0x00},
{0x38,0x6C,0x6C,0x38,0x00,0x00,0x00,0x00},
{0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00},
{0x00,0x00,0x00,0x00,0x18,0x00,0x00,0x00},
{0x0F,0x0C,0x0C,0x0C,0xEC,0x6C,0x3C,0x1C},
{0x78,0x6C,0x6C,0x6C,0x6C,0x00,0x00,0x00},
{0x70,0x18,0x30,0x60,0x78,0x00,0x00,0x00},
{0x00,0x00,0x3C,0x3C,0x3C,0x3C,0x00,0x00},
{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}};

const uint8_t kocka[6][8] PROGMEM= {{0x0,0x0,0x0,0x18,0x18,0x0,0x0,0x0},
                   {0x3,0x3,0x0,0x0,0x0,0x0,0xc0,0xc0},
                   {0x3,0x3,0x0,0x18,0x18,0x0,0xc0,0xc0},
                   {0xc3,0xc3,0x0,0x0,0x0,0x0,0xc3,0xc3},
                   {0xc3,0xc3,0x0,0x18,0x18,0x0,0xc3,0xc3},
                   {0xc3,0xc3,0x0,0xc3,0xc3,0x0,0xc3,0xc3}};

#define OP_NOOP   0
#define OP_DIGIT0 1
#define OP_DIGIT1 2
#define OP_DIGIT2 3
#define OP_DIGIT3 4
#define OP_DIGIT4 5
#define OP_DIGIT5 6
#define OP_DIGIT6 7
#define OP_DIGIT7 8
#define OP_DECODEMODE  9
#define OP_INTENSITY   10
#define OP_SCANLIMIT   11
#define OP_SHUTDOWN    12
#define OP_DISPLAYTEST 15
#define BUTTON 8


int CLK=5; // 5 = PD5
int LOAD=6; // 6 = PD6
int DIN=7;  // 7 = PD7
 
byte znak[2][8] = 
{{0xFE,0x62,0x68,0x78,0x68,0x62,0xFE,0x00},
      {0x1C,0x3C,0x6C,0xCC,0xFE,0x0C,0x1E,0x00}};

uint16_t prost(uint16_t n)
{
  uint16_t i;
  if (n < 2) return 0;

  for (i = 2; i < n; i++) if (n % i == 0) return 0;

  return 1;
}

uint16_t naop(uint16_t n)
{
  uint16_t i = 0;

  while (n > 0)
  {
    i = (i * 10) + n % 10;

    n /= 10;
  }

  return i;

}

void sendData( byte address, byte data)
{ 
    byte packet[2];
    byte bitmask;
    byte i;
    packet[0]=address;
    packet[1]=data;
     
    for(i=0;i<2;i++)
    for( bitmask=0x80 ; bitmask!=0 ; bitmask=bitmask>>1 )
    {
       if(bitmask & packet[i]) digitalWrite(DIN,1); 
           else digitalWrite(DIN,0);
       
       digitalWrite(CLK, HIGH);
       digitalWrite(CLK, LOW);        
    }
    digitalWrite(LOAD,HIGH); 
    digitalWrite(LOAD,LOW);
}

void setup() {
  // put your setup code here, to run once:
    pinMode(DIN,OUTPUT);
    pinMode(CLK,OUTPUT);
    pinMode(LOAD,OUTPUT);
    digitalWrite(LOAD,LOW);
    pinMode(BUTTON, INPUT_PULLUP);

     randomSeed(analogRead(0));


   sendData(OP_DISPLAYTEST, 0);
   sendData(OP_INTENSITY, 0);
   sendData(OP_SCANLIMIT, 7);
  
   sendData(OP_DECODEMODE, 0);
   sendData(OP_SHUTDOWN, 1);
   for(int i=0;i<8;i++) sendData(i+1, 0b00000000);

}


void loop() {
  // put your main code here, to run repeatedly:  
  
for(uint16_t i=0;i<65535;i++){
    if (prost(i))
    {
      delay(500);
      uint16_t bn = naop(i);
      while (bn > 0)
      {
        for (byte i = 0; i < 8; i++) sendData(i + 1, pgm_read_byte_near(&FontA[(bn % 10) + '0'][i]));
        bn /= 10;
        delay(300);
        for (byte i = 0; i < 8; i++) sendData(i + 1, 0x00);
        delay(100);
      }
    }

  }
}





