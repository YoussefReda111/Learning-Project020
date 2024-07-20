#pragma once
#include "cls_stack.h"

template <class class_type> class cls_undo_redo
{
private:
	int _current_index = 0;

protected:
	cls_stack <class_type> stack;

public:
	cls_undo_redo()
	{
		stack.push(class_type());
	}

	void set_value(class_type value)
	{
		stack.push(value);
	}

	class_type get_value()
	{
		return stack.at(_current_index);
	}

	__declspec(property(put = set_value, get = get_value)) class_type value;

	void undo()
	{
		if (_current_index < stack.size() - 1) _current_index++;
	}

	void redo()
	{
		if (_current_index > 0) _current_index--;
	}
};