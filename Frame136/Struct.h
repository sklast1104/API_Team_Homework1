#pragma once

typedef struct tagInfo
{
	float		fX;
	float		fY;
	float		fCX;
	float		fCY;

}INFO;

struct Vec2 {

public:
	float x;
	float y;

public:
	Vec2() : x(0.f), y(0.f) {}

	Vec2(int _x, int _y) : x((float)_x), y((float)_y) {}

	Vec2(LONG _x, LONG _y) : x((float)_x), y((float)_y) {}

	Vec2(float _x, float _y) : x(_x), y(_y) {}

	Vec2(const POINT _pt) : x((float)_pt.x), y((float)_pt.y) {}

	Vec2 operator - ()
	{
		return Vec2(-x, -y);
	}

	Vec2& operator = (POINT _pt) {
		x = (float)_pt.x;
		y = (float)_pt.y;

		return *this;
	}

	Vec2 operator + (Vec2 _vOther) {
		return Vec2(x + _vOther.x, y + _vOther.y);
	}

	void operator += (Vec2 _vOther) {
		x += _vOther.x;
		y += _vOther.y;
	}

	Vec2 operator - (Vec2 _vOther) {
		return Vec2(x - _vOther.x, y - _vOther.y);
	}

	void operator -= (Vec2 _vOther) {
		x += _vOther.x;
		y += _vOther.y;
	}

	void operator - (float _f) {

		x += _f;
		y += _f;
	}

	Vec2 operator * (Vec2 _vOther) {
		return Vec2(x * _vOther.x, y * _vOther.y);
	}

	Vec2 operator * (int _i)
	{
		return Vec2(x * (float)_i, y * (float)_i);
	}

	Vec2 operator * (float _f) {
		return Vec2(x * _f, y * _f);
	}

	void operator *= (float _f) {
		x *= _f;
		y *= _f;
	}

	Vec2 operator / (Vec2 _vOther) {

		assert(!(0.f == _vOther.x || 0.f == _vOther.y));
		return Vec2(x / _vOther.x, y / _vOther.y);
	}

	Vec2 operator / (float _f) {

		assert(!(0.f == _f));
		return Vec2(x / _f, y / _f);
	}

	bool IsZero() {
		if (x == 0.f && y == 0.f)
			return true;
		return false;
	}

	float Length() {
		return sqrt(x * x + y * y);
	}

	Vec2& Normalize() {

		float fLen = Length();

		assert(fLen != 0.f);

		x /= fLen;
		y /= fLen;
		return *this;
	}

	static float Dot(Vec2 v1, Vec2 v2) {

		return v1.x * v2.x + v1.y * v2.y;
	}
};