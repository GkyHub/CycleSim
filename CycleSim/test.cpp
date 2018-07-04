#include "fifo.h"
#include "clock.h"

int main()
{
	hdl::ClockDomain clk(10);
	hdl::SyncFifo<int, 16> fifo(clk);

	bool wr_en, rd_en;
	int wr_data;

	fifo.wr_en = &wr_en;
	fifo.rd_en = &rd_en;
	fifo.wr_data = &wr_data;

	return 0;
}