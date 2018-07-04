#include "fifo.h"
#include "clock.h"

int main()
{
	hdl::ClockDomain clk(10);
	hdl::SyncFifo<int, 16> fifo(clk);

	return 0;
}