#ifndef KERN_CMOS_H
#define KERN_CMOS_H

#include <core/os.h>

#define BCD_TO_BIN(num) ((num) = ((num) & 15) + ((num) >> 4) * 10)

#define CMOS_ADDR 0x70
#define CMOS_DATA 0x71

#define CMOS_SECONDS	0x00
#define CMOS_MINUTES	0x02
#define CMOS_HOURS	0x04
#define CMOS_WEEKDAY	0x06
#define CMOS_DAYOFMONTH 0x07
#define CMOS_MONTH	0x08
#define CMOS_YEAR	0x09
#define CMOS_CENTURY	0x32
#define CMOS_REG_A	0x0A
#define CMOS_REG_B	0x0B

struct cmos_t {
	u32 seconds;
	u32 minutes;
	u32 hours;
	u32 weekday;
	u32 dayofmonth;
	u32 month;
	u32 year;
	u32 century;
	u32 reg_a;
	u32 reg_b;
};

struct cmos_t ktime_s;

u32 cmos_read(u32 addr);
void init_cmos(void);

#endif /* KERN_CMOS_H */

