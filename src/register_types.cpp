#include "register_types.h"
// 导入你自己的类型模型
#include "gdexample.h"

#include <gdextension_interface.h>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>

using namespace godot;

void initialize_example_module(ModuleInitializationLevel p_level) {
  if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
    return;
  }

  GDREGISTER_CLASS(GDExample); // 注册你自己的类型模型
}

void uninitialize_example_module(ModuleInitializationLevel p_level) {
  if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
    return;
  }
}

extern "C" {
// 初始化. 你自己的类型_library_init,和gdexample.gdextension中的entry_symbol =
// "example_library_init"名称相同
GDExtensionBool GDE_EXPORT
example_library_init(GDExtensionInterfaceGetProcAddress p_get_proc_address,
                     const GDExtensionClassLibraryPtr p_library,
                     GDExtensionInitialization *r_initialization) {
  godot::GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library,
                                                 r_initialization);

  init_obj.register_initializer(
      initialize_example_module); // 注册 initialize_example_module
  init_obj.register_terminator(
      uninitialize_example_module); // 卸载 initialize_example_module
  init_obj.set_minimum_library_initialization_level(
      MODULE_INITIALIZATION_LEVEL_SCENE); // 设置库初始化级别

  return init_obj.init();
}
}