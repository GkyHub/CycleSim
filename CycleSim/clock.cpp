#include "clock.h"
using namespace hdl;

ClockDomain::ClockDomain(float period, float offset, float duty)
{
	assert(period > 0);
	_period = period;
	_offset = offset;
	assert(duty < 1 && duty > 0);
	_duty = duty;
}

// get methods
float ClockDomain::getPeriod() { return _period; }
float ClockDomain::getOffset() { return _offset; }
float ClockDomain::getDuty() { return _duty; }

int ClockDomain::AddElement(ClkElement *ele)
{
	_elements.push_back(ele);
	return _elements.size() - 1;
}

void ClockDomain::RemoveElement(int id)
{
	_elements[id] = nullptr;
	return;
}

void ClockDomain::onClkEdge()
{
	for each(ClkElement *e in _elements) {
		if (e != nullptr) {
			e->_onClkEdge();
		}
	}
	return;
}

void ClockDomain::postClkEdge()
{
	for each(ClkElement *e in _elements) {
		if (e != nullptr) {
			e->_postClkEdge();
		}
	}
	return;
}

ClkElement::ClkElement(ClockDomain *clk, std::function<void()> onClkEdge, std::function<void()> postClkEdge)
{
	_id = clk->AddElement(this);
	_cd = clk;
	_onClkEdge = onClkEdge;
	_postClkEdge = postClkEdge;
}

ClkElement::~ClkElement()
{
	_cd->RemoveElement(_id);
}