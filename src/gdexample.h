#ifndef GDEXAMPLE_H
#define GDEXAMPLE_H

#include <godot_cpp/classes/sprite2d.hpp>

namespace godot {

//测试类。继承godot中的Sprite2D
class GDExample : public Sprite2D {
	GDCLASS(GDExample, Sprite2D)

private:
    //测试用变量
	double time_passed;

protected:
	static void _bind_methods();

public:
	GDExample();
	~GDExample();
    
	void _process(double delta) override;
};

}

#endif