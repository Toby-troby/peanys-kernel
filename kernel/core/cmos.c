#include <core/cmos.h>

u32 cmos_read(u32 addr)
{
	outb(CMOS_ADDR, addr);
	return inb(CMOS_DATA);
}

void init_cmos(void)
{
	do{
		ktime_s.seconds = cmos_read(CMOS_SECONDS);
		ktime_s.minutes = cmos_read(CMOS_MINUTES);
		ktime_s.hours = cmos_read(CMOS_HOURS);
		ktime_s.weekday = cmos_read(CMOS_WEEKDAY);
		ktime_s.dayofmonth = cmos_read(CMOS_DAYOFMONTH);
		ktime_s.month = cmos_read(CMOS_MONTH);
		ktime_s.year = cmos_read(CMOS_YEAR);
		ktime_s.century = cmos_read(CMOS_CENTURY);
		ktime_s.reg_a = cmos_read(CMOS_REG_A);
		ktime_s.reg_b = cmos_read(CMOS_REG_B);
	} while(ktime_s.seconds != cmos_read(CMOS_SECONDS));

	BCD_TO_BIN(ktime_s.seconds);
	BCD_TO_BIN(ktime_s.minutes);
	BCD_TO_BIN(ktime_s.hours);
	BCD_TO_BIN(ktime_s.weekday);
	BCD_TO_BIN(ktime_s.dayofmonth);
	BCD_TO_BIN(ktime_s.month);
	BCD_TO_BIN(ktime_s.year);
	BCD_TO_BIN(ktime_s.century);
}

