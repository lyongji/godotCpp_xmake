#include "gdexample.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/char_string.hpp>
using namespace godot;

void GDExample::_bind_methods() {
  // 绑定速度属性
  ClassDB::bind_method(D_METHOD("set_speed", "speed"), &GDExample::set_speed);
  ClassDB::bind_method(D_METHOD("get_speed"), &GDExample::get_speed);
  // 添加速度属性到编辑器
  ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "speed"), "set_speed", "get_speed");

  // 绑定生命值属性
  ClassDB::bind_method(D_METHOD("set_health", "health"),
                       &GDExample::set_health);
  ClassDB::bind_method(D_METHOD("get_health"), &GDExample::get_health);
  // 添加生命值属性到编辑器
  ADD_PROPERTY(PropertyInfo(Variant::INT, "health"), "set_health",
               "get_health");

  CharStringT<char16_t> 吃(u"吃");
  // 绑定吃饭方法
  ClassDB::bind_method(D_METHOD(吃.get_data(), "food"), &GDExample::eat);
}

GDExample::GDExample() {

  // 默认速度
  speed = 100.0;
  // 默认生命值
  health = 100;
}

GDExample::~GDExample() {
  // 析构函数
}
// 实现功能
void GDExample::_process(double delta) {

  // 使用速度参数控制移动
  set_position(Vector2(10.0 + (delta * sin(speed * 2.0)),
                       10.0 + (delta * cos(speed * 1.5))));
}

// 设置速度
void GDExample::set_speed(const double p_speed) { speed = p_speed; }

// 获取速度
double GDExample::get_speed() const { return speed; }

// 设置生命值
void GDExample::set_health(const int p_health) { health = p_health; }

// 获取生命值
int GDExample::get_health() const { return health; }

// 吃饭功能实现
void GDExample::eat(const String &food) {
  // 根据食物类型增加生命值
  if (food == "apple") {
    health += 10;
  } else if (food == "meat") {
    health += 20;
  } else {
    health += 5;
  }

  // 生命值上限为100
  health = MIN(health, 100);
}
