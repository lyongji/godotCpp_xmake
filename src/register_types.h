#ifndef GDEXAMPLE_REGISTER_TYPES_H
#define GDEXAMPLE_REGISTER_TYPES_H

#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void initialize_example_module(ModuleInitializationLevel p_level);//注册 initialize_你自己的类型_module
void uninitialize_example_module(ModuleInitializationLevel p_level);//卸载

#endif // GDEXAMPLE_REGISTER_TYPES_H
