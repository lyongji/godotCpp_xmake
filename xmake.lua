add_rules("mode.debug", "mode.release")

set_languages("c++20")--设置语言标准

set_encodings("utf-8")--设置源文件编码和可执行文件输出编码 

set_version("0.0.1")-- 设置工程版本

--拉取依赖包
add_requires("godotcpp4 4.3") 



target("godotCpp")
    set_kind("shared")--动态库类型
    add_files("src/*.cpp")
    add_includedirs("src/")
    add_packages('godotcpp4')--添加依赖包到项目
    set_basename("lib个人库.$(os).$(mode).$(arch)")--设置生成的库名，
    --lib你的库名.$(os) 当前编译平台的操作系统 $(mode) 当前构建模式 $(arch) 当前系统架构
    
    after_build(function (target )--脚本运行,将构建后的dll文件复制到bin文件夹中
        print(target:targetfile())--构建目标位置
        os.cp(target:targetfile(), "demo/bin")--复制目标到demo/bin文件夹中
        print('$(os)')--当前编译平台
        --‘xmake f -h’ 查看所有内置变量
    end) 


--
-- If you want to known more usage about xmake, please see https://xmake.io
--
-- ## FAQ
--
-- You can enter the project directory firstly before building project.
--
--   $ cd projectdir
--
-- 1. How to build project?
--
--   $ xmake
--
-- 2. How to configure project?
--
--   $ xmake f -p [macosx|linux|iphoneos ..] -a [x86_64|i386|arm64 ..] -m [debug|release]
--
-- 3. Where is the build output directory?
--
--   The default output directory is `./build` and you can configure the output directory.
--
--   $ xmake f -o outputdir
--   $ xmake
--
-- 4. How to run and debug target after building project?
--
--   $ xmake run [targetname]
--   $ xmake run -d [targetname]
--
-- 5. How to install target to the system directory or other output directory?
--
--   $ xmake install
--   $ xmake install -o installdir
--
-- 6. Add some frequently-used compilation flags in xmake.lua
--
-- @code
--    -- add debug and release modes
--    add_rules("mode.debug", "mode.release")
--
--    -- add macro definition
--    add_defines("NDEBUG", "_GNU_SOURCE=1")
--
--    -- set warning all as error
--    set_warnings("all", "error")
--
--    -- set language: c99, c++11
--    set_languages("c99", "c++11")
--
--    -- set optimization: none, faster, fastest, smallest
--    set_optimize("fastest")
--
--    -- add include search directories
--    add_includedirs("/usr/include", "/usr/local/include")
--
--    -- add link libraries and search directories
--    add_links("tbox")
--    add_linkdirs("/usr/local/lib", "/usr/lib")
--
--    -- add system link libraries
--    add_syslinks("z", "pthread")
--
--    -- add compilation and link flags
--    add_cxflags("-stdnolib", "-fno-strict-aliasing")
--    add_ldflags("-L/usr/local/lib", "-lpthread", {force = true})
--
-- @endcode
--

