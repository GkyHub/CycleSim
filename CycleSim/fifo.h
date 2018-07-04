#pragma once
#include <functional>
#include "clock.h"
#include "interface.h"

namespace hdl
{
    /*
        class for a synchronous fifo
    */
    template<class T, unsigned int L>
	class SyncFifo {
	public:
		// I/O
		IN(bool)	wr_en;
		IN(T)		wr_data;
		OUT(bool)	full;

		IN(bool)	rd_en;
		OUT(T)		rd_data;
		OUT(bool)	empty;

	private:
		// local status
		T		_mem[L];
		int		_wrAddr;
		int		_rdAddr;

		ClkElement *_pFifoBehav;

	private:
		void _onClkEdge() {
			// write logic
			if (!*full && *wr_en) {
				_mem[_wrAddr] = *wr_data;
				_wrAddr = (_wrAddr + 1) % L;
			}
			// read logic
			if (!*empty && *rd_en) {
				_rdAddr = (_rdAddr + 1) % L;
			}
		};

		void _postClkEdge() {
			*full = ((_wrAddr + 1) % L) == _rdAddr;
			*empty = _wrAddr == _rdAddr;
			*rd_data = _mem[_rdAddr];
		}

	public:
		SyncFifo(ClockDomain cd) {
			_pFifoBehav = new ClkElement(cd, _onClkEdge, _postClkEdge);
		};		

		~SyncFifo() {
			delete _pFifoBehav;
		}
	};
}