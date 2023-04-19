#ifndef IMGUIINEGL_H
#define IMGUIINEGL_H
#include <jni.h>
#include <sched.h>
#include <unistd.h>
#include <time.h>
#include <thread>
#include <random>
#include <linux/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <fstream>
#include <sys/mman.h>
#include <sys/syscall.h>
#include <linux/input.h>
#include <linux/uinput.h>
#include <unordered_map>
#include <EGL/egl.h>
#include <GLES2/gl2.h>
#include <thread>
#include <array>
#include <android/native_window_jni.h>

using namespace std;

struct Vec2 {
    float x;
    float y;
    Vec2() {
        this->x = 0;
        this->y = 0;
    }
    Vec2(float x, float y) {
        this->x = x;
        this->y = y;
    }
    Vec2 operator+(float v) const {
        return Vec2(x + v, y + v);
    }
    Vec2 operator-(float v) const {
        return Vec2(x - v, y - v);
    }
    Vec2 operator*(float v) const {
        return Vec2(x * v, y * v);
    }
    Vec2 operator/(float v) const {
        return Vec2(x / v, y / v);
    }
    Vec2& operator+=(float v) {
        x += v; y += v; return *this;
    }
    Vec2& operator-=(float v) {
        x -= v; y -= v; return *this;
    }
    Vec2& operator*=(float v) {
        x *= v; y *= v; return *this;
    }
    Vec2& operator/=(float v) {
        x /= v; y /= v; return *this;
    }
    Vec2 operator+(const Vec2& v) const {
        return Vec2(x + v.x, y + v.y);
    }
    Vec2 operator-(const Vec2& v) const {
        return Vec2(x - v.x, y - v.y);
    }
    Vec2 operator*(const Vec2& v) const {
        return Vec2(x * v.x, y * v.y);
    }
    Vec2 operator/(const Vec2& v) const {
        return Vec2(x / v.x, y / v.y);
    }
    Vec2& operator+=(const Vec2& v) {
        x += v.x; y += v.y; return *this;
    }
    Vec2& operator-=(const Vec2& v) {
        x -= v.x; y -= v.y; return *this;
    }
    Vec2& operator*=(const Vec2& v) {
        x *= v.x; y *= v.y; return *this;
    }
    Vec2& operator/=(const Vec2& v) {
        x /= v.x; y /= v.y; return *this;
	}
};

struct Vec3 {
    float x;
    float y;
    float z;
    Vec3() {
        this->x = 0;
        this->y = 0;
        this->z = 0;
    }
    Vec3(float x, float y, float z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }
    Vec3 operator+(float v) const {
        return Vec3(x + v, y + v, z + v);
    }
    Vec3 operator-(float v) const {
        return Vec3(x - v, y - v, z - v);
    }
    Vec3 operator*(float v) const {
        return Vec3(x * v, y * v, z * v);
    }
    Vec3 operator/(float v) const {
        return Vec3(x / v, y / v, z / v);
    }
    Vec3& operator+=(float v) {
        x += v; y += v; z += v; return *this;
    }
    Vec3& operator-=(float v) {
        x -= v; y -= v; z -= v; return *this;
    }
    Vec3& operator*=(float v) {
        x *= v; y *= v; z *= v; return *this;
    }
    Vec3& operator/=(float v) {
        x /= v; y /= v; z /= v; return *this;
	}
    Vec3 operator+(const Vec3& v) const {
        return Vec3(x + v.x, y + v.y, z + v.z);
    }
    Vec3 operator-(const Vec3& v) const {
        return Vec3(x - v.x, y - v.y, z - v.z);
    }
    Vec3 operator*(const Vec3& v) const {
        return Vec3(x * v.x, y * v.y, z * v.z);
    }
    Vec3 operator/(const Vec3& v) const {
        return Vec3(x / v.x, y / v.y, z / v.z);
    }
    Vec3& operator+=(const Vec3& v) {
        x += v.x; y += v.y; z += v.z; return *this;
    }
    Vec3& operator-=(const Vec3& v) {
        x -= v.x; y -= v.y; z -= v.z; return *this;
    }
    Vec3& operator*=(const Vec3& v) {
        x *= v.x; y *= v.y; z *= v.z; return *this;
    }
    Vec3& operator/=(const Vec3& v) {
        x /= v.x; y /= v.y; z /= v.z; return *this;
	}
};

struct Vec4 {
    float x;
    float y;
    float z;
    float w;
    Vec4() {
        this->x = 0;
        this->y = 0;
        this->z = 0;
        this->w = 0;
    }
    Vec4(float x, float y, float z, float w) {
        this->x = x;
        this->y = y;
        this->z = z;
        this->w = w;
    }
};

struct Rotator {
    float Pitch;
    float Yaw;
    float Roll;
    Rotator(){}
    Rotator(float _P, float _Y, float _R) : Pitch(_P), Yaw(_Y), Roll(_R) {}
};

struct SwitchData {
	int IntIo[500] = {0};
    float TouchXY[2] = {0};
	bool BoolIo[500] = {0};
	float FloatIo[500] = {0};
};

#endif
