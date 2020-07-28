#pragma once

template<typename T>
void Safe_Delete(T& rObj)
{
	if (rObj)
	{
		delete rObj;
		rObj = nullptr;
	}
}

// 최소값 ~ 최대값
template <class T>
T Clamp(const T& _min, T& _val, const T& _max)
{
	return max(_min, min(_val, _max));
}

// 최소값 <-> 최대값 
template <class T>
T Wrap(const T& _min, T& _val, const T& _max)
{
	int n = (_val - _min) % (_max - _min);
	return (n >= 0) ? (n + _min) : (n + _max);
}