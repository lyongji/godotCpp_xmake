#ifndef GDEXAMPLE_H
#define GDEXAMPLE_H

#include <godot_cpp/classes/sprite2d.hpp>

namespace godot {

// 测试类。继承godot中的Sprite2D
class GDExample : public Sprite2D {
  GDCLASS(GDExample, Sprite2D)

private:
  // 移动速度
  double 速度值;
  // 生命值
  int 生命值;

  double time_passed;
  double time_emit;
  double 振幅;

protected:
  static void _bind_methods();

public:
  GDExample();
  ~GDExample();

  void _process(double delta) override;

  // 设置速度
  void set_speed(const double p_speed);
  // 获取速度
  double get_speed() const;

  void set_振幅(const double p_振幅);
  double get_振幅() const;

  // 设置生命值
  void set_health(const int p_health);
  // 获取生命值
  int get_health() const;

  // 吃饭功能
  void eat(const String &food);
};

} // namespace godot

#endif
