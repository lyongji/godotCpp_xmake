#include "gdexample.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/char_string.hpp>
using namespace godot;

void GDExample::_bind_methods() {
  // 绑定速度属性
  ClassDB::bind_method(D_METHOD(u"set_速度", u"速度值"), &GDExample::set_speed);
  ClassDB::bind_method(D_METHOD(u"get_速度"), &GDExample::get_speed);
  // 添加速度属性到编辑器
  ADD_PROPERTY(PropertyInfo(Variant::FLOAT, u"速度值"), u"set_速度",
               u"get_速度");

  // 绑定属性
  ClassDB::bind_method(D_METHOD(u"set_振幅", u"振幅"), &GDExample::set_振幅);
  ClassDB::bind_method(D_METHOD(u"get_振幅"), &GDExample::get_振幅);
  // 添加到编辑器
  ADD_PROPERTY(PropertyInfo(Variant::FLOAT, u"振幅"), u"set_振幅", u"get_振幅");

  // 绑定生命值属性
  ClassDB::bind_method(D_METHOD(u"set_生命值", u"生命值"),
                       &GDExample::set_health);
  ClassDB::bind_method(D_METHOD(u"get_生命值"), &GDExample::get_health);
  // 添加生命值属性到编辑器,绑定方法
  ADD_PROPERTY(PropertyInfo(Variant::INT, u"生命值"), u"set_生命值",
               u"get_生命值");

  // 绑定吃饭方法,测试使用中文
  ClassDB::bind_method(D_METHOD(u"吃", "food"), &GDExample::eat);

  // 添加信号
  ADD_SIGNAL(MethodInfo("position_changed",
                        PropertyInfo(Variant::OBJECT, "node"),
                        PropertyInfo(Variant::VECTOR2, "new_pos")));
}

GDExample::GDExample() {

  // 默认速度
  速度值 = 100.0;
  // 默认生命值
  生命值 = 100;
  // 默认振幅
  振幅 = 100.0;
  time_emit = 0.0;
}

GDExample::~GDExample() {
  // 析构函数
}
// 实现功能
void GDExample::_process(double delta) {
  time_passed += 速度值 * delta;
  // 使用速度参数控制移动
  auto new_pos =
      Vector2((振幅 * sin(time_passed * 2.0)), (振幅 * cos(time_passed * 1.5)));

  set_position(new_pos);

  time_emit += delta;
  if (time_emit > 1.0) {
    emit_signal("position_changed", this, new_pos);

    time_emit = 0.0;
  }
}

// 设置速度
void GDExample::set_speed(const double p_speed) { 速度值 = p_speed; }

// 获取速度
double GDExample::get_speed() const { return 速度值; }

// 设置振幅
void GDExample::set_振幅(const double p_振幅) { 振幅 = p_振幅; }
double GDExample::get_振幅() const { return 振幅; }

// 设置生命值
void GDExample::set_health(const int p_health) { 生命值 = p_health; }

// 获取生命值
int GDExample::get_health() const { return 生命值; }

// 吃饭功能实现
void GDExample::eat(const String &food) {
  // 根据食物类型增加生命值
  if (food == "apple") {
    生命值 += 10;
  } else if (food == "meat") {
    生命值 += 20;
  } else {
    生命值 += 5;
  }

  // 生命值上限为100
  生命值 = MIN(生命值, 100);
}
