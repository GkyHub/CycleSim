#pragma once
#include <vector>
#include "clock.h"

namespace hdl {
	class Simulator {
	protected:
		std::vector<ClockDomain *> _clocks;
		double _time;
		std::vector<double> _nxtEvent;

	public:
		Simulator() {};
		~Simulator() {};

		void AddClockDomain(ClockDomain *cd)
		{
			_clocks.push_back(cd);
			_nxtEvent.push_back(0.0);
		}

		void Reset()
		{
			_time = 0.0;
			for (int i = 0; i < _clocks.size(); i++) {
				_nxtEvent[i] = _clocks[i]->getPeriod();
			}
			return;
		}

		void Run(double t)
		{
			int nxtId;

			while (_time < t) {
				nxtId = nextEvent(_time);
				_clocks[nxtId]->onClkEdge();
				_clocks[nxtId]->postClkEdge();
				_nxtEvent[nxtId] += _clocks[nxtId]->getPeriod();
			}

			return;
		}

	private:
		int nextEvent(double &nxt)
		{
			nxt = _nxtEvent[0];
			int nxtId = 0;
			for (int i = 1; i < _nxtEvent.size(); i++) {
				if (_nxtEvent[i] < nxt) {
					nxt = _nxtEvent[i];
					nxtId = i;
				}
			}
			return nxtId;
		}
	};
}