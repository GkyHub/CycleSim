/*
    This file defines the hardware elements work in time sequential
    mode
*/
#pragma once
#include <vector>
#include <functional>
#include <cassert>

namespace hdl
{
    class ClkElement;

    class ClockDomain {
    private:
        float _period;
        float _offset;
        float _duty;
        std::vector<ClkElement*> _elements;

    public:

		ClockDomain(float period, float offset = 0, float duty = 0.5);

        // get methods
		float getPeriod();
		float getOffset();
		float getDuty();

		// manage all the elements
		int AddElement(ClkElement *ele);
		void RemoveElement(int id);

		// for simulation
		void onClkEdge();
		void postClkEdge();
    };

    class ClkElement {
	private:
		int _id;
		ClockDomain *_cd;		

    public:
		// update all the intermediate status
		std::function<void()> _onClkEdge;
		// update output
		std::function<void()> _postClkEdge;

		ClkElement(ClockDomain *clk, std::function<void()> onClkEdge, std::function<void()> postClkEdge);

		~ClkElement();
		
    };

}